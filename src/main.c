/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:43:06 by alphbarr          #+#    #+#             */
/*   Updated: 2024/08/18 19:34:57 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	free_all(t_philo *philos, t_fork *forks, t_param *params, int exit_code)
{
	wait_threads(&philos, params);
	free(philos);
	free(forks);
	return (exit_code);
}

int	check_nb(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] < '0' && av[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_arg(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
	{
		printf("Usage : ./philo number_philos time_to_die ");
		printf("time_to_eat time_to_sleep [number_eat]\n");
		return (0);
	}
	while (i != ac)
	{
		if (!check_nb(av[i]))
		{
			printf("Syntax Error in av[%d].", i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_param		params;
	t_philo		*philos;
	t_fork		*forks;
	int			return_code;

	return_code = 0;
	if (!check_arg(ac, av))
		return (1);
	if (!init_params(&params, ac, av))
		return (1);
	if (!create_philos(&philos, &params, &forks))
		return (1);
	if (!create_threads(&philos, &params))
		return_code = stop_threads(&philos[0]);
	return (free_all(philos, forks, &params, return_code));
}
