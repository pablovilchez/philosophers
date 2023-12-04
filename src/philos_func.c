/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:44:14 by pvilchez          #+#    #+#             */
/*   Updated: 2023/12/03 23:48:01 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Prints on the screen the time, the philosopher and the action
 * performed, after using mutex.
 * @param str String to print.
 * @param args Pointer to the arguments struct.
 */
void	use_print_mutex(char *str, t_args *args)
{
	pthread_mutex_lock(&(args->table->end_mutex));
	if (args->table->end)
	{
		pthread_mutex_unlock(&(args->table->end_mutex));
		return ;
	}
	pthread_mutex_unlock(&(args->table->end_mutex));
	pthread_mutex_lock(&(args->table->print_mutex));
	printf("%i ", lapsed_time(args->table->init_time));
	printf("%i ", args->philo->pos + 1);
	printf("%s\n", str);
	pthread_mutex_unlock(&(args->table->print_mutex));
}

/**
 * @brief Function that simulates the action of eating.
 * @param args Pointer to the arguments struct.
 */
void	philo_eat(t_args *args)
{
	pthread_mutex_lock(args->philo->left_fork);
	use_print_mutex("has taken a fork", args);
	pthread_mutex_lock(args->philo->right_fork);
	use_print_mutex("has taken a fork", args);
	use_print_mutex("is eating", args);
	args->philo->last_eat = now();
	usleep(args->table->time_eat * 1000);
	pthread_mutex_unlock(args->philo->left_fork);
	pthread_mutex_unlock(args->philo->right_fork);
}

/**
 * @brief Function that simulates the action of sleeping.
 * @param args Pointer to the arguments struct.
 */
void	philo_sleep(t_args *args)
{
	use_print_mutex("is sleeping", args);
	usleep(args->table->time_sleep * 1000);
}

/**
 * @brief Function that simulates the action of thinking.
 * @param args Pointer to the arguments struct.
 */
void	philo_think(t_args *args)
{
	use_print_mutex("is thinking", args);
}

/**
 * @brief Create and initialize the philosophers whith the fixed values.
 * @param table Pointer to the table.
 * @return 1 if success, 0 if error.
 */
int	create_philos(t_table *table)
{
	int				i;
	int				aux;

	table->philos = malloc(sizeof(t_philo) * table->num_philos);
	if (table->philos)
	{
		i = 0;
		while (i < table->num_philos)
		{
			table->philos[i].pos = i;
			table->philos[i].left_fork = &table->forks[i];
			aux = (i + 1) % table->num_philos;
			table->philos[i].right_fork = &table->forks[aux];
			i++;
		}
		return (1);
	}
	printf("Error: error in philos malloc.");
	return (0);
}
