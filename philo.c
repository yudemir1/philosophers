/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 05:42:51 by yudemir           #+#    #+#             */
/*   Updated: 2025/04/25 03:20:01 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_rules *rules;
	
	rules = NULL;
	parse(ac, av, &rules);
	print_arguments(rules);

	free(rules);
}