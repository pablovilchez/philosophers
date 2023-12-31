/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:42:26 by pvilchez          #+#    #+#             */
/*   Updated: 2023/12/06 19:27:39 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Destroy the forks mutex and free the memory.
 * @param table Pointer to the table struct.
 */
void	clear_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_destroy(&(table->forks[i]));
		i++;
	}
	free(table->forks);
}

/**
 * @brief Destroy the table and free the memory.
 * @param table Pointer to the table struct.
 */
void	clean_table(t_table *table)
{
	int	i;

	i = 0;
	if (table)
	{
		if (table->philos != NULL)
		{
			while (i < table->num_philos)
			{
				pthread_mutex_destroy(&(table->philos[i].last_eat_mutex));
				pthread_mutex_destroy(&(table->philos[i].num_eats_mutex));
				i++;
			}
			free(table->philos);
		}
		if (table->forks != NULL)
			clear_forks(table);
		pthread_mutex_destroy(&table->print_mutex);
		pthread_mutex_destroy(&table->end_mutex);
		free(table);
	}
}
