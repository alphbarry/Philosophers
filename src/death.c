/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:02:25 by alphbarr          #+#    #+#             */
/*   Updated: 2024/08/18 19:36:26 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo.h"

int	is_dead(t_philo *philo)
{
	int	alive;

	pthread_mutex_lock(&(philo->params->m_is_dead));
	alive = philo->params->is_dead;
	pthread_mutex_unlock(&(philo->params->m_is_dead));
	return (alive);
}

int	check_philo_death(t_philo *philo, long cur_time)
{
	int	dead;
	int	last_meal;

	dead = 0;
	pthread_mutex_lock(&(philo->m_last_meal));
	last_meal = cur_time - philo->last_meal;
	pthread_mutex_unlock(&(philo->m_last_meal));
	if (last_meal > philo->params->time_die)
	{
		pthread_mutex_lock(&(philo->params->mutex));
		pthread_mutex_lock(&(philo->params->m_is_dead));
		philo->params->is_dead = 1;
		pthread_mutex_unlock(&(philo->params->m_is_dead));
		printf("%09ld %d died\n", cur_time, philo->pos);
		pthread_mutex_unlock(&(philo->params->mutex));
		dead = 1;
	}
	return (dead);
}

void	*check_philos_death(void *arg)
{
	t_param		*params;
	t_philo		**philos;
	long		cur_time;
	int			cur;

	philos = (t_philo **)arg;
	params = philos[0]->params;
	while (1)
	{
		cur = 0;
		cur_time = get_time() - params->start_time;
		while (cur < params->num)
		{
			if (check_philo_death(&(*philos)[cur], cur_time))
				return (NULL);
			cur++;
		}
		ft_usleep(1);
	}
	return (NULL);
}
