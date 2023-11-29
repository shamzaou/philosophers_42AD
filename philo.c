/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:05:30 by shamzaou          #+#    #+#             */
/*   Updated: 2023/11/30 01:50:47 by shamzaou         ###   ########.fr       */
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

void routine(void *philo_ptr)
{
    t_philosopher   *philo;
    t_rules         *rules;

    philo = (t_philosopher *)philo_ptr;
    rules = philo->rules;
    if (!(philo->id % 2))
        usleep(10000);
        
    // while "condition" is useless with new plan
    while (!(rules->death))
    {
        eat(philo);
        if (rules->all_ate)
            break;

        event_print(rules, philo->id, "is sleeping");

        ft_usleep(rules->time_to_sleep, rules);
        
        event_print(rules, philo->id, "is thinking");
    }
}

void eat(t_philosopher *philo)
{
    t_rules *rules;

    rules = philo->rules;
    pthread_mutex_lock(&(rules->fork_mutex[philo->left_fork_id]));
    event_print(rules, philo->id, "has taken a fork");
    pthread_mutex_lock(&(rules->fork_mutex[philo->right_fork_id]));
    event_print(rules, philo->id, "has taken a fork");
    pthread_mutex_lock(&(rules->meal_check_mutex));
    event_print(rules, philo->id, "is eating");
    philo->last_meal_time = timestamp();
    pthread_mutex_unlock(&(rules->meal_check_mutex));
    ft_usleep(rules->time_to_eat, rules);
    (philo->times_eaten)++;
    pthread_mutex_unlock(&(philo->left_fork_id));
    pthread_mutex_unlock(&(philo->right_fork_id));
}