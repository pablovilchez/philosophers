/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:02:35 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/28 23:17:47 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_args(t_args **args, t_table *table, int i)
{
	t_args	*new;

	new = malloc(sizeof(t_args));
	new->table = table;
	new->philo = &(table->philos[i]);
	*args = new;
}

void	*philo_thread(void *arg)
{
	t_args	*args;
	int		i;

	args = (t_args *)arg;
	if (args->philo->pos % 2 == 0)
	{
		usleep(args->philo->t_eat * 100);
		philo_think(args);
	}
	while (1)
	{
		pthread_mutex_lock(&args->table->dead);
		if (args->table->any_dead)
		{
			pthread_mutex_unlock(&args->table->dead);
			return (NULL);
		}
		pthread_mutex_unlock(&args->table->dead);
		philo_eat(args);
		philo_sleep(args);
		philo_think(args);
		i++;
	}
	return (NULL);
}

void	check_dead(t_table *table)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < table->num_philos)
		{
			if (now(table->philos[i].last_eat) > table->t_die)
			{
				pthread_mutex_lock(&table->dead);
				printf("%i %i died\n", now(table->philos[i].start), \
					table->philos[i].pos + 1);
				table->any_dead = 1;
				pthread_mutex_unlock(&table->dead);
				return ;
			}
			i++;
		}
	}
}

int	start_eating(t_table *table)
{
	int			i;
	pthread_t	*threads;
	t_args		*args;

	threads = malloc(sizeof(pthread_t) * table->num_philos);
	if (threads)
	{
		i = 0;
		while (i < table->num_philos)
		{
			init_args(&args, table, i);
			pthread_create(&threads[i], NULL, philo_thread, args);
			i++;
		}
		check_dead(table);
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
