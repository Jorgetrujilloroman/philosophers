/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:10:30 by jotrujil          #+#    #+#             */
/*   Updated: 2025/03/06 11:44:21 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* If the philosopher is first, their right fork is the last one;
otherwise, it's the previous fork, closing the circle. */
static void	assign_forks(t_philo *philo, pthread_mutex_t *forks,
	int i, int total_philos)
{
	philo->l_fork = &forks[i];
	if (i == 0)
		philo->r_fork = &forks[total_philos - 1];
	else
		philo->r_fork = &forks[i - 1];
}

void	init_philos(t_philo *philos, t_table *table,
	pthread_mutex_t *forks, char **argv)
{
	int	i;

	i = 0;
	while (i < argv[1])
	{
		philos[i].id = i + 1;
		philos[i].is_eating = 0;
		philos[i].times_eaten = 0;
		philos[i].total_philos = philo_atoi(argv[1]);
		if (argv[5])
			philos[i].must_eat_x_times = philo_atoi(argv[5]);
		else
			philos[i].must_eat_x_times = -1;
		philos[i].any_dead = &table->dead_flag;
		philos[i].start_time = get_current_time();
		philos[i].last_eat_time = get_current_time();
		philos[i].time_to_eat = philo_atoi(argv[3]);
		philos[i].time_to_sleep = philo_atoi(argv[4]);
		philos[i].time_to_die = philo_atoi(argv[2]);
		philos[i].dead_mutex = &table->dead_mutex;
		philos[i].food_mutex = &table->food_mutex;
		philos[i].write_mutex = &table->write_mutex;
		assign_forks(&philos[i], forks, i, philos[i].total_philos);
		i++;
	}
}

void	init_forks_mx(pthread_mutex_t *forks, int total_philos)
{
	int		i;

	i = 0;
	while (i < total_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

t_table	*serve_table(t_table *table, t_philo *philos)
{
	table->dead_flag = 0;
	table->philos = philos;
	pthread_mutex_init(&table->dead_mutex, NULL);
	pthread_mutex_init(&table->food_mutex, NULL);
	pthread_mutex_init(&table->write_mutex, NULL);
}
