/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:28:30 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/27 19:21:14 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_sleep_and_think(t_philo *philo)
{
	philo_print(philo, BLUE, "is sleeping");
	usleep(philo->waiter->table.time_to_sleep * 1000);
	philo_print(philo, GREEN, "is thinking");
}

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->fork_mx);
	philo_print(philo, YELLOW, "has taken the left fork");

	pthread_mutex_lock(&(philo->right_fork->fork_mx));
	philo_print(philo, YELLOW, "has taken the right fork");

	philo_print(philo, MAGENTA, "is eating");

	pthread_mutex_lock((*philo).menu->last_eat_mx);
	// printf("%ld\n", ft_timer(ft_gettime(), (*philo).menu->time_mx));
	philo->time_delay = philo->last_eat;
	philo->last_eat = ft_gettime();
	pthread_mutex_unlock((*philo).menu->last_eat_mx);
	usleep(philo->waiter->table.time_to_eat * 1000);

	if (philo->waiter->table.times_to_eat != TILLDEATH)
		philo->times_eaten++;

	pthread_mutex_unlock(&philo->left_fork->fork_mx);
	pthread_mutex_unlock(&philo->right_fork->fork_mx);
}

static void	philo_dead(t_philo *philo)
{
	pthread_mutex_lock((*philo).menu->death_mx);
	(*philo).waiter->alive = 0;
	philo_print(philo, RED, "died");
	pthread_mutex_unlock((*philo).menu->death_mx);
	philo->waiter->alive = false;
}

bool	am_i_alive(t_philo *philo)
{
	// pthread_mutex_lock((*philo).menu->last_eat_mx);
	// printf("time to eat: %d\n", philo->waiter->table.time_to_eat);
	// printf("last_eat: %d\n", philo->last_eat);
	// printf("time_delay: %d\n", philo->time_delay);
	// pthread_mutex_unlock((*philo).menu->last_eat_mx);
	if (philo->waiter->table.time_to_eat < philo->last_eat - philo->time_delay)
		return (false);
	return (true);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(philo->waiter->table.time_to_eat * 1000);
	usleep(50);
	while (true)
	{
		if (philo->times_eaten == philo->waiter->table.times_to_eat)
			break ;
		if (!am_i_alive(philo) || !philo->waiter->alive)
		{
			philo_dead(philo);
			break ;
		}
		else if (philo->times_eaten == philo->waiter->table.times_to_eat)
			break ;
		philo_eat(philo);
		philo_sleep_and_think(philo);
	}
	return (NULL);
}
