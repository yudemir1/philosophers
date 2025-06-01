/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:59:55 by yudemir           #+#    #+#             */
/*   Updated: 2025/06/01 17:29:03 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/* Your program(s) must take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]*/
static int	init_rules(t_rules *rules, char **av)
{
	rules->number_of_philosophers = ft_atol((const char *)av[1]);
	rules->time_to_die = ft_atol((const char *)av[2]);
	rules->time_to_eat = ft_atol((const char *)av[3]);
	rules->time_to_sleep = ft_atol((const char *)av[4]);
	rules->meals_needed = -1;
	if (av[5])
		rules->meals_needed = ft_atol((const char *)av[5]);
	return (0);
}

static int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * (data->rules.number_of_philosophers));
	if (!data->philos)
		return (1);
	while (i < data->rules.number_of_philosophers)
	{
		data->philos[i].id = i + 1;// id assign ediyoruz.
		data->philos[i].rules = &data->rules;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->rules.number_of_philosophers];
		data->philos[i].data = data;
		pthread_mutex_init(data->philos[i].last_meal_lock, NULL);
		pthread_mutex_init(data->philos[i].meal_lock, NULL);
		if (pthread_create(&data->philos[i].philo, NULL, activity, &data->philos[i]))
			return (print_error("Error: Initializing philos."));
		i++;
	}
	data->dead = 0;
	data->start_time = get_time();
	return (0);
}

static int join_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rules.number_of_philosophers)
	{
		pthread_join(data->philos[i].philo, NULL);
		i++;
	}
	pthread_join(*data->monitor_t, NULL);
	return (0);
}

static int	init_forks(t_data *data)
{
	int	i;
	int	n;

	i = 0;
	n = data->rules.number_of_philosophers;
	data->forks = malloc(sizeof(pthread_mutex_t) * n);
	if (!data->forks)
		return (1);
	while (i < n)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	init(t_data *data, char **av)
{
	if (pthread_mutex_init(&data->print_lock, NULL) != 0 
			|| pthread_mutex_init(&data->isdead_lock, NULL) != 0)
		return (print_error("Error: While initializing mutexes."));
	data->monitor_t = malloc(sizeof(pthread_t));
	if (!data->monitor_t)
		return (print_error("Error: While initializing monitor thread."));
	if (pthread_create(data->monitor_t, NULL, *start_monitor, data) != 0)
		return (print_error("Error: While initializing monitor thread."));
	if (init_rules(&data->rules, av) != 0)
		return (print_error("Error: While initialiazing rules."));
	if (init_forks(data) != 0)
		return (print_error("Error: While initializing forks."));
	if (init_philos(data) != 0)
		return (print_error("Error: While initialiazing philos."));
	if (join_philos(data) != 0)
		return (print_error("Error: While thread join."));
	return (0);
}
