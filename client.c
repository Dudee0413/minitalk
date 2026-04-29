#include <unistd.h>
#include "libft/libft.h"
#include <signal.h>

int main(int argc, char **argv)
{
	int pid;

	if (argc != 2)
	{
		ft_putstr_fd("Error argc is not 2", 1);
		return(1);
	}

	pid = ft_atoi(argv[1]);
	kill(pid, SIGUSR1);
	//kill(pid, SIGUSR2);
}
