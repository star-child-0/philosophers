/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:29:42 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/27 19:35:13 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*waiter_routine(void *arg)
{
	t_waiter	*waiter;

	waiter = (t_waiter *)arg;
	usleep(50);

	while (true)
	{
		if (!waiter->alive)
		{
			pthread_mutex_lock(waiter->menu->print_mx);
			printf("%sWaiter is dead%s\n", REDBOLD, UNSET);
			break ;
		}
	}
	return (NULL);
	waiter = (void *)waiter;
}

int	waiter_create_thread(t_waiter *waiter)
{
	if (pthread_create(&waiter->waiter, NULL, waiter_routine, waiter))
		return (0);
	return (1);
}

int	waiter_init(t_waiter *waiter, t_table table, t_menu *menu)
{
	waiter->table = table;
	waiter->alive = true;
	waiter->menu = menu;
	if (pthread_mutex_init(&waiter->philo_mx, NULL))
		return (0);
	return (1);
}

void	waiter_free(t_waiter *waiter)
{
	pthread_mutex_destroy(&waiter->philo_mx);
	free(waiter);
}
