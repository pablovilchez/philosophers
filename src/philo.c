/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:10:59 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/27 19:47:08 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_table			table;

	if (capt_args(argc, argv, &table))
	{
		if (set_table(&table))
			start_eating(&table);
	}
	clear_table(&table);
	return (0);
}
