/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:41:42 by anvannin          #+#    #+#             */
/*   Updated: 2023/06/27 19:38:28 by anvannin         ###   ########.fr       */
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
# define MAGENTA "\033[0;35m"
# define MAGENTABOLD "\033[1;35m"
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
	int	philo_count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_to_eat;
}t_table;

typedef struct s_menu
{
	pthread_mutex_t	*death_mx;
	pthread_mutex_t	*time_mx;
	pthread_mutex_t	*print_mx;
	pthread_mutex_t	*eat_mx;
	pthread_mutex_t	*last_eat_mx;
}t_menu;

typedef struct s_waiter
{
	t_table			table;
	t_menu			*menu;
	bool			alive;
	pthread_t		waiter;
	pthread_mutex_t	philo_mx;
}t_waiter;

typedef struct s_philo
{
	int			id;
	int			times_eaten;
	time_t		last_eat;
	time_t		time_delay;
	time_t		start_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_waiter	*waiter;
	t_menu		*menu;
	pthread_t	thread;
}t_philo;

// UTILS ---------------------------------------------------------------------->
int			arg_check(int ac, char **av);
int			ft_atoi(char *str);
void		bombfreeall(t_philo **philo, t_fork **forks, t_waiter *waiter,
				t_menu **menu);

// TIME ----------------------------------------------------------------------->
time_t		ft_gettime(void);
time_t		ft_timer(time_t start_time, pthread_mutex_t *time_mx);

// THREADS -------------------------------------------------------------------->
void		threads_create(t_waiter *waiter, t_philo **philos);
void		threads_join(t_waiter *waiter, t_philo **philos);

// PHILO ---------------------------------------------------------------------->
int			philo_create_thread(int i, t_philo **philo);
void		philo_print(t_philo *philo, char *color, char *action);
int			philo_init(t_waiter *waiter, t_philo **philo, t_menu *menu,
				t_fork **forks);

// PHILO ROUTINE -------------------------------------------------------------->
void		*philo_routine(void *arg);

// MENU ----------------------------------------------------------------------->
t_menu		*menu_init(t_menu *menu);
void		menu_free(t_menu *menu);

// FORKS ---------------------------------------------------------------------->
void		forks_init(t_fork **forks, t_waiter *waiter);
void		forks_free(t_fork **forks, t_waiter *waiter);

// TABLE ---------------------------------------------------------------------->
void		table_init(t_table *table, char **argv);
void		print_table(t_table *table);

// WAITER --------------------------------------------------------------------->
int			waiter_init(t_waiter *waiter, t_table table, t_menu *menu);
int			waiter_create_thread(t_waiter *waiter);
void		waiter_free(t_waiter *waiter);

#endif
