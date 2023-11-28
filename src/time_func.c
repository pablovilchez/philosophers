/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:33:34 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/29 00:32:06 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Sets the start time of the simulation.
 * @param table Pointer to the table struct.
 */
void	set_start_time(t_table *table)
{
	struct timeval	time;
	int				i;

	gettimeofday(&time, NULL);
	table->start.tv_sec = time.tv_sec;
	table->start.tv_usec = time.tv_usec;
	i = 0;
	while (i < table->num_philos)
	{
		table->philos[i].start = table->start;
		i++;
	}
}

/**
 * @brief Converts a timeval struct to milliseconds.
 * @param time Timeval struct.
 * @return Time in milliseconds.
 */
int	timeval_to_int(struct timeval time)
{
	int	t_int;

	t_int = time.tv_sec * 1000;
	t_int += time.tv_usec / 1000;
	return (t_int);
}

/**
 * @brief Calculates the time elapsed since a given moment.
 * @param start Timeval struct of the given moment.
 * @return Elapsed time in milliseconds.
 */
int	lapsed_time(struct timeval start)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (timeval_to_int(time) - timeval_to_int(start));
}
