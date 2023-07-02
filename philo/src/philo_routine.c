/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:28:30 by anvannin          #+#    #+#             */
/*   Updated: 2023/07/02 16:11:14 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_sleep_and_think(t_philo *philo)
{
	if (!philo_alive(philo))
		return (false);
	philo_print(philo, GREEN, "is sleeping");
	usleep(philo->table->time_to_sleep);
	if (!philo_alive(philo))
		return (false);
	philo_print(philo, BLUE, "is thinking");
	return (true);
}

static void	philo_take_forks(t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &philo->table->forks[philo->left_fork];
	right_fork = &philo->table->forks[philo->right_fork];
	if (philo->id % 2)
		usleep(1000);
	if (left_fork < right_fork)
	{
		pthread_mutex_lock(left_fork);
		philo_print(philo, YELLOW, "has taken the left fork");
		pthread_mutex_lock(right_fork);
		philo_print(philo, YELLOW, "has taken the right fork");
	}
	else
	{
		pthread_mutex_lock(right_fork);
		philo_print(philo, YELLOW, "has taken the right fork");
		pthread_mutex_lock(left_fork);
		philo_print(philo, YELLOW, "has taken the left fork");
	}
}

bool	philo_eat(t_philo *philo)
{
	philo_take_forks(philo);
	philo_print(philo, MAGENTA, "is eating");
	pthread_mutex_lock(philo->menu->last_eat_mx);
	philo->last_eat = ft_gettime();
	pthread_mutex_unlock(philo->menu->last_eat_mx);
	usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
	return (!philo_satiated(philo, "philo"));
}

bool	philo_solo(t_philo *philo)
{
	if (philo->left_fork == philo->right_fork)
	{
		pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
		philo_print(philo, YELLOW, "has taken the right fork");
		pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
		return (true);
	}
	return (false);
}

void	philo_die(t_philo *philo)
{
	pthread_mutex_lock(philo->menu->death_mx);
	*philo->alive = false;
	printf("%d\n", philo->left_to_eat);
	philo_print(philo, RED, "has died");
	pthread_mutex_unlock(philo->menu->death_mx);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(1000);
	while (philo_alive(philo))
	{
		if (philo_solo(philo))
			break ;
		if (!philo_eat(philo))
			break ;
		if (!philo_sleep_and_think(philo))
			break ;
	}
	return (NULL);
}
