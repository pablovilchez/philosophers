/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:17:18 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/27 23:47:03 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTS_H
# define PHILO_STRUCTS_H

# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				pos;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct timeval	last_eat;
}				t_philo;

typedef struct s_table
{
	int				num_philos;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	struct timeval	start;
	struct timeval	t_die;
	struct timeval	t_eat;
	struct timeval	t_sleep;
	int				num_eats;
	int				any_dead;
}				t_table;

#endif