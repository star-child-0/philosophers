/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:28:30 by anvannin          #+#    #+#             */
/*   Updated: 2023/07/03 16:06:49 by anvannin         ###   ########.fr       */
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

static bool	philo_eat(t_philo *philo)
{
	if (!philo_alive(philo))
		return (false);
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

void	philo_die(t_philo *philo)
{
	bool	alive;

	pthread_mutex_lock(philo->menu->death_mx);
	pthread_mutex_lock(philo->menu->print_mx);
	alive = *philo->alive;
	if (alive)
		printf("%s[%ld] %d %s%s\n", RED, ft_timer(philo->simulation_start,
				(*philo).menu->time_mx), philo->id + 1, "died", UNSET);
	*philo->alive = false;
	pthread_mutex_unlock(philo->menu->print_mx);
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
