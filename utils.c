/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:17:11 by yudemir           #+#    #+#             */
/*   Updated: 2025/05/18 16:49:03 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

// 9223372036854775807 max long (19 rakam var)
long	ft_atol(const char *str)
{
	long long	retval;
	int		i;
	int		sign;

	i = 0;
	retval = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		retval *= 10;
		retval += str[i] - 48;
		i++;
	}
	if (ft_strlen(str) > 19 || retval > 9223372036854775807)
		return (-1);
	return (retval * sign);
}

long	get_timestamp(void)
{
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
