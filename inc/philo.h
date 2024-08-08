/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:38:28 by alphbarr          #+#    #+#             */
/*   Updated: 2024/08/08 14:20:21 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef "philo.h"
# define "philo.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>


typedef struct	s_param
{
	int				num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meal;
	long			start_time;
	pthread_mutex_t	mutex;
	int				is_dead;
	pthread_mutex_t	m_is_dead;
	pthread			death_thread;
}	t_param;

typedef struct s_fork
{
	int				used;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_philo
{
	pthread_t		thread;
	int				pos;
	int				meals_eaten;
	pthread_mutex_t	m_last_meal;
	size_t			last_meal;
	int				*dead;
	t_fork			*r_fork;
	int				r_taken;
	t_fork			*l_fork;
	int				l_taken;
	t_param			*params;
}	t_philo;

//Utils
int		ft_atoi(char *s);
int		ft_strlen(char *s);
size_t	get_current_time(void);
int		ft_usleep(size_t milliseconds);
void	state_param(char *s, t_philo *philos);

//Inits
int	init_params(t_param *params, int ac, char **av);
int	create_philos(t_philo **philos, t_param *params, t_fork **forks);

#endif // !"philosophers.h"
