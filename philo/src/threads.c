/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:54:03 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/30 21:38:41 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	threads_join(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->table->philo_count)
		pthread_join(philo[i].thread, NULL);
}

void	threads_init(t_philo *philo)
{
	int			i;
	bool		alive;

	i = -1;
	alive = false;
	while (++i < philo->table->philo_count)
	{
		philo[i].time_delay = ft_gettime();
		philo[i].last_eat_mx = philo[i].time_delay;
		philo[i].alive = &alive;
		pthread_create(&philo[i].thread, NULL, philo_routine, &philo[i]);
	}
	waiter_init(philo);
	threads_join(philo);
}
