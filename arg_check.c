/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:30:17 by yudemir           #+#    #+#             */
/*   Updated: 2025/05/18 16:50:08 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_num(char **av)
{
	int	i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	arg_check(char **av)
{
	int	i;

	i = 0;
	if (is_num(av) == 1)
		return (print_error("Error: Wrong argument type."));
	while (++i <= 4)
	{
		if (ft_atol((const char *)av[i]) < 0)
			return (print_error("Error: Wrong argument types."));
	}
	return (0);
}
