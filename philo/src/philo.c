/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:07:17 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/27 19:50:12 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, char *color, char *action)
{
	pthread_mutex_lock((*philo).menu->print_mx);
	printf("%s[%ld] %d %s%s\n", color, ft_timer((*philo).start_time,
			(*philo).menu->time_mx), philo->id, action, UNSET);
	pthread_mutex_unlock((*philo).menu->print_mx);
}

int	philo_init(t_waiter *waiter, t_philo **philo, t_menu *menu, t_fork **forks)
{
	int	i;

	i = -1;
	*philo = malloc(sizeof(t_philo) * waiter->table.philo_count);
	*forks = malloc(sizeof(t_fork) * waiter->table.philo_count);
	if (!*philo || !*forks)
		return (0);

	forks_init(forks, waiter);

	while (++i < waiter->table.philo_count)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].last_eat = ft_gettime();
		(*philo)[i].time_delay = (*philo)[i].last_eat;
		(*philo)[i].start_time = (*philo)[i].last_eat;
		(*philo)[i].waiter = waiter;
		(*philo)[i].menu = menu;
		(*philo)[i].times_eaten = 0;

		(*philo)[i].left_fork = &((*forks)[i]);
		if ((*philo)->id != waiter->table.philo_count)
			(*philo)[i].right_fork = &((*forks)[i + 1]);
		else
			(*philo)[i].right_fork = &((*forks)[0]);
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
