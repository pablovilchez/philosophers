/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:11:11 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/28 20:14:51 by pvilchez         ###   ########.fr       */
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
long			str_to_int(const char *str, int *read);

// mutex_func.c
int				create_forks_mutex(t_table *table);
int				destroy_mutex(pthread_mutex_t *forks);

// start_philos.c
int				start_eating(t_table *table);

// philo_actions.c
void			philo_eat(t_args *args);
void			philo_sleep(t_args *args);
void			philo_think(t_args *args);

// time_func.c
int				time_to_int(struct timeval time);
int				now(int start);

// set_table.c
int				set_table(t_table *table);

// clear_table.c
void			clear_table(t_table *table);

// print_table.c
void			print_table(t_table *table);

#endif