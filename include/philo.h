/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:36:37 by jotrujil          #+#    #+#             */
/*   Updated: 2025/02/27 22:02:59 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# ifndef MAX_PHILOS
#  define MAX_PHILOS 420
# endif

typedef struct s_philo
{
	int				id;
	int				is_eating;
	int				times_eaten;
	int				total_philos;
	int				must_eat_x_times;
	int				*any_dead;
	size_t			start_time;
	size_t			last_eat_time;
	size_t			time_to_eat;
	size_t			time_to_sleep
	size_t			time_to_die;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*dead_mutex;
	pthread_mutex_t	food_mutex;
	pthread_mutex_t	*write_mutex;
}	t_philo;

typedef struct s_table
{
	int				dead_flag;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	food_mutex;
	pthread_mutex_t	write_mutex;
	t_philo			*philos;
}	t_table;

/* CHECKS */
// Check if all args are valid. Return 1 if not
int		args_check(int ac, char **av);
// Converts a positive str to int
int		philo_atoi(char *str);

/* INIT */
// "Serves" the table: Init the flag, philos and some of the mutexes
t_table	*serve_table(t_table *table, t_philo *philos);
// Initialize all the forks mutexes
void	init_forks_mx(pthread_mutex_t *forks, int n_philos)
// Initialize all philosophers & assign their forks
void	init_philos(t_philo *philos, t_table *table,
	pthread_mutex_t *forks, char **argv)

#endif