/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou@student.42abudhabi.ae <shamzao    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:05:32 by shamzaou          #+#    #+#             */
/*   Updated: 2023/11/30 09:15:37 by shamzaou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int  error_handler(int error_code)
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
    else if (error_code == 4)
    {
        return (printf("0 1 died\n"));
    }
    else
        return (0);
}