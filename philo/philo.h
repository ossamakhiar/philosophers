/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:14:18 by okhiar            #+#    #+#             */
/*   Updated: 2023/01/21 18:20:44 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_life
{
	int				n_philo;
	int				check;
	int				n_meals;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
}	t_life;

typedef struct s_pinfo
{
	int				id;
	int				n_eat;
	long long		last_eat;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct s_philo	*cmn_data;
	pthread_t		th_philos;
}	t_pinfo;

typedef struct s_philo
{
	int				death: 2;
	int				all_ate: 2;
	long long		t_start;
	t_pinfo			*philo_info;
	pthread_mutex_t	*mtx;
	pthread_mutex_t	writing;
	pthread_mutex_t	eating;
	t_life			life;
}	t_philo;

void			ft_putstr_fd(char *str, int fd);
int				err_ret(void *ptr, int err);

/* Parse */
int				ft_atoi(char *str);
unsigned int	ft_atoui(char *str);

/* Utils : Time && print */
long long		ft_timestamp(void);
void			ft_print(t_pinfo *philo, char *str);
void			ft_usleep(long long ms_sec);

/* Init */
int				init_philos(t_philo	*philos, char **av);
void			destructor_philos(t_philo *philos);

/* life */
void			ft_philo_sleep(t_pinfo *philo);
void			ft_eat(t_pinfo *philo);

#endif
