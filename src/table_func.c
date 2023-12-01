/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:41:06 by pvilchez          #+#    #+#             */
/*   Updated: 2023/12/01 23:24:45 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Destroy the table and free the memory.
 * @param table Pointer to the table struct.
 */
void	clear_table(t_table *table)
{
	destroy_mutex(table->forks);
	free(table->philos);
}

/**
 * @brief Sets the start time of the simulation.
 * @param table Pointer to the table struct.
 */
void	set_table_start_time(t_table *table)
{
	struct timeval	time;
	int				i;

	gettimeofday(&time, NULL);
	table->start.tv_sec = time.tv_sec;
	table->start.tv_usec = time.tv_usec;
	i = 0;
	while (i < table->num_philos)
	{
		table->philos[i].start = table->start;
		i++;
	}
}

/**
 * @brief Destroy the table and free the memory.
 * @param table Pointer to the table struct.
 */
int	set_table(t_table *table)
{
	if (create_mutex_lst(&table->forks, table->num_philos))
		return (1);
	if (pthread_mutex_init(&table->print, NULL))
	{
		printf("Error: bad init mutex.");
		return (1);
	}
	if (pthread_mutex_init(&table->dead, NULL))
	{
		printf("Error: bad init mutex.");
		return (1);
	}
	if (create_philos(table))
		return (1);
	table->any_dead = 0;
	return (0);
}

/**
 * @brief Create and initialize a table with the structure t_table.
 * @param table Pointer to the table struct.
 * @return 1 if success, 0 if error.
 */
t_table	*create_table(t_table *table)
{
	table = malloc(sizeof(t_table));
	if (table)
	{
		table->num_philos = 0;
		table->philos = NULL;
		table->forks = NULL;
		table->start.tv_sec = 0;
		table->start.tv_usec = 0;
		table->t_die = 0;
		table->t_eat = 0;
		table->t_sleep = 0;
		table->num_eats = 0;
		table->any_dead = 0;
		return (1);
	}
	printf("Error: error in table malloc.");
	return (0);
}