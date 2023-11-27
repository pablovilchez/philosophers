/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:02:35 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/27 21:27:51 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		philo_take_forks(philo_arg);
		philo_eat(philo_arg);
		philo_sleep(philo_arg);
		philo_think(philo_arg);
	}
	return (NULL);
}

int	start_eating(t_table *table)
{
	int			i;
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * table->num_philos);
	if (threads)
	{
		i = 0;
		while (i < table->num_philos)
		{
			pthread_create(&threads[i], NULL, philo_thread, &table->philos[i]);
			i++;
		}
		i = 0;
		while (i < table->num_philos)
		{
			pthread_join(threads[i], NULL);
			i++;
		}
		return (0);
	}
	printf("Error: error in philos malloc.");
	return (1);
}
