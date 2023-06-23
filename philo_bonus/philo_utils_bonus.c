/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:20:18 by okhiar            #+#    #+#             */
/*   Updated: 2023/01/27 16:06:06 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_putstr_fd_(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
	exit(1);
}

void	err_exit(void *ptr)
{
	if (!ptr)
		ft_putstr_fd_("Error\n", 2);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');
	if (!str[i])
		ft_putstr_fd_("Invalid Arguments!\n", 2);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		ft_putstr_fd_("Invalid Arguments!\n", 2);
	return (result * sign);
}

unsigned int	ft_atoui(char *str)
{
	int				i;
	unsigned int	result;

	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		ft_putstr_fd_("Invalid Arguments!\n", 2);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		ft_putstr_fd_("Invalid Arguments!\n", 2);
	return (result);
}

long long	ft_timestamp(void)
{
	static long long	start;
	struct timeval		tv;
	long long			m_sec;

	if (gettimeofday(&tv, NULL))
		ft_putstr_fd_("Error getting the time\n", 2);
	m_sec = tv.tv_sec * 1000;
	m_sec += tv.tv_usec / 1000;
	if (!start)
		start = m_sec;
	return (m_sec - start);
}
