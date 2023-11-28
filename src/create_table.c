/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:41:06 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/28 23:56:44 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_table	*create_table(t_table *table)
{
	table = malloc(sizeof(t_table));
	if (table)
	{
		table->num_philos = 0;
		table->t_die = 0;
		table->t_eat = 0;
		table->t_sleep = 0;
		table->num_eats = 0;
		table->any_dead = 0;
		table->start.tv_sec = 0;
		table->start.tv_usec = 0;
		table->forks = NULL;
		table->philos = NULL;
		return (1);
	}
	printf("Error: error in table malloc.");
	return (0);
}
