/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:08:31 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/28 20:21:37 by anvannin         ###   ########.fr       */
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

void	table_init(t_table *table, char **argv)
{
	table->philo_count = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->times_to_eat = ft_atoi(argv[5]);
	else
		table->times_to_eat = TILLDEATH;
}
