/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:41:42 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/24 17:52:09 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

# define TILLDEATH -1

# define RED "\033[0;31m"
# define REDBOLD "\033[1;31m"
# define GREEN "\033[0;32m"
# define GREENBOLD "\033[1;32m"
# define YELLOW "\033[0;33m"
# define YELLOWBOLD "\033[1;33m"
# define BLUE "\033[0;34m"
# define BLUEBOLD "\033[1;34m"
# define UNSET "\033[0m"
# define BOLD "\033[1m"
# define UNDERLINE "\033[4m"
# define ITALIC "\033[3m"

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
	int				alive;
	pthread_t		waiter;
	pthread_mutex_t	print_mx;
	pthread_mutex_t	death_mx;
	pthread_mutex_t	philo_mx;
}t_waiter;

typedef struct s_philo
{
	int			id;
	int			times_eaten;
	int			last_eat;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_waiter	*waiter;
	pthread_t	thread;
}t_philo;

// UTILS ---------------------------------------------------------------------->
int					arg_check(int ac, char **av);
int					ft_atoi(char *str);
void				bombfreeall(t_philo **philos, t_fork **forks,
						t_waiter *waiter);

// TIME ----------------------------------------------------------------------->
unsigned long long	ft_gettime(void);
int					timer(unsigned long long time, int last_eat);

// THREADS -------------------------------------------------------------------->
void				threads_create(t_waiter *waiter, t_philo **philos);
void				threads_end(t_waiter *waiter, t_philo **philos);

// PHILO ---------------------------------------------------------------------->
int					philo_init(t_waiter *waiter, t_philo **philos,
						t_fork **forks);
int					philo_create_thread(int i, t_philo **philo);

// TABLE ---------------------------------------------------------------------->
void				table_init(t_table *table, char **argv);
void				print_table(t_table *table);

// WAITER --------------------------------------------------------------------->
int					waiter_init(t_waiter *waiter, t_table table);
int					waiter_create_thread(t_waiter *waiter);

#endif
