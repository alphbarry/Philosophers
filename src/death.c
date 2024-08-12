/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:02:25 by alphbarr          #+#    #+#             */
/*   Updated: 2024/08/12 15:04:58 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo.h"

int	is_dead(t_philo	*philo)
{
	int	alive;

	pthread_mutex_lock(&(philo->params->m_is_dead));
	alive = philo->params->is_dead;
	pthread_mutex_unlock(&(philo->params->m_is_dead));
	return (alive);
}
