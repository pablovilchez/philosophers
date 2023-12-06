/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:11:11 by pvilchez          #+#    #+#             */
/*   Updated: 2023/12/06 21:52:52 by pvilchez         ###   ########.fr       */
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

// clean_table.c
void		clean_table(t_table *table);

// eating.c
int			end_by_dead(t_table *table, int i);
void		*philo_thread(void *arg);
int			eating(t_table *table);

// mutex_func.c
void		destroy_forks_mutex(t_table *table);
int			create_forks_mutex(t_table *table);

// philos_func.c
void		use_print_mutex(char *str, t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
int			create_philos(t_table *table);

// read_args.c
long		phi_atoi(const char *str, int *check);
int			arg_num_philos(char *str, int *check);
int			read_args(int argc, char *argv[], t_table *table);

// table_func.c
void		clear_table(t_table *table);
int			set_table(t_table *table);
t_table		*create_table(void);

// time_func.c
long		now(void);
long		timeval_to_int(struct timeval time);
long		lapsed_time(long start);

#endif