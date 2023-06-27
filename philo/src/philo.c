/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:07:17 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/27 13:11:47 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, char *color, char *action)
{
	time_t	timer;

	timer = ft_timer(philo->time_delay, (*philo).menu->time_mx);
	pthread_mutex_lock((*philo).menu->print_mx);
	printf("%s[%ld] %d %s%s\n", color, timer, philo->id, action, UNSET);
	pthread_mutex_unlock((*philo).menu->print_mx);
}

static void	philo_mutex_init(t_philo *philo, t_menu *menu)
{
	pthread_mutex_init(&philo->left_fork->fork_mx, NULL);
	pthread_mutex_init(&philo->right_fork->fork_mx, NULL);
	menu = malloc(sizeof(t_menu));
	philo->menu = menu;
	philo->menu->death_mx = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init((*philo).menu->death_mx, NULL);
	philo->menu->time_mx = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init((*philo).menu->time_mx, NULL);
	philo->menu->print_mx = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init((*philo).menu->print_mx, NULL);
	philo->menu->eat_mx = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init((*philo).menu->eat_mx, NULL);
	philo->menu->last_eat_mx = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init((*philo).menu->last_eat_mx, NULL);
}

int	philo_init(t_waiter *waiter, t_philo **philo, t_menu **menu, t_fork **forks)
{
	int	i;

	i = -1;
	*philo = malloc(sizeof(t_philo) * waiter->table.philo_count);
	*forks = malloc(sizeof(t_fork) * waiter->table.philo_count);
	if (!*philo || !*forks)
		return (0);
	while (++i < waiter->table.philo_count)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].last_eat = ft_gettime();
		(*philo)[i].time_delay = (*philo)[i].last_eat;
		(*philo)[i].waiter = waiter;
		if (waiter->table.times_to_eat == TILLDEATH)
			(*philo)[i].times_eaten = -1;
		else
			(*philo)[i].times_eaten = 0;
		(*philo)[i].left_fork = &((*forks)[i]);
		if ((*philo)->id != waiter->table.philo_count)
			(*philo)[i].right_fork = &((*forks)[i + 1]);
		else
			(*philo)[i].right_fork = &((*forks)[0]);
		philo_mutex_init(&(*philo)[i], &(*menu)[i]);
	}
	return (1);
}

int	philo_create_thread(int i, t_philo **philo)
{
	if (pthread_create(&(*philo)[i].thread, NULL, philo_routine,
		&(*philo)[i]))
		return (0);
	return (1);
}
