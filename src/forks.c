/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:51:17 by alphbarr          #+#    #+#             */
/*   Updated: 2024/08/17 20:04:16 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo.h"

void	take_fork(char fork_name, t_philo *philo)
{
	int		*taken;
	t_fork	*fork;

	if (!is_dead(philo))
	{
		taken = &(philo->r_taken);
		fork = philo->r_fork;
		if (fork_name == 'l')
		{
			taken = &(philo->l_taken);
			fork = philo->l_fork;
		}
		pthread_mutex_lock(&(fork->lock));
		if (!(*taken) && !fork->used)
		{
			*taken = 1;
			fork->used = 1;
			pthread_mutex_unlock(&(fork->lock));
			state_param("has taken a fork", philo);
		}
		else
			pthread_mutex_unlock(&(fork->lock));
	}
}

void	release_fork(char fork_name, t_philo *philo)
{
	int		*taken;
	t_fork	*fork;

	taken = &(philo->r_taken);
	fork = philo->r_fork;
	if (fork_name == 'l')
	{
		taken = &(philo->l_taken);
		fork = philo->l_fork;
	}
	pthread_mutex_lock(&(fork->lock));
	*taken = 0;
	fork->used = 0;
	pthread_mutex_unlock(&(fork->lock));
}

void	release_forks_and_sleep(t_philo *philo)
{
	release_fork('r', philo);
	release_fork('l', philo);
	state_param("is sleeping", philo);
	ft_usleep(philo->params->time_sleep);
}
