/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:15:49 by yudemir           #+#    #+#             */
/*   Updated: 2025/06/01 17:28:01 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, const char *status)
{
	pthread_mutex_lock(&philo->data->print_lock);
	if (philo->data->dead != 1)
		printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id, status);
	pthread_mutex_unlock(&philo->data->print_lock);
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_unlock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_unlock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
}

void	eat(t_philo *philo)
{
	print_status(philo, "is eating");
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(philo->last_meal_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(philo->last_meal_lock);
	usleep(philo->data->rules.time_to_eat * 1000);
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->meal_lock);
}

void	sleep_and_think(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->data->rules.time_to_sleep * 1000);
	print_status(philo, "is thinking");
}

void	*activity(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		take_forks(philo);
		pthread_mutex_lock(&philo->data->isdead_lock);
		if (philo->data->dead)
			return (pthread_mutex_unlock(&philo->data->isdead_lock), NULL);
		pthread_mutex_unlock(&philo->data->isdead_lock);
		eat(philo);
		pthread_mutex_lock(&philo->data->isdead_lock);
		if (philo->data->dead)
			return (pthread_mutex_unlock(&philo->data->isdead_lock), NULL);
		pthread_mutex_unlock(&philo->data->isdead_lock);
		sleep_and_think(philo);
		pthread_mutex_lock(&philo->data->isdead_lock);
		if (philo->data->dead)
			return (pthread_mutex_unlock(&philo->data->isdead_lock), NULL);
		pthread_mutex_unlock(&philo->data->isdead_lock);
	}
	return (NULL);
}
