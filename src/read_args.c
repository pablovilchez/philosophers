/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:37:40 by pvilchez          #+#    #+#             */
/*   Updated: 2023/12/06 21:53:17 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Convert a string to a int.
 * @param str String to convert.
 * @param check Pointer to validate the continuation of reading arguments.
 * @return The int conversion result.
 */
long	phi_atoi(const char *str, int *check)
{
	long	num;

	num = 0;
	while (*str && *check == 1)
	{
		if (*str >= '0' && *str <= '9')
			num = num * 10 + (*str - '0');
		else
		{
			printf("Error: Not numeric or negative argument.\n");
			*check = 0;
			return (0);
		}
		str++;
	}
	return (num);
}

/**
 * @brief Check and convert the value of the number of philosophers.
 * @param str String to convert.
 * @param check Pointer to validate the continuation of reading arguments.
 * @return The long conversion result.
 */
int	arg_num_philos(char *str, int *check)
{
	int	num_philos;

	num_philos = (int)phi_atoi(str, check);
	if (num_philos > 250)
	{
		printf("Error: max. number of philosophers (250).\n");
		*check = 0;
	}
	return (num_philos);
}

/**
 * @brief Read the arguments and assign them to the table struct.
 * @param argc Number of arguments.
 * @param argv Arguments.
 * @param table Pointer to the table struct.
 * @return 1 if success, 0 if error.
 */
int	read_args(int argc, char *argv[], t_table *table)
{
	int	check;

	check = 1;
	if (argc == 5 || argc == 6)
	{
		table->num_philos = arg_num_philos(argv[1], &check);
		table->time_die = phi_atoi(argv[2], &check);
		table->time_eat = phi_atoi(argv[3], &check);
		table->time_sleep = phi_atoi(argv[4], &check);
		if (argc == 6)
			table->num_eats = phi_atoi(argv[5], &check);
		else
			table->num_eats = -1;
	}
	else
	{
		printf("Error: bad number of arguments.\n");
		check = 0;
	}
	return (check);
}
