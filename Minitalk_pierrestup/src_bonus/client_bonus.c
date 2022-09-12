/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremoretton <pierremoretton@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:27:00 by pierremoret       #+#    #+#             */
/*   Updated: 2022/08/02 13:21:24 by pierremoret      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

void	sendchar(unsigned char c, pid_t pid)
{
	int	i;

	i = 1;
	while (i <= 8)
	{	
		if ((c & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		c >>= 1;
		pause();
		usleep(25);/* tester sur les ordis de l'ecole */
	}
	return ;
}

void	send_str(char *str, pid_t pid)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		sendchar((unsigned char)str[i], pid);
		i++;
	}
	sendchar('\n', pid);
	sendchar('\0', pid);
}

void	mt_client_handler(int sig_id)
{
	(void)sig_id;
}

void	mt_endstr(int sig_id)
{
	(void)sig_id;
	putstr_fd("\n✅Envoyé\n", 1);
}

int	main(int argc, char **argv)
{
	pid_t	pidnumber;

	signal(SIGUSR1, mt_client_handler);
	signal(SIGUSR2, mt_endstr);
	if (argc != 3)
	{
		putstr_fd("\n❌ Erreur: Nombre d'arguments invalide\n", 1);
		return (0);
	}
	if (pid_check(argv[1]) == -1)
	{
		putstr_fd("\n ❌PID INVALIDE\n", 1);
		return (0);
	}
	pidnumber = mt_atoi(argv[1]);
	send_str(argv[2], pidnumber);
	return (0);
}
