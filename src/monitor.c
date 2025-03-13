/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:57:09 by jotrujil          #+#    #+#             */
/*   Updated: 2025/03/13 12:25:26 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	has_anyone_dead(t_philo	*philos)
{
	int		i;
	size_t	current_time;

	i = 0;
	while (i < philos[0].total_philos)
	{
		pthread_mutex_lock(philos[i].food_mutex);
		current_time = get_current_time();
		if (current_time - philos[i].last_eat_time >= philos[i].time_to_die)
		{
			pthread_mutex_unlock(philos[i].food_mutex);
			lock_and_print(&philos[i], "has died");
			pthread_mutex_lock(philos[0].dead_mutex);
			*philos->dead_or_end = 1;
			pthread_mutex_unlock(philos[0].dead_mutex);
			return (1);
		}
		pthread_mutex_unlock(philos[i].food_mutex);
		i++;
	}
	return (0);
}

int	has_everyone_eaten(t_philo *philos)
{
	int	i;
	int	has_eaten;

	i = 0;
	has_eaten = 0;
	if (philos[0].must_eat_x_times == -1)
		return (0);
	while (i < philos[0].total_philos)
	{
		pthread_mutex_lock(philos[i].food_mutex);
		if (philos[i].dishes_eaten >= philos[i].must_eat_x_times)
			has_eaten++;
		pthread_mutex_unlock(philos[i].food_mutex);
		i++;
	}
	if (has_eaten == philos[0].must_eat_x_times)
	{
		pthread_mutex_lock(philos[0].dead_mutex);
		*philos->dead_or_end = 1;
		pthread_mutex_unlock(philos[0].dead_mutex);
		return (1);
	}
	return (0);
}
