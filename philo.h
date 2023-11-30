/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou@student.42abudhabi.ae <shamzao    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:05:37 by shamzaou          #+#    #+#             */
/*   Updated: 2023/11/30 09:30:55 by shamzaou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <limits.h>
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
    long long    last_meal_time;
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
    bool   death;
    bool   all_ate;
    long long   simulation_start;
    pthread_mutex_t    fork_mutex[MAX_PHILOSOPHERS];
    pthread_mutex_t    print_mutex;
    pthread_mutex_t    meal_check_mutex;
    t_philosopher      philosophers[MAX_PHILOSOPHERS];
}                   t_rules;

/* >>> init.c <<< */
int parse_and_initialise(char **argv, t_rules *rules);
int parse(char **argv, t_rules *rules);
int initialise_mutexes(t_rules *rules);
int initialise_philosophers(t_rules *rules);

/* >>> philo.c <<< */
int simulation(t_rules *rules);
void *routine(void *philo_ptr);
void eat(t_philosopher *philo);
void *routine_monitor(void *rules_ptr);
void destroy_mutexes(t_rules *rules);

/* >>> utils.c <<< */
int	ft_atoi(char *str);
void event_print(t_rules *rules, int id, char *string);
long long timestamp(void);
long long time_diff(long long past, long long present);
void ft_usleep(long long time, t_rules *rules);


int  error_handler(int error_code);

#endif
