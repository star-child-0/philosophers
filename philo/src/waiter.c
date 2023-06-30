/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:29:42 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/30 21:46:13 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	waiter_philo_times_eaten(t_philo *philo)
{
	int	full;
	int	i;

	i = -1;
	full = 0;
	pthread_mutex_lock(philo->menu->eat_mx);
	while (++i < philo->table->philo_count)
	{
		if (philo[i].left_to_eat == 0)
			full++;
	}
	pthread_mutex_unlock(philo->menu->eat_mx);
	if (full == philo->table->philo_count)
		return (true);
	return (false);
}

static int	starvation(t_philo *philo, int i)
{
	time_t	diff;
	time_t	die_time;

	die_time = philo->table->time_to_die / 1000;
	pthread_mutex_lock(philo[i].menu->last_eat_mx);
	diff = ft_timer(philo[i].last_eat_mx, philo[i].menu->time_mx);
	pthread_mutex_unlock(philo[i].menu->last_eat_mx);
	if (diff > die_time)
	{
		philo_dead(&philo[i]);
		return (1);
	}
	return (0);
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
		if (starvation(philo, i))
			break ;
		if (philo->table->times_to_eat != TILLDEATH
			&& waiter_philo_times_eaten(philo))
			break ;
		i++;
	}
	return (NULL);
}

void	waiter_init(t_philo *philo)
{
	pthread_t	waiter;

	pthread_create(&waiter, NULL, waiter_routine, philo);
	pthread_join(waiter, NULL);
}
