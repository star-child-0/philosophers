/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:00:31 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/27 19:02:49 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_init(t_fork **forks, t_waiter *waiter)
{
	int	i;

	i = -1;
	while (++i < waiter->table.philo_count)
		pthread_mutex_init(&(*forks)[i].fork_mx, NULL);
}

void	forks_free(t_fork **forks, t_waiter *waiter)
{
	int	i;

	i = -1;
	while (++i < waiter->table.philo_count)
		pthread_mutex_destroy(&(*forks)[i].fork_mx);
	free(*forks);
}
