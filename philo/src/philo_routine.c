/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:28:30 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/30 21:43:43 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_sleep_and_think(t_philo *philo)
{
	philo_print(philo, GREEN, "is sleeping");
	usleep(philo->table->time_to_sleep);
	philo_print(philo, BLUE, "is thinking");
}

static void	philo_take_forks(t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &philo->table->forks[philo->left_fork];
	right_fork = &philo->table->forks[philo->right_fork];
	pthread_mutex_lock(left_fork);
	philo_print(philo, YELLOW, "has taken the left fork");
	pthread_mutex_lock(right_fork);
	philo_print(philo, YELLOW, "has taken the right fork");
}

int	philo_eat(t_philo *philo)
{
	if (philo->left_fork == philo->right_fork)
	{
		pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
		philo_print(philo, YELLOW, "has taken the right fork");
		pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
		return (1);
	}
	philo_take_forks(philo);
	philo_print(philo, MAGENTA, "is eating");
	pthread_mutex_lock(philo->menu->last_eat_mx);
	philo->last_eat_mx = ft_gettime();
	pthread_mutex_unlock(philo->menu->last_eat_mx);
	usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
	if (philo->table->times_to_eat > 0)
		return (philo_satiated(philo));
	return (0);
}

void	philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->menu->death_mx);
	*philo->alive = false;
	philo_print(philo, RED, "has died");
	pthread_mutex_unlock(philo->menu->death_mx);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo->id % 2)
		usleep(50);
	usleep(50);
	while (!philo_alive(philo))
	{
		if (philo_eat(philo))
			break ;
		philo_sleep_and_think(philo);
	}
	return (NULL);
}
