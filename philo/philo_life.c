/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:45:33 by okhiar            #+#    #+#             */
/*   Updated: 2023/01/20 14:06:44 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long long ms_sec)
{
	long long	start;

	start = ft_timestamp();
	while (ft_timestamp() - start < ms_sec)
		usleep(ms_sec / 10);
}

void	ft_print(t_pinfo *philo, char *str)
{
	pthread_mutex_lock(&philo->cmn_data->writing);
	if (!philo->cmn_data->death)
		printf("%lld %d %s\n", ft_timestamp(), philo->id, str);
	pthread_mutex_unlock(&philo->cmn_data->writing);
}

void	ft_philo_sleep(t_pinfo *philo)
{
	ft_print(philo, "is sleeping");
	if (!philo->cmn_data->death)
		ft_usleep(philo->cmn_data->life.t_sleep);
}

void	ft_eat(t_pinfo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	ft_print(philo, "has taken left fork");
	if (philo->cmn_data->life.n_philo == 1)
	{
		ft_usleep(philo->cmn_data->life.t_die + 1);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	ft_print(philo, "has taken right fork");
	pthread_mutex_lock(&philo->cmn_data->eating);
	ft_print(philo, "is eating");
	philo->last_eat = ft_timestamp();
	pthread_mutex_unlock(&philo->cmn_data->eating);
	if (!philo->cmn_data->death)
		ft_usleep(philo->cmn_data->life.t_eat);
	philo->n_eat++;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
