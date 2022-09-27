/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:44:12 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/09/27 16:44:13 by ludovictrom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_minitalk.h"

void	servhandler(int signum, siginfo_t *info, void *ucontext)
{
	static unsigned char	res;
	static int				i;

	(void)ucontext;
	res >>= 1;
	i++;
	if (signum == SIGUSR1)
		res |= 128;
	if (i == 8)
	{
		if (res == 0)
		{
			kill(info->si_pid, SIGUSR2);
		}
		write(1, &res, 1);
		i = 0;
		res = 0;
	}
	usleep(25);/* tester sur les ordi de l'ecole */
	kill(info->si_pid, SIGUSR1);
	return ;
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = servhandler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	putstr_fd("server is up with pid = ", 1);
	putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
