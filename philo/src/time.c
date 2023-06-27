/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:11:22 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/27 11:48:12 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*!
* @brief
	Get the current timestamp.
* @return
	The current timestamp.
*/
time_t	ft_gettime(void)
{
	struct timeval		time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/*!
* @brief
	Get the time elapsed since the last timestamp.
* @param last_eat
	The last eat timestamp.
* @param time_mx
	The mutex to lock the time.
* @return
	The time elapsed since the last timestamp.
*/
time_t	ft_timer(time_t last_time, pthread_mutex_t *time_mx)
{
	time_t	elapsed;

	pthread_mutex_lock(time_mx);
	elapsed = ft_gettime();
	pthread_mutex_unlock(time_mx);
	return (elapsed - last_time);
}
