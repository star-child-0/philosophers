/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:07:17 by anvannin          #+#    #+#             */
/*   Updated: 2023/07/01 17:41:01 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, char *color, char *action)
{
	pthread_mutex_lock((*philo).menu->print_mx);
	printf("%s[%ld] %d %s%s\n", color, ft_timer(philo->simulation_start,
			(*philo).menu->time_mx), philo->id + 1, action, UNSET);
	pthread_mutex_unlock((*philo).menu->print_mx);
}

int	philo_create_thread(int i, t_philo **philo)
{
	if (pthread_create(&(*philo)[i].thread, NULL, philo_routine,
		&(*philo)[i]))
		return (0);
	return (1);
}

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

int	philo_satiated(t_philo *philo)
{
	pthread_mutex_lock(philo->menu->eat_mx);
	if (philo->left_to_eat == TILLDEATH)
	{
		pthread_mutex_unlock(philo->menu->eat_mx);
		return (false);
	}
	if (--philo->left_to_eat == 0)
	{
		philo_print(philo, YELLOW, "is full!");
		pthread_mutex_unlock(philo->menu->eat_mx);
		return (true);
	}
	pthread_mutex_unlock(philo->menu->eat_mx);
	return (false);
}

t_philo	*philo_init(t_table *table, t_menu *menu, char **av)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * table->philo_count);
	i = -1;
	while (++i < table->philo_count)
		pthread_mutex_init(&table->forks[i], NULL);
	i = -1;
	while (++i < table->philo_count)
	{
		philo[i].right_fork = i;
		if (i == table->philo_count - 1)
			philo[i].left_fork = 0;
		else
			philo[i].left_fork = i + 1;
		philo[i].id = i;
		philo[i].table = table;
		philo[i].menu = menu;
		if (philo[i].table->times_to_eat == true)
			philo[i].left_to_eat = ft_atoi(av[5]);
		else
			philo[i].left_to_eat = TILLDEATH;
	}
	return (philo);
}
