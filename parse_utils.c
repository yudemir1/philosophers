/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 05:54:29 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/25 02:59:11 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_num(char *str, int *arr)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (!(str[i + 1]) || (str[i + 1] < '0' || str[i + 1] > '9')
				|| (i > 0 && (str[i - 1] != ' ')))
			{
				free(arr); // satır sayısı çok uzarsa, ft_error'a arr gönderilip error'un içinde freelenebilir.
				ft_error();
			}
		}
		else if (str[i] != ' ' && (str[i] < '0' || str[i] > '9'))
		{
			free(arr);
			ft_error();
		}
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str, int *arr, char **split)
{		//00000000000000000000000000042 düzeldi ama -000000000000000000000000000042 hatalı.
	long long	res;
	int			negative;
	char		*str2;

	negative = 1;
	res = 0;
	str2 = ft_trim_num(str);
	if (ft_strlen(str2) > 13)
		ft_max_int_error(arr ,split);
	while (*str2 && (*str2 == ' ' || (*str2 >= 9 && *str2 <= 13)))
		++str2;
	if (*str2 == '-')
		negative = -1;
	if (*str2 == '-' || *str2 == '+')
		++str2;
	while (*str2 && *str2 >= '0' && *str2 <= '9')
	{
		res = res * 10 + (*str2 - 48);
		++str2;
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
	while (str[i] && (str[i] == '0' || str[0] == '-'))
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
