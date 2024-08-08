/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:52:14 by alphbarr          #+#    #+#             */
/*   Updated: 2024/08/08 13:38:08 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_philos(t_philo *philo, t_params *param, t_forks **forks, int cur)
{
	philo->params = params;
	philo->pos = cur;
	philo->last_meal = 0;
	philo->meals_eaten = 0;
	philo->r_fork = &((*forks)[cur]);
	philo->r_taken = 0;
	philo->l_taken = 0;
	if (cur == params->num - 1)
		philo->l_fork = &((forks)[0]);
	else
		philo->l_fork = &((forks)[cur + 1]);
	phil->l_fork->used = 0;
	pthread_mutex_init(&(philo->m_last_meal), NULL);
	pthread_mutex_init(&(philo->l_fork->lock), NULL);
}

int	create_philos(t_philo **philos, t_param *params, t_forks **forks)
{
	int	cur;

	*philos = malloc(sizeof(t_philo) * params->num);
	if (!philos)
		return (0);
	*forks = malloc(sizeof(t_forks) * params->num);
	if (!forks)
	{
		free(*philos)
		return (0);
	}
	cur = 0;
	while (cur < params->num)
	{
		init_philos(&((*philos)[cur]), params, forks, cur);
		cur++;
	}
	return (1);
}

int	init_params(t_params *param, int ac, char **av)
{
	if (ac < 5)
	{
		printf("Usage : ./philo number_philos time_to_die ");
		printf("time_to_eat time_to_sleep [number_eat]\n");
		return (0);
	}
	param->num = ft_atoi(av[1]);
	param->time_to_die = ft_atoi(av[2]);
	param->time_to_eat = ft_atoi(av[3]);
	param->time_to_slee = ft_atoi(av[4]);
	if (ac > 5)
	{
		param->max_meal = ft_atoi(av[5]);
		if (ft_atoi(av[5]) < 0)
			return (0);
	}
	param->is_dead = 0;
	if (parma->num <= 0 || param->time_to_die < 0 || param->time_to_eat < 0
			|| param->time_to_sleep < 0)
		return (0);
	pthread_mutex_init(&(param->mutex), NULL);
	pthread_mutex_init(&(param->m_is_dead), NULL);
	return (1);
}
