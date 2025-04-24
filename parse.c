/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 05:35:11 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/24 16:49:06 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Your program(s) must take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat] */

void	parse(int ac, char **av, t_rules *rules)
{
	int		i;
	int		j;
	char	**split;
	int		k;
	int		*arr;
	
	i = 1;
	k = 0;
	null_check(av);
	arr = malloc(ac * sizeof(int));
	if (!arr)
		return ;
	while (av[i] && is_num(av[i]))
	{
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j])
			arr[k++] = ft_atoi(split[j++]);//tüm kuralları sırasıyla arr'e atıyoruz zaten hepsi int 
		free_split(split);
		i++;
	}
	assign_rules(arr, *rules);
	free(arr);
}

static void	null_check(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
		{
			ft_error();
		}
		i++;
	}
}

static void	assign_rules(int *arr, t_rules *rules) // buraya gelene kadar zaten kontrol edicek.
{
	rules->number_of_philosophers = arr[0];
	rules->time_to_die = arr[1];
	rules->time_to_eat = arr[2];
	rules->time_to_sleep = arr[3];
	if (arr[4])
		rules->eat_counter = arr[4];
}
