/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:54:03 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/24 18:40:06 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threads_create(t_waiter *waiter, t_philo **philos)
{
	int	i;

	i = -1;
	while (++i < waiter->table.philo_count)
		philo_create_thread(i, philos);
	waiter_create_thread(waiter);
	sleep(1);
}

void	threads_end(t_waiter *waiter, t_philo **philos)
{
	int	i;

	i = -1;
	while (++i < waiter->table.philo_count)
		pthread_join((*philos)[i].thread, NULL);
	pthread_join(waiter->waiter, NULL);
}
