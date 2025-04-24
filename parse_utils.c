/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 05:54:29 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/24 17:26:14 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_num(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{		//00000000000000000000000000042 hala hatalı çalışıyor.
	long long	res;
	int			negative;
	char		*str2;

	negative = 1;
	res = 0;
	str2 = ft_trim_num(str);
	if (ft_strlen(str2) > 13)
		ft_max_int_error();
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
		ft_max_int_error();
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

char	*ft_trim_num(char *str)//sayıların önündeki 0'ları silecek. *YAPILACAK: -000000042 parselanmıyor
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
	retval[k] = '\0'
	return (retval);
}

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
