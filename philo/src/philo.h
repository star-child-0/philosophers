/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:41:42 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/18 20:13:22 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_philo
{
	int		index;
	int		times_eaten;
	int		pid;
	t_table	*table;
}t_philo;

typedef struct s_table
{
	int		philo_count;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		times_to_eat;
	t_philo	**philos;
}t_table;


// FROM LIBFT ---------------------------------------------------------------->
int	ft_strlen(const char *str);

// PHILO ---------------------------------------------------------------------->
void	philo_init();

// TABLE ---------------------------------------------------------------------->
void	table_init();


int	usage_msg(void);

#endif
