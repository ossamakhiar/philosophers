/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:26:31 by okhiar            #+#    #+#             */
/*   Updated: 2023/01/27 16:08:54 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_usleep(long long m_sec)
{
	long long	start;

	start = ft_timestamp();
	while (ft_timestamp() - start < m_sec)
		usleep(m_sec / 10);
}

void	ft_print(t_pinfo *philo, char *str)
{
	sem_wait(philo->cmn_data->writing);
	printf("%lld %d %s\n", ft_timestamp(), philo->id, str);
	sem_post(philo->cmn_data->writing);
}

void	ft_eat(t_pinfo *philo)
{
	sem_wait(philo->cmn_data->forks);
	ft_print(philo, "has taken a fork");
	if (philo->cmn_data->life.n_philo == 1)
	{
		ft_usleep(philo->cmn_data->life.t_die + 1);
		return ;
	}
	sem_wait(philo->cmn_data->forks);
	ft_print(philo, "has taken a fork");
	sem_wait(philo->cmn_data->eating);
	ft_print(philo, "is eating");
	philo->last_meal = ft_timestamp();
	philo->n_eat++;
	sem_post(philo->cmn_data->eating);
	ft_usleep(philo->cmn_data->life.t_eat);
	sem_post(philo->cmn_data->forks);
	sem_post(philo->cmn_data->forks);
}

void	ft_phi_sleep(t_pinfo *philo)
{
	ft_print(philo, "is sleeping");
	ft_usleep(philo->cmn_data->life.t_sleep);
}
