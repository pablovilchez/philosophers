/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:10:59 by pvilchez          #+#    #+#             */
/*   Updated: 2023/12/02 10:55:28 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_table			*table;

	if (!create_table(table))
		return (1);
	if (!read_args(argc, argv, table))
		return (1);
	if (!create_philos(table))
		return (1);
	if (!create_forks_mutex(table))
		return (1);
	if (set_table(table) == 0)
	{
		start_eating(table);
	}
	clear_table(&table);
	return (0);
}
