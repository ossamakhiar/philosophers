/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:23:14 by okhiar            #+#    #+#             */
/*   Updated: 2023/02/05 21:12:53 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	life_init(t_life *life, char **av)
{
	life->n_philo = ft_atoi(av[1]);
	life->t_die = ft_atoui(av[2]);
	life->t_eat = ft_atoui(av[3]);
	life->t_sleep = ft_atoui(av[4]);
	life->n_meals = -1;
	if (av[5])
	{
		life->n_meals = ft_atoi(av[5]);
		if (av[5][0] == '-')
			return (1);
	}
	if (av[1][0] == '-' || av[2][0] == '-'
		|| av[3][0] == '-' || av[4][0] == '-')
		return (1);
	return (0);
}

void	init_philos(t_philos *philos, char **av)
{
	sem_unlink("write");
	sem_unlink("eat");
	sem_unlink("forks");
	if (life_init(&philos->life, av))
		ft_putstr_fd_("Invalide Argument\n", 2);
	philos->forks = sem_open("forks", O_CREAT | O_EXCL, \
			0666, philos->life.n_philo);
	if (philos->forks == SEM_FAILED)
		ft_putstr_fd_("Error on opening semaphore\n", 2);
	philos->philo_info = (t_pinfo *)malloc(sizeof(t_pinfo) * \
		philos->life.n_philo);
	err_exit(philos->philo_info);
	philos->writing = sem_open("write", O_CREAT | O_EXCL, 0666, 1);
	if (philos->writing == SEM_FAILED)
		ft_putstr_fd_("Error on opening semaphore\n", 2);
	philos->eating = sem_open("eat", O_CREAT | O_EXCL, 0666, 1);
	if (philos->eating == SEM_FAILED)
		ft_putstr_fd_("Error on opening semaphore\n", 2);
}
