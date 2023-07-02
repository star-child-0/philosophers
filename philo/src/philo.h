/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:41:42 by anvannin          #+#    #+#             */
/*   Updated: 2023/07/02 16:08:58 by anvannin         ###   ########.fr       */
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

// COLOR MACROS --------------------------------------------------------------->
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define BLUEBOLD "\033[1;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define UNSET "\033[0m"
# define BOLD "\033[1m"

// PROJECT MACROS ------------------------------------------------------------->
# define TILLDEATH -1

// STRUCTURES ----------------------------------------------------------------->
typedef struct s_data
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
	pthread_mutex_t	*forks;
}	t_table;

typedef struct s_mutex
{
	pthread_mutex_t	*death_mx;
	pthread_mutex_t	*time_mx;
	pthread_mutex_t	*print_mx;
	pthread_mutex_t	*eat_mx;
	pthread_mutex_t	*last_eat_mx;
}	t_menu;

typedef struct s_philo
{
	int			id;
	int			left_fork;
	int			right_fork;
	int			left_to_eat;
	bool		*alive;
	time_t		last_eat;
	time_t		simulation_start;
	t_menu		*menu;
	t_table		*table;
	pthread_t	thread;
}	t_philo;

// UTILS ---------------------------------------------------------------------->
int			arg_check(int ac, char **av);
bool		ft_isdigit(int c);
int			ft_atoi(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		bombfreeall(t_philo *philo);

// TIME ----------------------------------------------------------------------->
time_t		ft_gettime(void);
time_t		ft_timer(time_t start_time, pthread_mutex_t *time_mx);

// THREADS -------------------------------------------------------------------->
void		threads_init(t_philo *philo);

// PHILO ---------------------------------------------------------------------->
t_philo		*philo_init(t_table *table, t_menu *menu, char **av);
int			philo_create_thread(int i, t_philo **philo);
void		philo_print(t_philo *philo, char *color, char *action);
bool		philo_alive(t_philo *philo);
int		philo_satiated(t_philo *philo, char *who);
bool		philo_starved(t_philo *philo, int i);

// PHILO ROUTINE -------------------------------------------------------------->
void		*philo_routine(void *arg);
void		philo_die(t_philo *philo);

// MENU ----------------------------------------------------------------------->
t_menu		*menu_init(t_menu *menu);
void		menu_free(t_menu *menu);

// TABLE ---------------------------------------------------------------------->
t_table		*table_init(char **av);
void		table_print(t_table *table);

// WAITER --------------------------------------------------------------------->
void		waiter_init(t_philo *philo);
void		*waiter_routine(void *arg);

#endif
