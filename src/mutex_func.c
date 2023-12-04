/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:20:48 by pvilchez          #+#    #+#             */
/*   Updated: 2023/12/03 18:59:02 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Destroy mutex for each element of the list and free the list.
 * @param lst Pointer to the list.
 * @param num_elements Number of elements to destroy.
 */
void	destroy_forks_mutex(t_table *table)
{
	int				i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->forks);
}

/**
 * @brief Create and initialize a mutex for each element of the list.
 * @param table Pointer to the table.
 * @return 1 if success, 0 if error.
 */
int	create_forks_mutex(t_table *table)
{
	int				i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	if (table->forks)
	{
		i = 0;
		while (i < table->num_philos)
		{
			if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			{
				printf("Error: bad init mutex.");
				return (1);
			}
			i++;
		}
		return (0);
	}
	printf("Error: error in forks malloc.");
	return (1);
}
