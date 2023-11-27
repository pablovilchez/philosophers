/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:33:34 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/27 23:35:21 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	time_diff(struct timeval start, struct timeval end)
{
	long	diff;

	diff = (end.tv_sec - start.tv_sec) * 1000;
	diff += (end.tv_usec - start.tv_usec) / 1000;
	return (diff);
}
