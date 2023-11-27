/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capt_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:37:40 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/27 23:38:04 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	str_to_int(const char *str, int *read)
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

struct timeval	capt_timeval(long num, int *read)
{
	struct timeval	time;

	time.tv_sec = 0;
	time.tv_usec = 0;
	if (num > 0)
	{
		time.tv_sec = num / 1000000;
		time.tv_usec = num % 1000000;
	}
	else
	{
		printf("Incorrect arguments values. Must be > 0.\n");
		*read = 0;
	}
	return (time);
}

long	capt_philos(char *str, int *read)
{
	long	philosophers;

	philosophers = str_to_int(str, read);
	if (philosophers > 250)
	{
		printf("Error: Exceeded maximum number of philosophers (250).\n");
		*read = 0;
	}
	return (philosophers);
}

int	capt_args(int argc, char *argv[], t_table *table)
{
	int	read;

	read = 0;
	if (argc == 5 || argc == 6)
	{
		read = 1;
		table->num_philos = capt_philos(argv[1], &read);
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
