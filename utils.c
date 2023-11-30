/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamzaou <shamzaou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:05:35 by shamzaou          #+#    #+#             */
/*   Updated: 2023/12/01 03:38:51 by shamzaou         ###   ########.fr       */
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
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	return (result);
}

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	time_diff(long long past, long long present)
{
	return (present - past);
}

void	event_print(t_rules *rules, int id, char *string)
{
	pthread_mutex_lock(&(rules->print_mutex));
	if (!(rules->death))
	{
		printf("%lli ", timestamp() - rules->simulation_start);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(rules->print_mutex));
}

void	ft_usleep(long long time, t_rules *rules)
{
	long long	pin;

	pin = timestamp();
	while (!(rules->death))
	{
		if (time_diff(pin, timestamp()) >= time)
			break ;
		usleep(50);
	}
}
