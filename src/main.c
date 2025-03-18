/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:45:26 by jotrujil          #+#    #+#             */
/*   Updated: 2025/03/18 19:00:47 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_table			table;
	t_philo			philos[MAX_PHILOS];
	pthread_mutex_t	forks[MAX_PHILOS];

	if (args_check(argc, argv))
		return (1);
	serve_table(&table, philos);
	init_forks_mx(forks, philo_atoi(argv[1]));
	init_philos(philos, &table, forks, argv);
	create_all_threads(&table, forks);
	destroy_all_mutexes("The restaurant is closed 🔒\n", &table, forks);
	return (0);
}
