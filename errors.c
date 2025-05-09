/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 02:46:15 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/25 03:40:49 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_max_int_error(int *arr, char **split)
{
	free_split(split);
	free(arr);
	printf("Error occured while parsing arguments.\n");
	exit(1);
}

void	ft_error()
{
	printf("Error\n");
	exit(1);
}

