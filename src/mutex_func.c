/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:20:48 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/22 21:57:04 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	destroy_mutex(pthread_mutex_t *forks)
{
	while (forks)
	{
		pthread_mutex_destroy(forks);
		forks++;
	}
	free(forks);
	printf("\nMutex destruido. Memoria liberada\n");
	return (0);
}


int	create_mutex(t_table *table, pthread_mutex_t **forks)
{
	int	i;

	*forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	if (*forks)
	{
		i = 0;
		while (i < table->num_philos)
		{
			if (pthread_mutex_init(forks[i], NULL) != 0)
			{
				printf("Error: bad init mutex.");
				return (1);
			}
			i++;
		}
		printf("\nMutex creados. Éxito reservando memoria para Forks.\n");
		return (0);
	}
	printf("Error: error in forks malloc.");
	return (1);
}
