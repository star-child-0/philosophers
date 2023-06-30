/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:41:24 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/30 21:43:56 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table		*table;
	t_philo		*philo;
	t_menu		*menu;

	table = NULL;
	philo = NULL;
	menu = NULL;
	if (arg_check(argc, argv))
		return (0);
	table = table_init(argv);
	menu = menu_init(menu);
	philo = philo_init(table, menu, argv);
	threads_init(philo);
	bombfreeall(philo);
	return (0);
}
