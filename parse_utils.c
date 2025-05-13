/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 05:54:29 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/25 03:40:19 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (!(str[i + 1]) || (str[i + 1] < '0' || str[i + 1] > '9')
				|| (i > 0 && (str[i - 1] != ' ')))
				return (ft_error(), 1);
		}
		else if (str[i] != ' ' && (str[i] < '0' || str[i] > '9'))
			return (ft_error(), 1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str, int *arr, char **split)
{		//00000000000000000000000000042 düzeldi ama -000000000000000000000000000042 hatalı.
	long long	res;
	int			negative;
	char		*str2;
	int			i;

	negative = 1;
	res = 0;
	i = 0;
	str2 = ft_trim_num(str);
	if (!str2)
		ft_max_int_error(arr, split);
	if (ft_strlen(&(*str2)) > 13)
		ft_max_int_error(arr ,split);
	while (str2[i] && (str2[i] == ' ' || (str2[i] >= 9 && str2[i] <= 13)))
		i++;
	if (str2[i] == '-')
		negative = -1;
	if (str2[i] == '-' || str2[i] == '+')
		i++;;
	while (str2[i] && str2[i] >= '0' && str2[i] <= '9')
	{
		res = res * 10 + (str2[i] - 48);
		i++;
	}
	if (res * negative > 2147483647 || res * negative < -2147483648)
		ft_max_int_error(arr, split);
	free(str2);
	return (res * negative);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	*ft_trim_num(const char *str)//sayıların önündeki 0'ları silecek. *YAPILACAK: -000000042 parselanmıyor -0000
{
	int		i;
	char	*retval;
	int		k;

	i = 0;
	k = 0;
	while (str[i] && str[i] == '0')
		i++;
	if (!str[i])//sayı sadece 0'lardna oluşuyorsa tek sıfır döndürürüz.
	{
		retval = malloc (2 * sizeof(char));
		if (!retval)
			return (NULL);
		retval[0] = '0';
		retval[1] = '\0';
		return (retval);
	}
	retval = malloc((ft_strlen(&str[i]) + 1) * sizeof(char));
	if (!retval)
		return (NULL);
	while (str[i])
		retval[k++] = str[i++];
	retval[k] = '\0';
	return (retval);
}

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
