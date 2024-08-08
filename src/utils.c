/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:48:59 by alphbarr          #+#    #+#             */
/*   Updated: 2024/08/08 14:20:06 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_strlen(char *s)
{
	int	i;

	if (s = NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(char *s)
{
	int	i;
	int	sign;
	unsigned long long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
			|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return (res * sign);
}

size_t	get_current_time(void)
{
	struct	timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write (2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

void	state_param(char *s, t_philo *philos)
{
	long	cur_time;

	cur_time = get_current_time() - philos->params->start_time;
	pthread_mutex_lock(&(philos->params->mutex));
	if (!is_dead(philos))
		printf("%09ld %d %s\n", cur_time, philos->pos, s);
	pthread_mutex_unlock(&(philos->params->mutex));
}
