/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:33:34 by pvilchez          #+#    #+#             */
/*   Updated: 2023/12/06 21:55:02 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Returns the current time in milliseconds.
 * @return Current time in milliseconds.
 */
long	now(void)
{
	struct timeval	time;
	long			t_int;

	gettimeofday(&time, NULL);
	t_int = timeval_to_int(time);
	return (t_int);
}

/**
 * @brief Converts a timeval struct to milliseconds.
 * @param time Timeval struct to convert.
 * @return Time in milliseconds.
 */
long	timeval_to_int(struct timeval time)
{
	long	t_int;

	t_int = time.tv_sec * 1000;
	t_int += time.tv_usec / 1000;
	return (t_int);
}

/**
 * @brief Returns the time elapsed since the start of the meal.
 * @param start Start time of the meal.
 * @return Time elapsed since the start of the meal.
 */
long	lapsed_time(long start)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (timeval_to_int(time) - start);
}
