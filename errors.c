/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 02:46:15 by yudemir           #+#    #+#             */
/*   Updated: 2025/05/02 01:59:47 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_max_int_error(int *arr, char **split)
{
	free_split(split);
	free(arr);
	printf("Error occured while parsing arguments.\n");
}

void	ft_error_arr(int *arr)
{
	free(arr);
	printf("Error\n");
}

void	ft_error()
{
	printf("Error\n");
}

void	ft_custom_error(char *str)
{
	printf("%s\n", str);
}

