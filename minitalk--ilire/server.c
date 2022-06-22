#include "minitalk.h"

void	sighandler(int sig, siginfo_t *infos, void *param)
{
	static char	bits = 0;
	static int	i = 0;

	(void)param;
	i++;
	bits = bits << 1;
	if (sig == SIGUSR1)
		bits = bits | 1;
	if (i == 8)
	{
		if (bits == 0)
			kill(infos->si_pid, SIGUSR1);
		ft_printf("%c", bits);
		bits = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	siga;

	siga.sa_sigaction = &sighandler;
	siga.sa_flags = SA_SIGINFO;
	ft_printf("\nServer PID: \033[1;36m%d\033[0m\n\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &siga, NULL);
		sigaction(SIGUSR2, &siga, NULL);
	}
	return (0);
}
