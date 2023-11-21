/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:46:10 by pvilchez          #+#    #+#             */
/*   Updated: 2023/10/07 20:11:45 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_table(t_table table)
{
	printf("\nInformación de la mesa:\n");
	printf(" Número de filósofos y tenedores: %i\n", table.num_philos);
	printf(" Tiempo para morir:\n");
	printf("   S: %ld  uS: %ld\n", table.t_die.tv_sec, table.t_die.tv_usec);
	printf(" Tiempo para comer:\n");
	printf("   S: %ld  uS: %ld\n", table.t_eat.tv_sec, table.t_eat.tv_usec);
	printf(" Tiempo para dormir:\n");
	printf("   S: %ld  uS: %ld\n", table.t_sleep.tv_sec, table.t_sleep.tv_usec);
	printf(" Número de comidas: %i\n", table.num_eats);
}
