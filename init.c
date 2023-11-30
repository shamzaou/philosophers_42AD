/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:05:32 by shamzaou          #+#    #+#             */
/*   Updated: 2023/11/30 04:43:14 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int parse_and_initialise(char **argv, t_rules *rules)
{
    if (parse(argv, rules))
        return (EXIT_FAILURE);
    rules->death = false;
    rules->all_ate = false;
    
    if (initialise_mutexes(rules))
        return (EXIT_FAILURE);
    if (initialise_philosophers(rules))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int parse(char **argv, t_rules *rules)
{
    rules->nbr_philo = ft_atoi(argv[1]);
    rules->time_to_die = ft_atoi(argv[2]);
    rules->time_to_eat = ft_atoi(argv[3]);
    rules->time_to_sleep = ft_atoi(argv[4]);
    // NEEDS MORE CHECKS
    if (rules->nbr_philo < 2 || rules->nbr_philo > MAX_PHILOSOPHERS ||
        rules->time_to_die < 0 || rules->time_to_eat < 0 ||
        rules->time_to_sleep < 0)
        return (EXIT_FAILURE);
    if (argv[5])
    {
        rules->max_meals = ft_atoi(argv[5]);
        if (rules->max_meals <= 0)
            return(EXIT_FAILURE);
    }
    else
        rules->max_meals = -1;
    return (EXIT_SUCCESS);
}

int initialise_mutexes(t_rules *rules)
{
    int id;

    id = rules->nbr_philo;
    while (--id >= 0)
    {
        if (pthread_mutex_init(&(rules->fork_mutex[id]), NULL))
            return (EXIT_FAILURE);
    }
    if (pthread_mutex_init(&(rules->print_mutex), NULL))
        return (EXIT_FAILURE);
    if (pthread_mutex_init(&(rules->meal_check_mutex), NULL))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int initialise_philosophers(t_rules *rules)
{
    int id;

    id = rules->nbr_philo;
    while (--id >= 0)
    {
        rules->philosophers[id].id = id;
        rules->philosophers[id].times_eaten = 0;
        rules->philosophers[id].left_fork_id = id;
        rules->philosophers[id].right_fork_id = (id + 1) % rules->nbr_philo;
        rules->philosophers[id].last_meal_time = 0;
        rules->philosophers[id].rules = rules;
    }
    return (EXIT_SUCCESS);
}