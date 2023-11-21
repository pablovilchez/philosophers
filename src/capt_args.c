/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capt_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:37:40 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/21 20:10:27 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	str_to_int(const char *str, int *read)
{
	long	result;

	result = 0;
	while (*str && *read == 1)
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + (*str - '0');
		else
		{
			printf("Error: Not numeric or negative arguments.\n");
			*read = 0;
		}
		str++;
	}
	return (result);
}

struct timeval	capt_timeval(long num, int *read)
{
	struct timeval	tiempo;

	tiempo.tv_sec = 0;
	tiempo.tv_usec = 0;
	if (num > 0)
	{
		tiempo.tv_sec = num / 1000000;
		tiempo.tv_usec = num % 1000000;
	}
	else
	{
		printf("Incorrect arguments values. Must be > 0.\n");
		*read = 0;
	}
	return (tiempo);
}

int	capt_args(int argc, char *argv[], t_table *table)
{
	int	read;

	read = 0;
	if (argc == 5 || argc == 6)
	{
		read = 1;
		table->num_philos = str_to_int(argv[1], &read);
		if (read == 1)
			table->t_die = capt_timeval(str_to_int(argv[2], &read), &read);
		if (read == 1)
			table->t_eat = capt_timeval(str_to_int(argv[3], &read), &read);
		if (read == 1)
			table->t_sleep = capt_timeval(str_to_int(argv[4], &read), &read);
		if (read == 1 && argc == 6)
			table->num_eats = str_to_int(argv[5], &read);
		else
			table->num_eats = -1;
	}
	else
		printf("Error: Bad arguments\n");
	return (read);
}
