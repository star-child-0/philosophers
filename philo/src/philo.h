/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:41:42 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/20 20:14:45 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define UNSET "\033[0m"

typedef struct s_fork
{
	pthread_mutex_t	fork_mx;
}t_fork;

typedef struct s_table
{
	int		philo_count;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		times_to_eat;
}t_table;

typedef struct s_waiter
{
	t_table			table;
	int				safe;
	pthread_t		waiter;
	pthread_mutex_t	print_mx;
	pthread_mutex_t	death_mx;
	pthread_mutex_t	philo_mx;
}t_waiter;

typedef struct s_philo
{
	int		index;
	int		times_eaten;
	int		pid;
	t_table	*table;
}t_philo;

// UTILS ---------------------------------------------------------------->
int		arg_check(int ac, char **av);
void	bombfreeall(t_philo **philos, t_fork **forks, t_waiter *waiter);
int		ft_atoi(char *str);
void	print_table(t_table *table);

// PHILO ---------------------------------------------------------------------->
int		philo_init(t_waiter *waiter, t_philo **philos, t_fork **forks);

// TABLE ---------------------------------------------------------------------->
void	table_init(t_table *table, char **argv);

// WAITER --------------------------------------------------------------------->
int		waiter_init(t_waiter *waiter, t_table table);

#endif
