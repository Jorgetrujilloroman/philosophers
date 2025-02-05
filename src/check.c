/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:36:14 by jotrujil          #+#    #+#             */
/*   Updated: 2025/02/05 21:16:59 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Return 0 if all args are numbers. Return 1 if not */
static int	digit_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
			{
				j++;
				continue ;
			}
			if (av[i][j] < 48 || av[i][j] > 57)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	args_check(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf ("Invalid number of args. Use the following format:\n./philo ");
		printf ("n_philos time_to_die time_to_eat time_to_zzz [n_each_eat]\n");
		return (1);
	}
	if (digit_check(av))
	{
		printf ("Invalid input: All arguments must be numbers\n");
		return (1);
	}
	return (0);
}
