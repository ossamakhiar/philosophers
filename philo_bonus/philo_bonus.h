/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:34:11 by okhiar            #+#    #+#             */
/*   Updated: 2023/02/05 21:12:59 by okhiar           ###   ########.fr       */
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
# include <sys/wait.h>
# include <signal.h>

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
	long long		next_eat;
	struct s_philos	*cmn_data;
}	t_pinfo;

typedef struct s_philos
{
	// t_pinfo			philo_info[250];
	t_pinfo			*philo_info;
	sem_t			*forks;
	sem_t			*writing;
	sem_t			*eating;
	t_life			life;
}	t_philos;

void			ft_putstr_fd_(char *str, int fd);
void			err_exit(void *ptr);
int				ft_atoi(char *str);
unsigned int	ft_atoui(char *str);
void			init_philos(t_philos *philos, char **av);
long long		ft_timestamp(void);
void			ft_print(t_pinfo *philo, char *str);
void			ft_usleep(long long m_sec);
void			ft_eat(t_pinfo *philo);
void			ft_phi_sleep(t_pinfo *philo);
void			destruct_philos(t_philos *philos);

#endif
