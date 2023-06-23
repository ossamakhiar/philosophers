/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:19:17 by okhiar            #+#    #+#             */
/*   Updated: 2023/02/05 21:10:14 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_master(void *phi)
{
	t_pinfo	*philo;

	philo = (t_pinfo *)phi;
	while (1)
	{
		sem_wait(philo->cmn_data->eating);
		if (philo->cmn_data->life.n_meals != -1 && \
			philo->n_eat == philo->cmn_data->life.n_meals)
		{
			sem_post(philo->cmn_data->eating);
			break ;
		}
		if (ft_timestamp() - philo->last_meal >= \
			(long long)philo->cmn_data->life.t_die)
		{
			sem_wait(philo->cmn_data->writing);
			printf("%lld %d died\n", ft_timestamp(), philo->id);
			exit(1);
		}
		sem_post(philo->cmn_data->eating);
		usleep(100);
	}
	return (NULL);
}

void	philosopher(t_pinfo *philo)
{
	pthread_t	th;

	if (philo->id % 2 == 0)
		usleep(100);
	pthread_create(&th, NULL, ft_master, philo);
	while (1)
	{
		ft_eat(philo);
		if (philo->cmn_data->life.n_meals != -1 && \
				philo->n_eat >= philo->cmn_data->life.n_meals)
			break ;
		ft_phi_sleep(philo);
		ft_print(philo, "is thinking");
	}
	pthread_join(th, NULL);
	exit(0);
}

void	launch_philos(t_philos *philos)
{
	int	i;

	i = 0;
	ft_timestamp();
	while (i < philos->life.n_philo)
	{
		philos->philo_info[i].id = i + 1;
		philos->philo_info[i].n_eat = 0;
		philos->philo_info[i].cmn_data = philos;
		philos->philo_info[i].last_meal = ft_timestamp();
		philos->philo_info[i].pid = fork();
		if (philos->philo_info[i].pid == 0)
			philosopher(&philos->philo_info[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_philos	philos;

	if (ac != 5 && ac != 6)
		ft_putstr_fd_("Invalid number of arguments\n", 2);
	init_philos(&philos, av);
	launch_philos(&philos);
	destruct_philos(&philos);
	return (0);
}
