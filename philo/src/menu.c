/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:56:15 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/30 21:38:41 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_menu	*menu_init(t_menu *menu)
{
	menu = malloc(sizeof(t_menu) * 1);
	menu->death_mx = malloc(sizeof(pthread_mutex_t) * 1);
	menu->print_mx = malloc(sizeof(pthread_mutex_t) * 1);
	menu->time_mx = malloc(sizeof(pthread_mutex_t) * 1);
	menu->eat_mx = malloc(sizeof(pthread_mutex_t) * 1);
	menu->last_eat_mx = malloc(sizeof(pthread_mutex_t) * 1);
	pthread_mutex_init(menu->death_mx, NULL);
	pthread_mutex_init(menu->print_mx, NULL);
	pthread_mutex_init(menu->time_mx, NULL);
	pthread_mutex_init(menu->eat_mx, NULL);
	pthread_mutex_init(menu->last_eat_mx, NULL);
	return (menu);
}

void	menu_free(t_menu *menu)
{
	pthread_mutex_destroy(menu->death_mx);
	pthread_mutex_destroy(menu->time_mx);
	pthread_mutex_destroy(menu->print_mx);
	pthread_mutex_destroy(menu->eat_mx);
	pthread_mutex_destroy(menu->last_eat_mx);
	free(menu->death_mx);
	free(menu->time_mx);
	free(menu->print_mx);
	free(menu->eat_mx);
	free(menu->last_eat_mx);
	free(menu);
}
