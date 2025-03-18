/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:04:19 by jotrujil          #+#    #+#             */
/*   Updated: 2025/03/18 15:13:20 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	improved_usleep(size_t millis)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < millis)
		usleep(500);
	return (0);
}

int	dead_checker(t_philo *philo)
{
	int	is_dead;

	pthread_mutex_lock(philo->dead_mutex);
	is_dead = (*philo->dead_or_end == 1);
	pthread_mutex_unlock(philo->dead_mutex);
	return (is_dead);
}

void	lock_and_print(t_philo *philo, char *msg)
{
	size_t	time;

	pthread_mutex_lock(philo->write_mutex);
	time = get_current_time() - philo->start_time;
	if (!dead_checker(philo))
		printf("%zu ms: Philo number %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->write_mutex);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("Error when getting time. Time set as 0\n");
		return (0);
	}
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	philo_atoi(char *str)
{
	int			i;
	long long	nbr;

	i = 0;
	nbr = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (nbr > INT_MAX)
		return (-1);
	else
		return ((int)nbr);
}
