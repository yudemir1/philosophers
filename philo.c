/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 05:42:51 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/25 13:46:43 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_rules *rules;
	
	if (ac >= 2)
	{
		rules = NULL;
		parse(ac, av, &rules);
		print_arguments(rules);
	}
	else 
	{
		printf("Error\n");
		return (1);
	}
	free(rules);
	return (0);
}
