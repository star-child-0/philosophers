/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:41:24 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/18 20:13:56 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;
	t_philo	**philos;

	if (argc != 5 && argc != 6)
		return (usage_msg());

	// table_init();
	// philo_init();

	printf("number_of_philosopher: %s\n", argv[1]);
	printf("time_to_die: %s\n", argv[2]);
	printf("time_to_eat: %s\n", argv[3]);
	printf("time_to_sleep: %s\n", argv[4]);
	if (argc == 6)
		printf("number_of_times_each_philosopher_must_eat: %s\n", argv[5]);
	return (0);
}
