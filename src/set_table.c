/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:51:30 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/29 00:18:28 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	set_table(t_table *table)
{
	if (create_forks_mutex(table))
		return (1);
	if (pthread_mutex_init(&table->print, NULL))
	{
		printf("Error: bad init mutex.");
		return (1);
	}
	if (pthread_mutex_init(&table->dead, NULL))
	{
		printf("Error: bad init mutex.");
		return (1);
	}
	if (create_philos(table))
		return (1);
	table->any_dead = 0;
	return (0);
}
