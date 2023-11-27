/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:51:30 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/27 23:48:05 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_philos(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo) * table->num_philos);
	if (table->philos)
	{
		i = 0;
		gettimeofday(&table->start, NULL);
		while (i < table->num_philos)
		{
			table->philos[i].pos = i;
			table->philos[i].left_fork = &table->forks[i];
			table->philos[i].right_fork = &table->forks[(i + 1) \
				% table->num_philos];
			table->philos[i].last_eat = table->start;
			i++;
		}
		return (0);
	}
	printf("Error: error in philos malloc.");
	return (1);
}

int	set_table(t_table *table)
{
	if (create_mutex(table))
		return (1);
	if (pthread_mutex_init(&table->print, NULL) != 0)
	{
		printf("Error: bad init mutex.");
		return (1);
	}
	if (pthread_mutex_init(&table->dead, NULL) != 0)
	{
		printf("Error: bad init mutex.");
		return (1);
	}
	if (create_philos(table))
		return (1);
	table->any_dead = 0;
	return (0);
}
