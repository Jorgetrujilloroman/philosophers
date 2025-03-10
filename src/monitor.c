/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:57:09 by jotrujil          #+#    #+#             */
/*   Updated: 2025/03/10 13:50:40 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	has_anyone_dead(t_philo	*philos)
{
	
}

int	has_everyone_eaten(t_philo *philos)
{
	int	i;
	int	end_eat;

	i = 0;
	end_eat = 0;
	if (philos[0].must_eat_x_times == -1)
		return (0);
	while (i < philos[0].total_philos)
	{
		pthread_mutex_lock(philos[i].food_mutex);
		if (philos[i].dishes_eaten >= philos[i].must_eat_x_times)
			end_eat++;
		pthread_mutex_unlock(philos[i].food_mutex);
		i++;
	}
	if (end_eat == philos[0].must_eat_x_times)
	{
		pthread_mutex_lock(philos[0].dead_mutex);
		*philos->dead_or_end = 1;
		pthread_mutex_unlock(philos[0].dead_mutex);
		return (1);
	}
	return (0);
}