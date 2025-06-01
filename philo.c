/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:41:08 by yudemir           #+#    #+#             */
/*   Updated: 2025/05/19 21:50:41 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_data	data;
	
	if (ac == 5 || ac == 6)
	{
		if (arg_check(av) || init(&data, av))
			return (1);
		else
		{
			print_rules(&data.rules);
			free(data.philos);
			// destroy_forks(&data); destroy forks fonksiyonu yazılıcak.
			free(data.forks);
		}
	}
	else
		return (print_error("Error: Invalid number of arguments"), 1);
	return (0);
}
