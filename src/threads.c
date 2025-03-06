/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:51:19 by jorge             #+#    #+#             */
/*   Updated: 2025/03/06 16:20:50 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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

	if (pthread_create(&camera, NULL, &monitor_routine, table->philos) != 0)
		destroy_all_mutexes("Error when creating camera Thread", table, forks); //TODO
}