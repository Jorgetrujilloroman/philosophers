/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:04:19 by jotrujil          #+#    #+#             */
/*   Updated: 2025/03/06 11:36:55 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
