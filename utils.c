/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:05:35 by shamzaou          #+#    #+#             */
/*   Updated: 2023/11/29 04:04:51 by shamzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	long long	result;
	int			i;

	i = 0;
	result = 0;
	if (str == NULL)
		return (-1);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] && str[i] >= '9' && str[i] <= '0')
		return (-1);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		if (result > UINT_MAX)
			return (-1);
		i++;
	}
	if (result < 2)
		return (-1);
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	return (result);
}