/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:19:17 by okhiar            #+#    #+#             */
/*   Updated: 2023/01/21 20:40:56 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	destruct_philos(t_philos *philos)
{
	if (sem_close(philos->forks))
		ft_putstr_fd_("Error closing\n", 2);
	if (sem_unlink(philos->forks))
		ft_putstr_fd_("Error unlink\n", 2);
}

int	main(int ac, char **av)
{
	t_philos	philos;

	if (ac != 5 && ac != 6)
		ft_putstr_fd_("Invalid number of arguments\n", 2);
	philo_init(&philos, av);
	// TODO: launch proccesses (life of philosophers)
	destruct_philos(&philos);
	return (0);
}
