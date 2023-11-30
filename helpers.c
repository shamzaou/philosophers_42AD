/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:05:32 by shamzaou          #+#    #+#             */
/*   Updated: 2023/12/01 02:57:16 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_handler(int error_code)
{
	if (error_code == 1)
	{
		return (printf("Usage: number_of_philosophers time_to_die time_to_eat "
				"time_to_sleep [number_of_times_each_philosopher_must_eat]\n"));
	}
	else if (error_code == 2)
	{
		return (printf("Error: Simulation failed!\n"));
	}
	else if (error_code == 3)
	{
		return (printf("Error: Program initialisation failed!\n"));
	}
	else
		return (0);
}

int	join_threads(t_rules *rules, pthread_t monitor_thread)
{
	t_philosopher	*philosophers;
	int				id;

	philosophers = rules->philosophers;
	id = 0;
	while (id < rules->nbr_philo)
	{
		if (pthread_join(philosophers[id].thread_id, NULL))
			return (EXIT_FAILURE);
		id++;
	}
	if (pthread_join(monitor_thread, NULL))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

bool	check_all_ate(t_rules *rules)
{
	int	i;

	i = -1;
	while (rules->max_meals != -1 && ++i < rules->nbr_philo
		&& rules->philosophers[i].times_eaten >= rules->max_meals)
		;
	return (i == rules->nbr_philo);
}
