/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:03:15 by shamzaou          #+#    #+#             */
/*   Updated: 2023/11/29 04:23:00 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules rules;
	int init_status;

	if (argc != 5 && argc != 6)
	{
		printf("Usage: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		exit(EXIT_FAILURE);
	}
	init_status = parse_and_initialise(argc, argv, &rules);
	if (init_status != EXIT_SUCCESS)
	{
		printf("Error: Program initialisation failed!\n");
        exit(EXIT_FAILURE);
	}
	if (philo(&rules))
	{
        printf("Error: Simulation failed!\n");
        exit(EXIT_FAILURE);
    }
	return (EXIT_SUCCESS);
}

