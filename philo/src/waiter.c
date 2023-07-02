/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:29:42 by anvannin          #+#    #+#             */
/*   Updated: 2023/07/02 16:45:46 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*waiter_routine(void *arg)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)arg;
	i = 0;
	while (1)
	{
		if (i == philo->table->philo_count)
			i = 0;
		if (philo_starved(philo, i) || philo_satiated(philo, "waiter"))
			break ;
		i++;
	}
	return (NULL);
}

void	waiter_init(t_philo *philo)
{
	pthread_t	waiter;

	pthread_create(&waiter, NULL, waiter_routine, philo);
	pthread_join(waiter, NULL);
}
