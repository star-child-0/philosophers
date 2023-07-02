/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:13:33 by anvannin          #+#    #+#             */
/*   Updated: 2023/07/02 17:14:35 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_alive(t_philo *philo)
{
	pthread_mutex_lock(philo->menu->death_mx);
	if (*(philo->alive) == false)
	{
		pthread_mutex_unlock(philo->menu->death_mx);
		return (false);
	}
	pthread_mutex_unlock(philo->menu->death_mx);
	return (true);
}

bool	philo_satiated(t_philo *philo, char *who)
{
	pthread_mutex_lock(philo->menu->eat_mx);
	if (philo->left_to_eat == TILLDEATH)
	{
		pthread_mutex_unlock(philo->menu->eat_mx);
		return (false);
	}
	if (!ft_strncmp(who, "philo", 5))
		philo->left_to_eat -= 1;
	if (philo->left_to_eat == 0)
	{
		philo_print(philo, CYAN, "is full");
		pthread_mutex_unlock(philo->menu->eat_mx);
		return (true);
	}
	pthread_mutex_unlock(philo->menu->eat_mx);
	return (false);
}

bool	philo_starved(t_philo *philo, int i)
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

bool	philo_solo(t_philo *philo)
{
	if (philo->left_fork == philo->right_fork)
	{
		pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
		philo_print(philo, YELLOW, "has taken the right fork");
		usleep(philo->table->time_to_die);
		pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
		philo_die(philo);
		return (true);
	}
	return (false);
}
