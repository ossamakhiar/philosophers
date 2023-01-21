/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:34:11 by okhiar            #+#    #+#             */
/*   Updated: 2023/01/21 20:36:38 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>

typedef struct s_life
{
	int				n_philo;
	int				n_meals;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
}	t_life;

typedef struct s_pinfo
{
	int				id;
	int				n_eat;
	pid_t			pid;
	long long		last_meal;
	struct s_philos	*cmn_data;
	
}	t_pinfo;

typedef struct s_philos
{
	t_pinfo			*philo_info;
	sem_t			*forks;
	t_life			life;
	pthread_mutex_t	writing;
}	t_philos;

void			ft_putstr_fd_(char *str, int fd);
int				ft_atoi(char *str);
unsigned int	ft_atoui(char *str);
void			init_philos(t_philos *philos, char **av);

#endif
