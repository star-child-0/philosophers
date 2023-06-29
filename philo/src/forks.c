/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:00:31 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/29 20:55:55 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_init(t_fork **forks, t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_count)
		pthread_mutex_init(&(*forks)[i].fork_mx, NULL);
}

void	forks_free(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->table->philo_count)
		pthread_mutex_destroy(&philo->left_fork->fork_mx);
}
