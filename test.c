/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:50:37 by yudemir           #+#    #+#             */
/*   Updated: 2025/05/19 21:56:43 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_rules(t_rules *rules)
{
	printf("%ld\n%ld\n%ld\n%ld\n", rules->number_of_philosophers, rules->time_to_die, rules->time_to_eat, rules->time_to_sleep);
	if (rules->meals_needed)
		printf("%ld", rules->meals_needed);
}

void	*thread_test(void *arg)
{
    t_philo	*local_philo;

    local_philo = (t_philo *)arg; // arg'ı int * olarak cast edip değerini alıyoruz
    printf("bebek pembesi ayak - Thread ID: %lu, Philosopher ID: %d\n", pthread_self(), local_philo->id);
    return (NULL);
}
