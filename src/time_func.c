/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:33:34 by pvilchez          #+#    #+#             */
/*   Updated: 2023/12/01 23:31:09 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Returns the current time.
 * @return Timeval struct.
 */
struct timeval	*now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (&time);
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
