/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:47:51 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/27 19:31:45 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (ft_atoi(av[1]) < 2)
		return (printf("%sError: There must be at least 2 philosophers%s\n"
				, RED, UNSET));
	i = 1;
	while (++i < ac)
	{
		if (ft_atoi(av[i]) <= 0)
		{
			printf("%sError: Each argument must be a number greater than 0%s\n",
				RED, UNSET);
			return (1);
		}
	}
	return (0);
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

void	bombfreeall(t_philo **philo, t_fork **forks, t_waiter *waiter, t_menu **menu)
{
	forks_free(forks, waiter);
	free(*philo);
	waiter_free(waiter);
	free(*menu);
	return ;
}
