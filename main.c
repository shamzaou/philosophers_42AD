/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou@student.42abudhabi.ae <shamzao    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:03:15 by shamzaou          #+#    #+#             */
/*   Updated: 2023/11/30 09:13:22 by shamzaou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules rules;
	int code;

	if (argc != 5 && argc != 6)
	{
		return (error_handler(1));
	}
	code = parse_and_initialise(argv, &rules);
	if (code == 3)
    {
		return (error_handler(3));
	}
	else if (code == 4)
	{
		return (error_handler(4));
	}
	if (simulation(&rules))
	{
        return (error_handler(2));
    }
	return (EXIT_SUCCESS);
}
