/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:29:42 by anvannin          #+#    #+#             */
/*   Updated: 2023/07/01 17:42:24 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_starved(t_philo *philo, int i)
{
	time_t	diff;
	time_t	die_time;

	die_time = philo->table->time_to_die / 1000;
	pthread_mutex_lock(philo[i].menu->last_eat_mx);
	diff = ft_timer(philo[i].last_eat, philo[i].menu->time_mx);
	pthread_mutex_unlock(philo[i].menu->last_eat_mx);
	if (diff > die_time)
	{
		philo_die(&philo[i]);
		return (true);
	}
	return (false);
}

void	*waiter_routine(void *arg)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)arg;
	i = 0;
	while (1)
	{
		if (i == philo->table->philo_count)
			i = 0;
		if (philo_starved(philo, i))
			break ;
		i++;
	}
	return (NULL);
	(void)philo;
	i++;
}

void	waiter_init(t_philo *philo)
{
	pthread_t	waiter;

	pthread_create(&waiter, NULL, waiter_routine, philo);
	pthread_join(waiter, NULL);
}
