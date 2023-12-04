/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:10:59 by pvilchez          #+#    #+#             */
/*   Updated: 2023/12/04 00:39:47 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_table			*table;
	int				cont;

	cont = 1;
	table = create_table();
	if (table)
		cont = read_args(argc, argv, table);
	if (cont)
		cont = set_table(table);
	if (cont)
	{
		init_times(table);
		eating(table);
	}
	clean_table(table);
	return (0);
}
