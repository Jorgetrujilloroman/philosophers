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

t_table	*serve_table(t_table *table, t_philo *philos)
{
	table->dead_flag = 0;
	table->philos = philos;
	pthread_mutex_init(&table->dead_lock, NULL);
	pthread_mutex_init(&table->dinner_lock, NULL);
	pthread_mutex_init(&table->write_lock, NULL);
}
