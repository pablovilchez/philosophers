/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:20:48 by pvilchez          #+#    #+#             */
/*   Updated: 2023/12/01 23:17:23 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Destroy mutex for each element of the list and free the list.
 * @param lst Pointer to the list.
 * @param num_elements Number of elements to destroy.
 */
void	destroy_mutex_lst(pthread_mutex_t **lst, int num_elements)
{
	int				i;
	pthread_mutex_t	*elem;

	elem = *lst;
	i = 0;
	while (i < num_elements)
	{
		pthread_mutex_destroy(*lst);
		i++;
	}
	free(lst);
}

/**
 * @brief Create and initialize a mutex for each element of the list.
 * @param lst Pointer to the list.
 * @param num_elements Number of elements to initialize.
 * @return 1 if success, 0 if error.
 */
int	create_mutex_lst(pthread_mutex_t **lst, int num_elements)
{
	int				i;
	pthread_mutex_t	*elem;

	elem = malloc(sizeof(pthread_mutex_t) * num_elements);
	if (elem)
	{
		i = 0;
		while (i < num_elements)
		{
			if (pthread_mutex_init(&elem[i], NULL) != 0)
			{
				printf("Error: bad init mutex.");
				return (1);
			}
			i++;
		}
		*lst = elem;
		return (0);
	}
	printf("Error: error in forks malloc.");
	return (1);
}
