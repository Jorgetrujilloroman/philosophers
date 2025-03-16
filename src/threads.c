/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:51:19 by jorge             #+#    #+#             */
/*   Updated: 2025/03/16 21:07:29 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Runs each philosopher thread. Loop eating, sleepint and thinking, 
until it is detected that some philosopher has died. */
static void	*philo_routine(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!dead_checker(philo))
	{
		eat(philo);
		deep_think(philo);
		take_nap(philo);
	}
	return (philo_arg);
}

/* Monitors the status of philos & terminates when any philo is dead 
or if every philo has eaten if this parameter has been specified*/
static void	*monitor_routine(void *all_philos)
{
	t_philo	*philos;

	philos = (t_philo *)all_philos;
	while (1)
		if (has_everyone_eaten(philos) == 1 || has_anyone_dead(philos) == 1)
			break ;
	return (all_philos);
}

void	destroy_all_mutexes(char *msg, t_table *table, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (msg)
		printf("%s\n", msg);
	pthread_mutex_destroy(&table->dead_mutex);
	pthread_mutex_destroy(&table->food_mutex);
	pthread_mutex_destroy(&table->write_mutex);
	while (i < table->philos[0].total_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	create_all_threads(t_table *table, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	camera;

	i = 0;
	if (pthread_create(&camera, NULL, &monitor_routine, table->philos) != 0)
		destroy_all_mutexes("Error when creating camera Thread", table, forks);
	while (i < table->philos[0].total_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &philo_routine,
				&table->philos[i]) != 0)
			destroy_all_mutexes("Error creating philo threads", table, forks);
		i++;
	}
	if (pthread_join(camera, NULL) != 0)
		destroy_all_mutexes("Error joining camera thread", table, forks);
	i = 0;
	while (i < table->philos[i].total_philos)
	{
		if (pthread_join(&table->philos[i].thread, NULL) != 0)
			destroy_all_mutexes("Error joining philo thread", table, forks);
		i++;
	}
}
