/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:10:30 by jotrujil          #+#    #+#             */
/*   Updated: 2025/02/26 17:12:14 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_philos(t_philo *philos, t_table *table,
	pthread_mutex_t *forks, char **argv)
{
	int	i;

	i = 0;
	while (i < argv[1])
	{
		philos[i]->id = i + 1;
		philos[i]->is_eating = 0;
		philos[i]->times_eaten = 0;
		philos[i]->total_philos = philo_atoi(philos_number);
		if (argv[5])
			philos[i]->must_eat_x_times = philo_atoi(argv[5]);
		else
			philos[i]->must_eat_x_times = -1;
		philos[i]->any_dead = &table->dead_flag;
		philos[i]->start_time = get_current_time(); //todo
		philos[i]->last_eat_time = get_current_time();
		
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
	pthread_mutex_init(&table->dinner_mutex, NULL);
	pthread_mutex_init(&table->write_mutex, NULL);
}
