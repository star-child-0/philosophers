/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:08:31 by anvannin          #+#    #+#             */
/*   Updated: 2023/07/02 16:18:25 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	table_print(t_table *table)
{
	printf("%sphilo_count:\t%s%d\n", BLUEBOLD, UNSET, table->philo_count);
	printf("%stime_to_die:\t%s%d\n", BLUEBOLD, UNSET, table->time_to_die);
	printf("%stime_to_eat:\t%s%d\n", BLUEBOLD, UNSET, table->time_to_eat);
	printf("%stime_to_sleep:\t%s%d\n", BLUEBOLD, UNSET, table->time_to_sleep);
	if (table->times_to_eat == TILLDEATH)
		printf("%stimes_to_eat:\t%sTILLDEATH\n", BLUEBOLD, UNSET);
	else
		printf("%stimes_to_eat:\t%s%d\n", BLUEBOLD, UNSET, table->times_to_eat);
}

t_table	*table_init(char **av)
{
	t_table	*table;

	table = malloc(sizeof(t_table) * 1);
	table->philo_count = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]) * 1000;
	table->time_to_eat = ft_atoi(av[3]) * 1000;
	table->time_to_sleep = ft_atoi(av[4]) * 1000;
	table->times_to_eat = TILLDEATH;
	if (av[5] && ft_atoi(av[5]) > 0)
		table->times_to_eat = ft_atoi(av[5]);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_count);
	return (table);
}
