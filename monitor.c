/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:06:48 by yudemir           #+#    #+#             */
/*   Updated: 2025/06/01 17:30:24 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->rules.number_of_philosophers)
		{
			pthread_mutex_lock(data->philos[i].last_meal_lock);
			if (get_time() - data->philos[i].last_meal > data->rules.time_to_die)
			{
				pthread_mutex_lock(&data->isdead_lock);
				data->dead = 1;
				pthread_mutex_unlock(&data->isdead_lock);
				print_status(&data->philos[i], "died");
				pthread_mutex_unlock(data->philos[i].last_meal_lock);
				return (NULL);
			}
			pthread_mutex_unlock(data->philos[i].last_meal_lock);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

long	get_time()
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}
