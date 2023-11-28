/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:03:15 by shamzaou          #+#    #+#             */
/*   Updated: 2023/11/28 05:34:43 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_rules rules;
    int     init_status;

    if (ac != 5 && ac != 6)
        return (display_error("Wrong number of Arguments!"));
    init_status = init_all(&rules, av);
    if (init_status)
        return (error_handler(init_status));
    if (philo(&rules))
        return (display_error("Thread creation failure!"));
    return (0);
}