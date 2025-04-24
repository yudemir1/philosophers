/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 05:33:51 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/24 04:01:20 by yudemir          ###   ########.fr       */
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

typedef struct s_rules
{
	int 	number_of_philosophers;
	int 	time_to_die;
	int 	time_to_eat;
	int 	time_to_sleep;
	int		eat_counter;
} t_rules;


#endif