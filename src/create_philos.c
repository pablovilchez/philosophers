/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 00:16:52 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/29 00:20:29 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_philos(t_table *table)
{
	int				i;
	struct timeval	time;

	table->philos = malloc(sizeof(t_philo) * table->num_philos);
	if (table->philos)
	{
		i = 0;
		
		while (i < table->num_philos)
		{
			table->philos[i].pos = i;
			table->philos[i].left_fork = &table->forks[i];
			table->philos[i].right_fork = &table->forks[(i + 1) \
				% table->num_philos];
			table->philos[i].last_eat = table->start;
			table->philos[i].start = table->start;
			table->philos[i].t_die = table->t_die;
			table->philos[i].t_eat = table->t_eat;
			table->philos[i].t_sleep = table->t_sleep;
			i++;
		}
		return (0);
	}
	printf("Error: error in philos malloc.");
	return (1);
}