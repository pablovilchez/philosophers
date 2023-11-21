/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:10:59 by pvilchez          #+#    #+#             */
/*   Updated: 2023/10/07 20:14:03 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_table			table;
	pthread_mutex_t	*forks;

	forks = NULL;
	if (capt_args(argc, argv, &table))
	{
		print_table(table);
		if (create_mutex(&table, forks) == 0)
		{
			run_philos(&table);
			destroy_mutex(forks);
		}
	}
	return (0);
}
