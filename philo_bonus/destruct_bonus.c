/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:33:21 by okhiar            #+#    #+#             */
/*   Updated: 2023/01/27 16:17:38 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_philos(t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philos->life.n_philo)
		kill(philos->philo_info[i++].pid, SIGTERM);
}

void	destruct_philos(t_philos *philos)
{
	int	i;
	int	status;

	i = 0;
	while (i < philos->life.n_philo)
	{
		waitpid(-1, &status, 0);
		if (status)
		{
			kill_philos(philos);
			break ;
		}
		i++;
	}
	if (sem_close(philos->forks) || sem_close(philos->eating) || \
				sem_close(philos->writing))
		ft_putstr_fd_("Error closing\n", 2);
	if (sem_unlink("eat"))
		ft_putstr_fd_("Error unlink semaphore\n", 2);
	if (sem_unlink("write"))
		ft_putstr_fd_("Error unlink semaphore\n", 2);
	if (sem_unlink("forks"))
		ft_putstr_fd_("Error unlink semaphore\n", 2);
}
