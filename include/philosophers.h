/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:11:11 by pvilchez          #+#    #+#             */
/*   Updated: 2023/12/02 11:05:31 by pvilchez         ###   ########.fr       */
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

// start_philos.c
int				start_eating(t_table *table);

// philo_actions.c
void			philo_eat(t_args *args);
void			philo_sleep(t_args *args);
void			philo_think(t_args *args);



// Archivos comprobados y comentados:


// mutex_func.c
void			destroy_mutex_lst(pthread_mutex_t **lst, int num_elements);
int				create_mutex_lst(pthread_mutex_t **lst, int num_elements);

// read_args.c
int				capt_args(int argc, char *argv[], t_table *table);
int				phi_atoi(const char *str, int *check);
int				arg_num_philos(char *str, int *check);
int				read_args(int argc, char *argv[], t_table *table);

// table_func.c
void			clear_table(t_table *table);
void			set_table_start_time(t_table *table);
int				set_table(t_table *table);
t_table			*create_table(t_table *table);

// time_func.c
int				timeval_to_int(struct timeval time);
int				lapsed_time(struct timeval start);

#endif