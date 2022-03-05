#include "libft.h"
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

void	return_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	handler(int sig)
{
	(void)sig;
	write(1, "Message received from server.\n", 30);
}

int	char_to_bin(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
		{
			if (!(kill(pid, SIGUSR1) == 0))
				return_error();
		}
		else
		{
			if (!(kill(pid, SIGUSR2) == 0))
				return_error();
		}
		i--;
		usleep(150);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*str;

	if (argc != 3)
		return (0);
	str = argv[2];
	signal(SIGUSR1, handler);
	if (kill(ft_atoi(argv[1]), 0) == -1)
		return (0);
	i = 0;
	while (str[i])
	{
		char_to_bin(ft_atoi(argv[1]), str[i]);
		i++;
	}
	char_to_bin(ft_atoi(argv[1]), '\0');
}
