/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:44:14 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/28 23:23:04 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	use_print_mutex(char *str, t_args *args)
{
	pthread_mutex_lock(&(args->table->dead));
	if (args->table->any_dead)
	{
		pthread_mutex_unlock(&(args->table->dead));
		return ;
	}
	pthread_mutex_unlock(&(args->table->dead));
	pthread_mutex_lock(&(args->table->print));
	printf("%i %i %s\n", now(args->philo->start), args->philo->pos + 1, str);
	pthread_mutex_unlock(&(args->table->print));
}

void	philo_eat(t_args *args)
{
	pthread_mutex_lock(args->philo->left_fork);
	use_print_mutex("has taken a fork", args);
	pthread_mutex_lock(args->philo->right_fork);
	use_print_mutex("is eating", args);
	args->philo->last_eat = now(args->philo->start);
	usleep(args->table->t_eat * 1000);
	pthread_mutex_unlock(args->philo->left_fork);
	pthread_mutex_unlock(args->philo->right_fork);
}

void	philo_sleep(t_args *args)
{
	use_print_mutex("is sleeping", args);
	usleep(args->philo->t_sleep * 1000);
}

void	philo_think(t_args *args)
{
	use_print_mutex("is thinking", args);
}
