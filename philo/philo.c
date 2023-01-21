/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:03:06 by okhiar            #+#    #+#             */
/*   Updated: 2023/01/20 14:05:54 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_master(t_philo *philos)
{
	int	i;

	while (!philos->death)
	{
		i = 0;
		if (!philos->all_ate)
		{
			philos->death = 1;
			return ;
		}
		while (i < philos->life.n_philo && !philos->death)
		{
			pthread_mutex_lock(&philos->eating);
			if (ft_timestamp() - philos->philo_info[i].last_eat \
							>= philos->life.t_die)
			{				
				ft_print(&philos->philo_info[i], "died");
				philos->death = 1;
			}
			pthread_mutex_unlock(&philos->eating);
			usleep(100);
			i++;
		}
	}
}

void	*philosopher(void *phi)
{
	t_pinfo	*philo;

	philo = (t_pinfo *)phi;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!philo->cmn_data->death)
	{
		ft_eat(philo);
		if (philo->cmn_data->life.check && \
				philo->n_eat == philo->cmn_data->life.n_meals)
			philo->cmn_data->all_ate--;
		if (!philo->cmn_data->all_ate)
			break ;
		ft_philo_sleep(philo);
		ft_print(philo, "is thinking");
	}
	return (NULL);
}

int	lunch_philos(t_philo *philos)
{
	int	i;

	i = 0;
	ft_timestamp();
	while (i < philos->life.n_philo)
	{
		philos->philo_info[i].id = i + 1;
		philos->philo_info[i].n_eat = 0;
		philos->philo_info[i].cmn_data = philos;
		philos->philo_info[i].last_eat = ft_timestamp();
		philos->philo_info[i].l_fork = &philos->mtx[i];
		philos->philo_info[i].r_fork = &philos->mtx[(i + 1) % \
											philos->life.n_philo];
		if (pthread_create(&philos->philo_info[i].th_philos, \
					NULL, philosopher, &philos->philo_info[i]))
			return (1);
		i++;
	}
	ft_master(philos);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	philos;

	if (ac == 5 || ac == 6)
	{
		if (init_philos(&philos, av))
		{
			ft_putstr_fd("Invalid Arguments\n", 2);
			return (1);
		}
		if (lunch_philos(&philos))
			return (1);
		destructor_philos(&philos);
		return (0);
	}
	ft_putstr_fd("Invalid Number of Arguments\n", 2);
	return (1);
}
