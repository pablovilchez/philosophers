/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:11:11 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/27 23:37:21 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <pthread.h>
# include "philo_structs.h"

//	philo.c

// check_args.c
int				capt_args(int argc, char *argv[], t_table *table);
struct timeval	capt_timeval(long num, int *read);
long			str_to_int(const char *str, int *read);

// capt_args.c
void			print_table(t_table table);

// mutex_func.c
int				create_mutex(t_table *table);
int				destroy_mutex(pthread_mutex_t *forks);

// start_philos.c
int				start_eating(t_table *table);

// philo_actions.c
void			phi_eat(void);
void			phi_sleep(void);
void			phi_think(void);

// time_func.c
long			time_diff(struct timeval start, struct timeval end);

#endif