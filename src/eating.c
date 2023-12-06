/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:02:35 by pvilchez          #+#    #+#             */
/*   Updated: 2023/12/06 21:50:40 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Check if all philosophers have eaten the number of times specified
 * in the arguments.
 * @param table Pointer to the table struct.
 * @return 1 if all philosophers have eaten the number of times specified,
 * 0 otherwise.
 */
int	end_by_eat_num(t_table *table, int j)
{
	if (j == table->num_philos)
	{
		pthread_mutex_lock(&table->end_mutex);
		table->end = 1;
		pthread_mutex_unlock(&table->end_mutex);
		pthread_mutex_lock(&table->print_mutex);
		printf("%li ", lapsed_time(table->init_time));
		printf("All philos have eaten at least %i times\n", table->num_eats);
		pthread_mutex_unlock(&table->print_mutex);
		return (1);
	}
	return (0);
}

/**
 * @brief Check if a philosopher has exceeded his maximum life span without
 * eating.
 * @param table Pointer to the table struct.
 * @param i Position of the philosopher in the table.
 * @return 1 if the philosopher has exceeded his maximum life span without
 * eating, 0 otherwise.
 */
int	end_by_dead(t_table *table, int i)
{
	pthread_mutex_lock(&table->philos[i].last_eat_mutex);
	if (lapsed_time(table->philos[i].last_eat) > table->time_die)
	{
		pthread_mutex_lock(&table->end_mutex);
		table->end = 1;
		pthread_mutex_unlock(&table->end_mutex);
		pthread_mutex_lock(&table->print_mutex);
		printf("%li ", lapsed_time(table->init_time));
		printf("%i died\n", table->philos[i].pos + 1);
		pthread_mutex_unlock(&table->print_mutex);
		pthread_mutex_unlock(&table->philos[i].last_eat_mutex);
		return (1);
	}
	return (0);
}

/**
 * @brief Check if the simulation should end.
 * @param table Pointer to the table struct.
 */
void	watch_table(t_table *table)
{
	int	i;
	int	j;

	while (1)
	{
		i = 0;
		j = 0;
		while (i < table->num_philos)
		{
			if (end_by_dead(table, i))
				return ;
			pthread_mutex_unlock(&table->philos[i].last_eat_mutex);
			if (table->num_eats > 0)
			{
				pthread_mutex_lock(&table->philos[i].num_eats_mutex);
				if (table->philos[i].num_eats >= table->num_eats)
					j++;
				pthread_mutex_unlock(&table->philos[i].num_eats_mutex);
			}
			if (end_by_eat_num(table, j))
				return ;
			i++;
		}
	}
}

/**
 * @brief Function with the routine that each philosopher performs.
 * @param args Pointer to the arguments struct.
 */
void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->pos % 2 == 0)
	{
		usleep(philo->table->time_eat * 100);
		philo_think(philo);
	}
	while (1)
	{
		pthread_mutex_lock(&philo->table->end_mutex);
		if (philo->table->end)
		{
			pthread_mutex_unlock(&philo->table->end_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->table->end_mutex);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

/**
 * @brief Simulates the eating process.
 * @param table Pointer to the table struct.
 * @return 1 if success, 0 if error.
 */
int	eating(t_table *table)
{
	int			i;
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * table->num_philos);
	if (threads)
	{
		i = 0;
		table->init_time = now();
		while (i < table->num_philos)
		{
			table->philos[i].last_eat = now();
			pthread_create(&threads[i], NULL, philo_thread, &table->philos[i]);
			i++;
		}
		watch_table(table);
		i = 0;
		while (i < table->num_philos)
		{
			pthread_join(threads[i], NULL);
			i++;
		}
		return (1);
	}
	printf("Error: error in threads malloc.");
	return (0);
}
