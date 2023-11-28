/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:17:18 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/29 00:22:29 by pvilchez         ###   ########.fr       */
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
	int				last_eat;
	struct timeval	start;
	int				t_die;
	int				t_eat;
	int				t_sleep;
}				t_philo;

typedef struct s_table
{
	int				num_philos;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	struct timeval	start;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				num_eats;
	int				any_dead;
}				t_table;

typedef struct s_args
{
	t_philo	*philo;
	t_table	*table;
}			t_args;

#endif