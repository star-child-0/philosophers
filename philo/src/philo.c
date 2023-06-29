/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:07:17 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/29 20:59:40 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, char *color, char *action)
{
	pthread_mutex_lock((*philo).menu->print_mx);
	printf("%s[%ld] %d %s%s\n", color, ft_timer((*philo).last_eat,
			(*philo).menu->time_mx), philo->id, action, UNSET);
	pthread_mutex_unlock((*philo).menu->print_mx);
}

int	philo_create_thread(int i, t_philo **philo)
{
	if (pthread_create(&(*philo)[i].thread, NULL, philo_routine,
		&(*philo)[i]))
		return (0);
	return (1);
}

bool	philo_alive_check(t_philo *philo)
{
	pthread_mutex_lock(philo->menu->death_mx);
	if (!philo->menu->alive)
	{
		pthread_mutex_unlock(philo->menu->death_mx);
		return (false);
	}
	pthread_mutex_unlock(philo->menu->death_mx);
	return (true);
}

bool	philo_satiated(t_philo *philo)
{
	if (philo->table->times_to_eat == TILLDEATH)
		return (false);
	philo->times_eaten++;
	if (philo->times_eaten == philo->table->times_to_eat)
		return (true);
	return (false);
}

int	philo_init(t_philo **philo, t_menu *menu, t_fork **forks, t_table *table)
{
	int	i;

	i = -1;
	*philo = malloc(sizeof(t_philo) * table->philo_count);
	*forks = malloc(sizeof(t_fork) * table->philo_count);
	if (!*philo || !*forks)
		return (0);
	forks_init(forks, table);
	while (++i < table->philo_count)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].last_eat = ft_gettime();
		(*philo)[i].time_delay = (*philo)[i].last_eat;
		(*philo)[i].alive = true;
		(*philo)[i].times_eaten = 0;
		(*philo)[i].table = table;
		(*philo)[i].menu = menu;
		(*philo)[i].left_fork = &((*forks)[i]);
		if ((*philo)->id != table->philo_count)
			(*philo)[i].right_fork = &((*forks)[i + 1]);
		else
			(*philo)[i].right_fork = &((*forks)[0]);
	}
	return (1);
}
