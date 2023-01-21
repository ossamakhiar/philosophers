/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:13:00 by okhiar            #+#    #+#             */
/*   Updated: 2023/01/20 14:07:59 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
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
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
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
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

long long	ft_timestamp(void)
{
	static long long	start;
	struct timeval		tv;
	long long			m_sec;

	if (gettimeofday(&tv, NULL))
		ft_putstr_fd("Error on getting timestamp\n", 2);
	m_sec = tv.tv_sec * 1000;
	m_sec += (tv.tv_usec / 1000);
	if (!start)
		start = m_sec;
	return (m_sec - start);
}

int	err_ret(void *ptr, int err)
{
	if (!ptr || err)
		return (1);
	return (0);
}
