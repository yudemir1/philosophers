#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

// Zaman ölçüm fonksiyonu (milisaniye cinsinden)
double get_current_time_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0);
}

// Global değişkenler
int counter = 0;
bool running = true;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
double start_time;

// Thread fonksiyonu
void* thread_function(void* arg) {
    int thread_id = *(int*)arg;
    
    while(running) {
        // Mutex kilitleme
        pthread_mutex_lock(&mutex);
        double current_time = get_current_time_ms() - start_time;
        
        // Kritik bölge işlemleri
        printf("Thread %d: Counter değeri: %d (%.2f ms)\n", 
               thread_id, counter, current_time);
        
        counter++;
        
        if(counter >= 500) {
            running = false;
        }
        
        printf("Thread %d: Counter'ı artırdım, yeni değer: %d (%.2f ms)\n", 
               thread_id, counter, get_current_time_ms() - start_time);
        
        // Mutex kilidini açma
        pthread_mutex_unlock(&mutex);
        
        // Rastgele bekleme süresi (100-300ms arası)
    }
    
    return NULL;
}

void* thread_function_wo_mtuex(void* arg) {
    int thread_id = *(int*)arg;
    
    while(running) {
        double current_time = get_current_time_ms() - start_time;
        
        printf("Thread %d: Counter değeri: %d (%.2f ms)\n", 
               thread_id, counter, current_time);
        
        counter++;
        
        if(counter >= 500) {
            running = false;
        }
        
        printf("Thread %d: Counter'ı artırdım, yeni değer: %d (%.2f ms)\n", 
               thread_id, counter, get_current_time_ms() - start_time);
        
    }
    
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;
    int id1 = 1, id2 = 2, id3 = 3;
    
    // Zamanı başlat
    start_time = get_current_time_ms();
    printf("Main: Program başladı (0.00 ms)\n");
    
    // 3 thread oluştur
    pthread_create(&thread1, NULL, thread_function, &id1);
    pthread_create(&thread2, NULL, thread_function, &id2);
    
    // Thread'lerin bitmesini bekle
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    printf("Main: Tüm thread'ler tamamlandı. Son counter=%d (%.2f ms)\n", 
           counter, get_current_time_ms() - start_time);
    
    // Mutex'i temizle
    pthread_mutex_destroy(&mutex);
    
    return 0;
}