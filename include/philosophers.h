/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:11:11 by pvilchez          #+#    #+#             */
/*   Updated: 2023/10/07 20:20:26 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				pos;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct timeval	t_die;
	struct timeval	t_eat;
	struct timeval	t_sleep;
	int				died;
}				t_philo;

typedef struct s_table
{
	int				num_philos;
	struct timeval	t_die;
	struct timeval	t_eat;
	struct timeval	t_sleep;
	t_philo			philo;
	int				num_eats;
}				t_table;


//	philo.c


// check_args.c
int				capt_args(int argc, char *argv[], t_table *table);
struct timeval	capt_timeval(long num, int *read);
long			str_to_int(const char *str, int *read);

// capt_args.c
void			print_table(t_table table);

// mutex_func.c
int				create_mutex(t_table *table, pthread_mutex_t *forks);
int				destroy_mutex(pthread_mutex_t *forks);

// start_philos.c
int				run_philos(t_table *table);

// philo_actions.c
void			phi_eat(void);
void			phi_sleep(void);
void			phi_think(void);

#endif