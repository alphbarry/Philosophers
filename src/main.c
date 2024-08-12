/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:43:06 by alphbarr          #+#    #+#             */
/*   Updated: 2024/08/12 14:49:29 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_arg_content(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_args(char **av)
{

	if (ft_atoi(av[1]) <= 0 || check_arg_content(av) == 1)
		(return (write (2, "Invalid philosophers number\n", 29), 1));
	if (ft_atoi(av[2]) <= 0 || check_arg_content(av) == 1)
		(return (write (2, "Invalid time to die\n", 21), 1));
	if (ft_atoi(av[3]) <= 0 || check_arg_content(av) == 1)
		(return (write (2, "Invalid time to eat\n", 21), 1));
	if (ft_atoi(av[4]) <= 0 || check_arg_content(av) == 1)
		(return (write (2, "Invalid time to sleep\n", 23), 1));
	if (av[5] && (ft_atoi(av[5]) <= 0 || check_arg_content(av) == 1))
		(return (write (2, "Invalid number of times each philosopher must eat\n", 51), 1));
	return (0);
}

void	free_all(t_philo *philos, t_fork *forks, int exit_code)
{
	free(philos);
	free(forks);
	return (exit_code);
}

int	main(int ac, char **av)
{
	t_param			param;
	t_philo			*philos;
	t_fork			*forks;
	int				return_code;

	return_code = 0;
	if (ac != 5 || ac != 6)
		return (write (2, "Wrongs args\n", 12), 1);
	if (check_args(av) == 1)
		return (1);
	if (!init_params(param, ac, av))
		return (1);
	if (!create_philos(&philos, &params, &forks))
		return (1);
	if (!create_threads())
}
