/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:05:30 by shamzaou          #+#    #+#             */
/*   Updated: 2023/11/29 06:03:51 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int simulation(t_rules *rules)
{
    t_philosopher *philosophers;
    int id;

    philosophers = rules->philosophers;
    id = 0;
    rules->simulation_start = timestamp();
    while (id < rules->nbr_philo)
    {
        if (pthread_create(&(philosophers[id].thread_id), NULL, routine, &philosophers[id]));
            return(EXIT_FAILURE);
        philosophers[id].last_meal_time = timestamp();
        id++;
    }
    // Check monitor death
    // proper exit
    return (EXIT_SUCCESS);
}