/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 05:33:51 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/25 13:45:31 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h> 

typedef struct s_rules//eğer struct'ın içindeki herhangi bir variable'ın türü değişirse parse bozulucak çünkü while içinde arr'e atıyoruz hepsini.
{
	int 	number_of_philosophers;
	int 	time_to_die;
	int 	time_to_eat;
	int 	time_to_sleep;
	int		eat_counter;
} t_rules;

void	parse(int ac, char **av, t_rules **rules);
void	print_arguments(t_rules *rules);
void	free_split(char **split);
int	ft_atoi(const char *str, int *arr, char **split);
void	null_check(char **av);
void	assign_rules(int *arr, t_rules **rules);
int	is_num(char *str, int *arr);
char	**ft_split(char const *s, char c);
void	ft_max_int_error(int *arr, char **split);
void	ft_error();
char	*ft_trim_num(const char *str);
int		ft_strlen(const char	*str);

#endif