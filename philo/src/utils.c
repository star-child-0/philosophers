/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:47:51 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/20 20:15:07 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_table(t_table *table)
{
	printf("%sphilo_count: %s%d\n", BLUE, UNSET, table->philo_count);
	printf("%stime_to_die: %s%d\n", BLUE, UNSET, table->time_to_die);
	printf("%stime_to_eat: %s%d\n", BLUE, UNSET, table->time_to_eat);
	printf("%stime_to_sleep: %s%d\n", BLUE, UNSET, table->time_to_sleep);
	printf("%stimes_to_eat: %s%d\n", BLUE, UNSET, table->times_to_eat);
}

int	arg_check(int ac, char **av)
{
	int	i;

	if (ac < 5 || ac > 6)
	{
		printf("%sError: wrong number of arguments\n", RED);
		printf("Usage: ./philo number_of_philosopher time_to_die time_to_eat ");
		printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		printf("Example: ./philo 4 410 200 200 [5]%s\n", UNSET);
		return (1);
	}
	i = 0;
	while (++i < ac)
		if (ft_atoi(av[i]) < 0)
			return (printf("%sError: Each argument must be a positive \
				number%s\n", RED, UNSET));
	return (0);
}

void	bombfreeall(t_philo **philos, t_fork **forks, t_waiter *waiter)
{
	int	i;

	i = 0;
	while (i < waiter->table.philo_count)
	{
		pthread_mutex_destroy(&(*forks)[i].fork_mx);
		i++;
	}
	pthread_mutex_destroy(&waiter->print_mx);
	pthread_mutex_destroy(&waiter->death_mx);
	pthread_mutex_destroy(&waiter->philo_mx);
	free(*philos);
	free(*forks);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}