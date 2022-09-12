/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mt_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremoretton <pierremoretton@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:11:40 by pierremoret       #+#    #+#             */
/*   Updated: 2022/08/02 20:29:02 by pierremoret      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str != '\0')
	{
		write(fd, str, 1);
		str++;
	}
}

void	putnbr_fd(int nb, int fd)
{
	char	c;

	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		putnbr_fd(nb / 10, fd);
	c = nb % 10 + '0';
	write(fd, &c, 1);
	return ;
}

int	mt_atoi(const char *nptr)
{
	int				i;
	int				sign;
	unsigned int	res;

	sign = 1;
	i = 0;
	res = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = (res * 10) + (nptr[i++] - 48);
	return (sign * res);
}

int	pid_check(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (1);
}
