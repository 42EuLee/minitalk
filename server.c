#include "libft.h"
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

static void	sigaction_handler(int signo, siginfo_t *info, void *u)
{
	static int	bc;
	static char	c;
	static int	signal_pid;

	(void)u;
	signal_pid = info->si_pid;
	if (signo == SIGUSR1)
		c = c | (1 << (7 - bc));
	bc++;
	if (bc == 8)
	{
		if (c == '\0')
			kill(signal_pid, SIGUSR1);
		write(1, &c, 1);
		c = 0;
		bc = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = sigaction_handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_putstr_fd("The server PID is: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
