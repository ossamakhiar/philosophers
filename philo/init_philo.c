/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:51:44 by okhiar            #+#    #+#             */
/*   Updated: 2023/01/20 14:01:58 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_rules(t_life *life, char **av)
{
	life->n_philo = ft_atoi(av[1]);
	life->t_die = ft_atoui(av[2]);
	life->t_eat = ft_atoui(av[3]);
	life->t_sleep = ft_atoui(av[4]);
	life->check = 0;
	if (av[5])
	{
		life->n_meals = ft_atoui(av[5]);
		life->check = 1;
		if (av[5][0] == '-')
			return (1);
	}
	if (av[1][0] == '-' || av[2][0] == '-'
		|| av[3][0] == '-' || av[4][0] == '-')
		return (1);
	return (0);
}

int	init_philos(t_philo	*philos, char **av)
{
	int	i;
	int	err;

	i = -1;
	err = init_rules(&philos->life, av);
	philos->philo_info = (t_pinfo *)malloc(sizeof(t_pinfo) * \
							philos->life.n_philo);
	err = err_ret(philos->philo_info, err);
	philos->mtx = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
							philos->life.n_philo);
	err = err_ret(philos->mtx, err);
	if (err)
		return (1);
	philos->death = 0;
	philos->all_ate = philos->life.n_philo;
	if (pthread_mutex_init(&philos->writing, NULL))
		return (1);
	if (pthread_mutex_init(&philos->eating, NULL))
		return (1);
	while (++i < philos->life.n_philo)
		if (pthread_mutex_init(&(philos->mtx[i]), NULL))
			return (1);
	return (0);
}

void	destructor_philos(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->life.n_philo)
		pthread_join(philos->philo_info[i].th_philos, NULL);
	i = -1;
	while (++i < philos->life.n_philo)
		pthread_mutex_destroy(&philos->mtx[i]);
	pthread_mutex_destroy(&philos->writing);
	pthread_mutex_destroy(&philos->eating);
}
