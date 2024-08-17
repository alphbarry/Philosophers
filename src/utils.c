/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:48:59 by alphbarr          #+#    #+#             */
/*   Updated: 2024/08/17 20:23:43 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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

void	ft_usleep(long int milliseconds)
{
	long int	start_time;

	start_time = 0;
	start_time = get_time();
	while ((get_time() - start_time) < milliseconds)
		usleep(100);
}

void	state_param(char *s, t_philo *philo)
{
	long	cur_time;

	cur_time = get_time() - philo->params->start_time;
	pthread_mutex_lock(&(philo->params->mutex));
	if (!is_dead(philo))
		printf("%09ld %d %s\n", cur_time, philo->pos, s);
	pthread_mutex_unlock(&(philo->params->mutex));
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
