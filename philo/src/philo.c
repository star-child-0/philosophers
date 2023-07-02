/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:07:17 by anvannin          #+#    #+#             */
/*   Updated: 2023/07/02 18:23:23 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		if (i == 0)
			philo[i].left_fork = table->philo_count - 1;
		else
			philo[i].left_fork = i - 1;
		philo[i].id = i;
		philo[i].table = table;
		philo[i].menu = menu;
		if (philo[i].table->times_to_eat == TILLDEATH)
			philo[i].left_to_eat = TILLDEATH;
		else
			philo[i].left_to_eat = ft_atoi(av[5]);
	}
	return (philo);
}

int	philo_create_thread(int i, t_philo **philo)
{
	if (pthread_create(&(*philo)[i].thread, NULL, philo_routine,
		&(*philo)[i]))
		return (0);
	return (1);
}

void	philo_print(t_philo *philo, char *color, char *action)
{
	bool	alive;

	pthread_mutex_lock((*philo).menu->death_mx);
	alive = *philo->alive;
	pthread_mutex_unlock((*philo).menu->death_mx);
	pthread_mutex_lock((*philo).menu->print_mx);
	if (alive)
		printf("%s[%ld] %d %s%s\n", color, ft_timer(philo->simulation_start,
				(*philo).menu->time_mx), philo->id + 1, action, UNSET);
	pthread_mutex_unlock((*philo).menu->print_mx);
}
