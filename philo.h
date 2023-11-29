/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:05:37 by shamzaou          #+#    #+#             */
/*   Updated: 2023/11/29 04:59:10 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

# define MAX_PHILOSOPHERS 200

typedef struct s_rules t_rules;

typedef struct philosopher
{
    int    id;
    int    times_eaten;
    int    right_fork_id;
    int    left_fork_id;
    int    last_meal_time;
    t_rules    *rules;
    pthread_t    thread_id;
}                   t_philosopher;

typedef struct s_rules
{
    int    nbr_philo;
    int    time_to_die;
    int    time_to_eat;
    int    time_to_sleep;
    int    max_meals;
    bool   is_dead;
    bool   all_ate;
    bool   simulation_start;
    pthread_mutex_t    fork_mutex[MAX_PHILOSOPHERS];
    pthread_mutex_t    print_mutex;
    pthread_mutex_t    meal_check_mutex;
    t_philosopher      philosophers[MAX_PHILOSOPHERS];
}                   t_rules;

/* >>> init.c <<< */
int parse_and_initialise(int argc, char **argv, t_rules *rules);
int parse(char **argv, t_rules *rules);
int initialise_mutexes(t_rules *rules);
int initialise_philosophers(t_rules *rules);

/* >>> philo.c <<< */

/* >>> utils.c <<< */
int	ft_atoi(char *str);

#endif
