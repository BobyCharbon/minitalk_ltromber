#include "minitalk.h"

void	ft_msg(char c, pid_t pid)
{
	int	i;

	i = 8;
	while (i)
	{
		i--;
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
	}
}

void	sigmsg(char *msg, pid_t pid)
{
	int	i;

	i = -1;
	while (msg[++i])
		ft_msg(msg[i], pid);
	exit(0);
}

int	t_atoi(const char *str)
{
	int	i;
	int	num;
	int	neg;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_printf("Write (./client), the server's pid and your message !");
		return (0);
	}
	pid = ft_atoi(av[1]);
	sigmsg(av[2], pid);
	while (1)
	{
		pause();
	}
	return (0);
}
