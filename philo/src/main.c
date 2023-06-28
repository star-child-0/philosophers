/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:41:24 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/28 20:22:37 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table		table;
	t_philo		*philo;
	t_menu		*menu;
	t_fork		*forks;

	if (arg_check(argc, argv))
		return (0);
	table_init(&table, argv);
	table_print(&table);
	menu = NULL;
	menu = menu_init(menu);
	if (!philo_init(&philo, menu, &forks, &table))
		return (printf("%sError: Philo not found (Thread)%s\n", REDBOLD, UNSET));
	threads_create(philo);
	threads_join(philo);
	bombfreeall(philo);
	return (0);
}
