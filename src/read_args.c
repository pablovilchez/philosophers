/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:37:40 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/29 00:10:08 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	phi_atoi(const char *str, int *read)
{
	long	time;

	time = 0;
	while (*str && *read == 1)
	{
		if (*str >= '0' && *str <= '9')
			time = time * 10 + (*str - '0');
		else
		{
			printf("Error: Not numeric or negative arguments.\n");
			*read = 0;
		}
		str++;
	}
	return (time);
}

long	arg_philos(char *str, int *read)
{
	long	num_philos;

	num_philos = phi_atoi(str, read);
	if (num_philos > 250)
	{
		printf("Error: max. number of philosophers (250).\n");
		*read = 0;
	}
	return (num_philos);
}

int	capt_args(int argc, char *argv[], t_table *table)
{
	int	check;

	check = 0;
	if (argc == 5 || argc == 6)
	{
		check = 1;
		table->num_philos = arg_philos(argv[1], &check);
		if (check == 1)
			table->t_die = phi_atoi(argv[2], &check);
		if (check == 1)
			table->t_eat = phi_atoi(argv[3], &check);
		if (check == 1)
			table->t_sleep = phi_atoi(argv[4], &check);
		if (check == 1 && argc == 6)
			table->num_eats = phi_atoi(argv[5], &check);
		else
			table->num_eats = -1;
	}
	if (check == 0)
	{
		free(table);
		printf("Error: bad arguments.\n");
	}
	return (check);
}
