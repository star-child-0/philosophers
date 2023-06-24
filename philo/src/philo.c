/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:07:17 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/24 18:42:14 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("%s [%d] philo %d created%s\n", BLUE, timer(ft_gettime(),
			philo->last_eat), philo->id, UNSET);
	usleep(50);
	return (NULL);
}

int	philo_create_thread(int i, t_philo **philo)
{
	if (pthread_create(&(*philo)[i].thread, NULL, philo_routine,
		&(*philo)[i]))
		return (0);
	return (1);
}

int	philo_init(t_waiter *waiter, t_philo **philos, t_fork **forks)
{
	int	i;

	i = 0;
	*philos = malloc(sizeof(t_philo) * waiter->table.philo_count);
	*forks = malloc(sizeof(t_fork) * waiter->table.philo_count);
	if (!*philos || !*forks)
		return (0);
	while (i < waiter->table.philo_count)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].last_eat = 0;
		(*philos)[i].times_eaten = 0;
		if (pthread_mutex_init(&(*forks)[i].fork_mx, NULL))
			return (0);
		i++;
	}
	return (1);
}
