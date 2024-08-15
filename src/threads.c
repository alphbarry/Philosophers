/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:51:24 by alphbarr          #+#    #+#             */
/*   Updated: 2024/08/15 18:06:04 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_life(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->pos % 2 != 0)
		ft_usleep(philo->params->time_to_eat);
	while (!is_dead(philo))
	{
		if (philo->meals_eaten >= philo->params->max_meal
				&& philo->params->max_meal > 0)
			break ;
		take_fork('l', philo);
		if (philo->l_taken)
			take_fork('r', philo);
		if (philo->l_taken && philo->r_taken)
		{
			state_param("is_eating", philo);
			ft_usleep(philo->params->time_to_eat);
			philo->meals_eaten++;
			pthread_mutex_lock(&(philo->m_last_meal));
			philo->last_meal = get_current_time() - philo->params->start_time;
			pthread_mutex_unlock(&(philo->m_last_meal));
			release_fork_and_sleep(philo);
		}
	}
}


int	create_threads(t_philo **philos, t_param *params)
{
	int	cur;

	params->start_time = get_current_time();
	cur = 0;
	while (cur < params->num)
	{
		if (pthread_create(&((*philos)[cur].thread, NULL,
				philo_life,	&((*philos)[cur]))))
			return (0);
		cur++;
	}
	if (pthread_create(&(params->death_thread), NULL,
			check_philos_death, philos))
		return (0);
	return (1);
}


int	wait_threads(t_philo **philo, t_param *param)
{
	int	cur;
	int	return_code;

	cur = 0;
	return_code = 1;
	while (cur < param->num)
	{
		if (pthread_join((*philo)[cur].thread, NULL))
				return_code = 0;
				cur++;
	}
	return (return_code);
}

int	stop_threads(t_philo *philo)
{
	pthread_mutex_lock(&(philo->params->m_is_dead));
	philo->params->is_dead = 1;
	pthread_mutex_unlock(&(philo->params->m_is_dead));
	return (1);
}


