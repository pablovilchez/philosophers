/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:17:18 by pvilchez          #+#    #+#             */
/*   Updated: 2023/12/06 19:20:28 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTS_H
# define PHILO_STRUCTS_H

# include <sys/time.h>
# include <pthread.h>

typedef struct s_table	t_table;

typedef struct s_philo
{
	int				pos;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	last_eat_mutex;
	int				last_eat;
	pthread_mutex_t	num_eats_mutex;
	int				num_eats;
	t_table			*table;
}				t_philo;

typedef struct s_table
{
	int				num_philos;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	int				init_time;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eats;
	pthread_mutex_t	end_mutex;
	int				end;
}				t_table;

#endif