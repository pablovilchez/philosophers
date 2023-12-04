/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:02:35 by pvilchez          #+#    #+#             */
/*   Updated: 2023/12/03 23:47:21 by pvilchez         ###   ########.fr       */
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
int	check_meals(t_table *table)
{
	int	i;

	i = 0;
	if (table->num_eats == -1)
		return (0);
	while (i < table->num_philos)
	{
		if (table->philos[i].num_eats < table->num_eats)
			return (0);
		i++;
	}
	if (i == table->num_philos)
	{
		pthread_mutex_lock(&table->end_mutex);
		table->end = 1;
		pthread_mutex_unlock(&table->end_mutex);
		pthread_mutex_lock(&table->print_mutex);
		printf("%i ", lapsed_time(table->init_time));
		printf("All philos have eaten at least %i times\n", table->num_eats);
		pthread_mutex_unlock(&table->print_mutex);
		return (1);
	}
	return (0);
}

/**
 * @brief It continually checks whether any philosopher has exceeded his
 * maximum life span without eating.
 * @param table Pointer to the table struct.
 */
void	watch_table(t_table *table)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < table->num_philos)
		{
			if (lapsed_time(table->philos[i].last_eat) > table->time_die)
			{
				pthread_mutex_lock(&table->end_mutex);
				table->end = 1;
				pthread_mutex_unlock(&table->end_mutex);
				pthread_mutex_lock(&table->print_mutex);
				printf("%i ", lapsed_time(table->init_time));
				printf("%i died\n", table->philos[i].pos + 1);
				pthread_mutex_unlock(&table->print_mutex);
				return ;
			}
			i++;
		}
		if (check_meals(table))
			return ;
	}
}

/**
 * @brief Function with the routine that each philosopher performs.
 * @param args Pointer to the arguments struct.
 */
void	*philo_thread(void *arg)
{
	t_args	*args;

	args = (t_args *)arg;
	if (args->philo->pos % 2 == 0)
	{
		usleep(args->table->time_eat * 100);
		philo_think(args);
	}
	while (1)
	{
		if (args->table->end)
			break ;
		philo_eat(args);
		philo_sleep(args);
		philo_think(args);
	}
	return (NULL);
}

/**
 * @brief Create the arguments struct for each philosopher.
 * @param args Pointer to the arguments struct.
 * @param table Pointer to the table struct.
 * @param i Position of the philosopher.
 */
void	thread_args(t_args **args, t_table *table, int i)
{
	t_args	*new;

	new = malloc(sizeof(t_args));
	new->table = table;
	new->philo = &(table->philos[i]);
	*args = new;
}

/**
 * @brief Simulates the eating process, creating each thread and checking
 * when it should end.
 * @param table Pointer to the table struct.
 * @return 1 if success, 0 if error.
 */
int	eating(t_table *table)
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
			thread_args(&args, table, i);
			pthread_create(&threads[i], NULL, philo_thread, args);
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
