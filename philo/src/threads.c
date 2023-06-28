/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:54:03 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/28 20:19:10 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threads_create(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->table->philo_count)
		pthread_create(&philo[i].thread, NULL, philo_routine, &philo[i]);
	pthread_create(&philo->thread, NULL, waiter_routine, philo);
}

void	threads_join(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->table->philo_count)
		pthread_join(philo[i].thread, NULL);
	pthread_join(philo->thread, NULL);
}
