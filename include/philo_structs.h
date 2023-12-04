/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:17:18 by pvilchez          #+#    #+#             */
/*   Updated: 2023/12/03 23:24:24 by pvilchez         ###   ########.fr       */
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
	int				num_eats;
}				t_philo;

typedef struct s_table
{
	int				num_philos;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	struct timeval	init_time;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eats;
	pthread_mutex_t	end_mutex;
	int				end;
}				t_table;

typedef struct s_args
{
	t_philo	*philo;
	t_table	*table;
}			t_args;

#endif