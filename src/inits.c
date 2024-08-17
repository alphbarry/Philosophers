/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:52:14 by alphbarr          #+#    #+#             */
/*   Updated: 2024/08/17 20:22:53 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_philo(t_philo *philo, t_fork **forks, t_param *params, int cur)
{
	philo->params = params;
	philo->pos = cur + 1;
	philo->last_meal = 0;
	philo->meals_eaten = 0;
	philo->r_fork = &((*forks)[cur]);
	philo->r_taken = 0;
	philo->l_taken = 0;
	if (cur == params->num - 1)
		philo->l_fork = &((*forks)[0]);
	else
		philo->l_fork = &((*forks)[cur + 1]);
	philo->l_fork->used = 0;
	pthread_mutex_init(&(philo->m_last_meal), NULL);
	pthread_mutex_init(&(philo->l_fork->lock), NULL);
}

int	create_philos(t_philo **philos, t_param *params, t_fork **forks)
{
	int	cur;

	*philos = malloc(sizeof(t_philo) * params->num);
	if (!(*philos))
		return (0);
	*forks = malloc(sizeof(t_fork) * params->num);
	if (!(*forks))
	{
		free(*philos);
		return (0);
	}
	cur = 0;
	while (cur < params->num)
	{
		init_philo(&(*philos)[cur], forks, params, cur);
		cur++;
	}
	return (1);
}

int	init_params(t_param *params, int ac, char **av)
{
	params->num = ft_atoi(av[1]);
	params->time_die = ft_atoi(av[2]);
	params->time_eat = ft_atoi(av[3]);
	params->time_sleep = ft_atoi(av[4]);
	params->max_meal = -1;
	if (ac > 5)
	{
		params->max_meal = ft_atoi(av[5]);
		if (ft_atoi(av[5]) < 0)
			return (0);
	}
	params->is_dead = 0;
	if (params->num <= 0 || params->time_die < 0 || params->time_eat < 0
		|| params->time_sleep < 0)
		return (0);
	pthread_mutex_init(&(params->mutex), NULL);
	pthread_mutex_init(&(params->m_is_dead), NULL);
	return (1);
}
