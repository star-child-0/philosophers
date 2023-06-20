/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:07:17 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/20 19:39:36 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_init(t_waiter *waiter, t_philo **philos, t_fork **forks)
{
	int	i;

	i = 0;
	*philos = malloc(sizeof(t_philo) * waiter->table.philo_count);
	*forks = malloc(sizeof(t_fork) * waiter->table.philo_count);
	if (!*philos || !*forks)
		return (0);
	while (i < waiter->table.philo_count)
	{
		(*philos)[i].index = i;
		(*philos)[i].times_eaten = 0;
		(*philos)[i].pid = 0;
		(*philos)[i].table = &waiter->table;
		if (pthread_mutex_init(&(*forks)[i].fork_mx, NULL))
			return (0);
		i++;
	}
	return (1);
}
