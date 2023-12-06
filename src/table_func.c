/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:41:06 by pvilchez          #+#    #+#             */
/*   Updated: 2023/12/06 19:22:42 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Assign values ​​to the entire table to start the meal.
 * @param table Pointer to the table struct.
 * @return 1 if success, 0 if error.
 */
int	set_table(t_table *table)
{
	if (create_forks_mutex(table))
		return (0);
	if (pthread_mutex_init(&table->print_mutex, NULL))
	{
		printf("Error: bad init mutex.");
		return (0);
	}
	if (pthread_mutex_init(&table->end_mutex, NULL))
	{
		printf("Error: bad init mutex.");
		return (0);
	}
	if (!create_philos(table))
		return (0);
	return (1);
}

/**
 * @brief Create and initialize a table with the structure t_table.
 * @param table Pointer to the table struct.
 * @return 1 if success, 0 if error.
 */
t_table	*create_table(void)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (table)
	{
		table->num_philos = 0;
		table->philos = NULL;
		table->forks = NULL;
		table->init_time = 0;
		table->time_die = 0;
		table->time_eat = 0;
		table->time_sleep = 0;
		table->num_eats = 0;
		table->end = 0;
		return (table);
	}
	printf("Error: error in table malloc.");
	return (NULL);
}
