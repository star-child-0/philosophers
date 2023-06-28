/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:29:42 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/28 21:26:28 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*waiter_routine(void *arg)
{
	int		i;
	time_t	die_time;
	time_t	diff;
	t_philo	*waiter;

	waiter = (t_philo *)arg;
	i = -1;
	die_time = waiter->table->time_to_die;
	while (++i)
	{
		if (i == waiter->table->philo_count)
			i = 0;
		pthread_mutex_lock(waiter[i].menu->last_eat_mx);
		diff = ft_timer(waiter[i].last_eat, waiter[i].menu->time_mx);
		pthread_mutex_unlock(waiter[i].menu->last_eat_mx);
		if (diff > die_time)
		{
			philo_dead(&waiter[i]);
			break ;
		}
		if (philo_satiated(&waiter[i]))
			break ;
	}
	return (NULL);
}
