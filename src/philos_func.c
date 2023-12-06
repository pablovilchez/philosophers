/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:44:14 by pvilchez          #+#    #+#             */
/*   Updated: 2023/12/06 19:25:47 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Prints on the screen the time, the philosopher and the action
 * performed, after using mutex.
 * @param str String to print.
 * @param args Pointer to the arguments struct.
 */
void	use_print_mutex(char *str, t_philo *philo)
{
	int	time;

	time = lapsed_time(philo->table->init_time);
	pthread_mutex_lock(&(philo->table->end_mutex));
	if (philo->table->end)
	{
		pthread_mutex_unlock(&(philo->table->end_mutex));
		return ;
	}
	pthread_mutex_lock(&(philo->table->print_mutex));
	printf("%i ", time);
	printf("%i ", philo->pos + 1);
	printf("%s\n", str);
	pthread_mutex_unlock(&(philo->table->print_mutex));
	pthread_mutex_unlock(&(philo->table->end_mutex));
}

/**
 * @brief Function that simulates the action of eating.
 * @param args Pointer to the arguments struct.
 */
void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	use_print_mutex("has taken a fork", philo);
	if (philo->table->num_philos == 1)
	{
		usleep(philo->table->time_die * 1000);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	use_print_mutex("has taken a fork", philo);
	use_print_mutex("is eating", philo);
	pthread_mutex_lock(&philo->last_eat_mutex);
	philo->last_eat = now();
	pthread_mutex_unlock(&philo->last_eat_mutex);
	usleep(philo->table->time_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(&philo->num_eats_mutex);
	philo->num_eats++;
	pthread_mutex_unlock(&philo->num_eats_mutex);
}

/**
 * @brief Function that simulates the action of sleeping.
 * @param args Pointer to the arguments struct.
 */
void	philo_sleep(t_philo *philo)
{
	use_print_mutex("is sleeping", philo);
	usleep(philo->table->time_sleep * 1000);
}

/**
 * @brief Function that simulates the action of thinking.
 * @param args Pointer to the arguments struct.
 */
void	philo_think(t_philo *philo)
{
	use_print_mutex("is thinking", philo);
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
			table->philos[i].table = table;
			table->philos[i].num_eats = 0;
			pthread_mutex_init(&table->philos[i].last_eat_mutex, NULL);
			pthread_mutex_init(&table->philos[i].num_eats_mutex, NULL);
			i++;
		}
		return (1);
	}
	printf("Error: error in philos malloc.");
	return (0);
}
