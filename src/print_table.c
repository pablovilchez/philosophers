/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:46:10 by pvilchez          #+#    #+#             */
/*   Updated: 2023/11/28 19:18:05 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_table(t_table *table)
{
	printf("\nInformación de la mesa:\n");
	printf("  Filósofos y tenedores: %i\n", table->num_philos);
	printf("  Tiempo para morir:  %i\n", table->t_die);
	printf("  Tiempo para comer:  %i\n", table->t_eat);
	printf("  Tiempo para dormir: %i\n", table->t_sleep);
	printf("  Número de comidas:  %i\n", table->num_eats);
}
