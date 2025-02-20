/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:36:37 by jotrujil          #+#    #+#             */
/*   Updated: 2025/02/06 14:10:15 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <limits.h>

typedef struct s_table
{
	long	philo_id;
}	t_table;

/* CHECKS */

// Check if all args are valid. Return 1 if not
int	args_check(int ac, char **av);
// Converts a positive str to int
int	philo_atoi(char *str);

#endif