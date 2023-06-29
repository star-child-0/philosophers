/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:28:30 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/29 21:01:23 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_sleep(t_philo *philo)
{
	static bool	i = true;

	if (!philo_alive_check(philo))
		i = 0;
	if (!i)
		return ;
	philo_print(philo, BLUE, "is sleeping");
	usleep(philo->table->time_to_sleep * 1000);
}

static void	philo_think(t_philo *philo)
{
	static bool	i = true;

	if (!philo_alive_check(philo))
		i = 0;
	if (!i)
		return ;
	philo_print(philo, GREEN, "is thinking");
}

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->fork_mx);
	philo_print(philo, YELLOW, "has taken the left fork");
	pthread_mutex_lock(&(philo->right_fork->fork_mx));
	philo_print(philo, YELLOW, "has taken the right fork");
	philo_print(philo, MAGENTA, "is eating");
	usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->left_fork->fork_mx);
	pthread_mutex_unlock(&philo->right_fork->fork_mx);
}

bool	philo_dead(t_philo *philo)
{
	pthread_mutex_lock((*philo).menu->death_mx);
	philo->alive = false;
	philo_print(philo, RED, "died");
	pthread_mutex_unlock((*philo).menu->death_mx);
	return (false);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(50);
	usleep(50);
	while (true)
	{
		if (!philo_alive_check(philo))
			break ;
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
