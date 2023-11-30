/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:05:30 by shamzaou          #+#    #+#             */
/*   Updated: 2023/11/30 04:49:53 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int simulation(t_rules *rules)
{
    t_philosopher *philosophers;
    int id;
    pthread_t monitor_thread;

    philosophers = rules->philosophers;
    id = 0;
    rules->simulation_start = timestamp();
    while (id < rules->nbr_philo)
    {
        if (pthread_create(&(philosophers[id].thread_id), NULL, routine, &(philosophers[id])))
            return(EXIT_FAILURE);
        philosophers[id].last_meal_time = timestamp();
        id++;
    }
    
    // Create monitoring thread
    if (pthread_create(&monitor_thread, NULL, routine_monitor, rules))
        return(EXIT_FAILURE);

    // Join philosopher threads using a while loop
    id = 0;
    while (id < rules->nbr_philo) {
        if (pthread_join(philosophers[id].thread_id, NULL))
            return(EXIT_FAILURE);
        id++;
    }

    // Join monitoring thread
    if (pthread_join(monitor_thread, NULL))
        return(EXIT_FAILURE);
        
    return (EXIT_SUCCESS);
}

void *routine(void *philo_ptr)
{
    t_philosopher   *philo;
    t_rules         *rules;

    philo = (t_philosopher *)philo_ptr;
    rules = philo->rules;
    if (philo->id % 2)
        usleep(15000);
        
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
    return (NULL);
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
    pthread_mutex_unlock(&(rules->fork_mutex[philo->left_fork_id]));
    pthread_mutex_unlock(&(rules->fork_mutex[philo->right_fork_id]));
}

void *routine_monitor(void *rules_ptr)
{
    t_rules *rules;
    int i;
    
    rules = (t_rules *)rules_ptr;
    while (!(rules->all_ate))
    {
        i = -1;
        while (++i < rules->nbr_philo && !(rules->death))
        {
            pthread_mutex_lock(&(rules->meal_check_mutex));
            if (time_diff(rules->philosophers[i].last_meal_time, timestamp()) > rules->time_to_die)
            {
                event_print(rules, i, "died");
                rules->death = true;
            }
            pthread_mutex_unlock(&(rules->meal_check_mutex));
            usleep(100);
        }
        if (rules->death)
            break;
        i = 0;
        while (rules->max_meals != -1 && i < rules->nbr_philo && rules->philosophers[i].times_eaten >= rules->max_meals)
            i++;
        if (i == rules->nbr_philo)
            rules->all_ate = true;
    }
    return (NULL);
}