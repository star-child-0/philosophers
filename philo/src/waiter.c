/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:29:42 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/20 21:35:17 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*waiter_routine(void *arg)
{
	return (NULL);
}

int	waiter_create_thread(t_waiter *waiter)
{
	if (pthread_create(&waiter->waiter, NULL, waiter_routine, waiter))
		return (0);
	return (1);
}

int	waiter_init(t_waiter *waiter, t_table table)
{
	waiter->table = table;
	waiter->safe = 1;
	if (pthread_mutex_init(&waiter->print_mx, NULL))
		return (0);
	if (pthread_mutex_init(&waiter->death_mx, NULL))
		return (0);
	if (pthread_mutex_init(&waiter->philo_mx, NULL))
		return (0);
	return (1);
}
