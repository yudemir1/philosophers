/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 02:31:18 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/25 03:31:49 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_arguments(t_rules *rules)
{
	printf("%d\n%d\n%d\n%d\n%d\n", rules->number_of_philosophers, rules->time_to_die, rules->time_to_eat, rules->time_to_sleep, rules->eat_counter);
}