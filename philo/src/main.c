/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:41:24 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/20 21:38:25 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table		table;
	t_waiter	waiter;
	t_philo		*philos;
	t_fork		*forks;

	if (arg_check(argc, argv))
		return (0);
	table_init(&table, argv);
	if (!waiter_init(&waiter, table))
		return (printf("%sError: Waiter not found (Mutex)%s\n", REDBOLD, UNSET));
	if (!philo_init(&waiter, &philos, &forks))
		return (printf("%sError: Philo not found (Thread)%s\n", REDBOLD, UNSET));
	create_threads(&waiter, &philos);
	bombfreeall(&philos, &forks, &waiter);
	return (0);
}
