/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:02:35 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/22 21:46:48 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	*mi_funcion(void *arg)
{
	int	i;
	int	tid;
	int	hilo;

	i = 0;
	hilo = *((int *)arg);
	tid = (int)pthread_self();
	while (i < 10)
	{
		pthread_mutex_lock(&miMutex);
		if (pthread_equal(tid, hilo))
			printf("imprime A\n");
		if (pthread_equal(tid, hilo))
			printf("   imprime B\n");
		i++;
		pthread_mutex_unlock(&miMutex);
	}
	return (NULL);
}


int	run_philos(t_table *table)
{
	pthread_t	*mi_mutex;
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
