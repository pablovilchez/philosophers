/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:02:35 by pvilchez          #+#    #+#             */
/*   Updated: 2023/10/07 20:38:29 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	contador = 0;

void	*miFuncion(void *arg)
{
	int	tid;
	int	hilo;

	hilo = *((int *)arg);
	tid = (int)pthread_self();
	for (int i = 0; i < 10; i++) {
		pthread_mutex_lock(&miMutex);
		if (pthread_equal(tid, hilo))
			printf("imprime A\n");
		if (pthread_equal(tid, hilo))
			printf("   imprime B\n");
		contador++;
		pthread_mutex_unlock(&miMutex);
	}
	return (NULL);
}


int	run_philos(t_table *table)
{
	pthread_t	*miMutex;
	int			i;

	i = 0;
	while (i < table->num_philos)
	{
		if (pthread_create(&hilos[i], NULL, miFuncion, &hilos[i]) != 0)
		{
			perror("Error al crear el hilo");
			return (1);
		}
		i++;
	}
	while (i < table->num_philos)
	{
		if (pthread_join(hilos[i], NULL) != 0)
		{
			perror("Error al unir el hilo");
			return (1);
		}
	}
}
