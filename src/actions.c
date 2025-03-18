/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:07:59 by jotrujil          #+#    #+#             */
/*   Updated: 2025/03/18 15:04:41 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	take_nap(t_philo *philo)
{
	lock_and_print(philo, "is taking a nap: zZz");
	improved_usleep(philo->time_to_sleep);
}

void	deep_think(t_philo *philo)
{
	lock_and_print(philo, "is philosophizing about deep issues");
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	lock_and_print(philo, "took the right fork");
	if (philo->total_philos == 1)
	{
		improved_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	lock_and_print(philo, "took the left fork");
	philo->is_eating = 1;
	lock_and_print(philo, "is eating");
	pthread_mutex_lock(philo->food_mutex);
	philo->last_eat_time = get_current_time();
	philo->dishes_eaten++;
	pthread_mutex_unlock(philo->food_mutex);
	improved_usleep(philo->time_to_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
