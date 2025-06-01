/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:41:11 by yudemir           #+#    #+#             */
/*   Updated: 2025/06/01 17:25:29 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
/* Your program(s) must take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]*/
typedef	struct s_rules
{
	long	number_of_philosophers;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meals_needed;
}	t_rules;

typedef struct s_philo
{
	int				id;
	pthread_t		philo;
	long			last_meal;
	int				meals_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t *last_meal_lock;
	pthread_mutex_t *meal_lock;
	t_rules			*rules;
	struct s_data			*data;
}	t_philo;

typedef	struct s_data
{
	t_rules 		rules;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_t		*monitor_t;
	pthread_mutex_t print_lock;
	pthread_mutex_t meal_lock;
	pthread_mutex_t isdead_lock;
	int				dead;
	long			start_time;
}	t_data;

int		print_error(const char *err_msg);
int		init(t_data *data, char **av);
int		arg_check(char **av);
long	ft_atol(const char *str);
void	print_rules(t_rules *rules);
void	*thread_test(void *arg);
long	get_time(void);
void	*activity(void *arg);
void	*start_monitor(void *arg);
void	print_status(t_philo *philo, const char *status);

#endif