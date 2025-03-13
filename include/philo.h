/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:36:37 by jotrujil          #+#    #+#             */
/*   Updated: 2025/03/13 11:07:43 by jotrujil         ###   ########.fr       */
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
	int				dishes_eaten;
	int				total_philos;
	int				must_eat_x_times;
	int				*dead_or_end;
	size_t			start_time;
	size_t			last_eat_time;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			time_to_die;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*dead_mutex;
	pthread_mutex_t	*food_mutex;
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

/* UTILS */

// Converts a positive str to int
int		philo_atoi(char *str);
// Gets the current system time in milliseconds. Return 0 if fail.
size_t	get_current_time(void);
// Locks the write mutex and prints the time, philo id and a custom message.
void	lock_and_print(t_philo *philo, char *msg);
// Checks if a philo dead or end flag is up. 
int		dead_checker(t_philo *philo);

/* INIT */

// "Serves" the table: Init the flag, philos and some of the mutexes
t_table	*serve_table(t_table *table, t_philo *philos);
// Initialize all the forks mutexes
void	init_forks_mx(pthread_mutex_t *forks, int n_philos);
// Initialize all philosophers & assign their forks
void	init_philos(t_philo *philos, t_table *table,
			pthread_mutex_t *forks, char **argv);

/* THREADS */

// Create all the threads for each philo and a "camera" thread for monitoring
void	create_all_threads(t_table *table, pthread_mutex_t *forks);
// Destroy all the mutexes & forks. Prints a message if first parameter exists.
void	destroy_all_mutexes(char *msg, t_table *table, pthread_mutex_t *forks);

/* MONITOR */

// Check if every philo has eaten the specified n of times. Returns 0 if not.
int		has_everyone_eaten(t_philo *philos);
// Check if any philo has dead and writes the time and philo ID if it has.
int		has_anyone_dead(t_philo	*philos);
#endif