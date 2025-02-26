/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:36:37 by jotrujil          #+#    #+#             */
/*   Updated: 2025/02/26 17:08:27 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <pthread.h>

# ifndef MAX_PHILOS
#  define MAX_PHILOS 420
# endif

typedef struct s_philo
{
	pthread_t		thread;
}	t_philo;

typedef struct s_table
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	dinner_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}	t_table;

/* CHECKS */
// Check if all args are valid. Return 1 if not
int		args_check(int ac, char **av);
// Converts a positive str to int
int		philo_atoi(char *str);

/* INIT */
// "Serves" the table: Init the flag, philos and initialice the mutexes
t_table	*serve_table(t_table *table, t_philo *philos);

#endif