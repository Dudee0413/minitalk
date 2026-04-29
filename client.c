#include <unistd.h>
#include "libft/libft.h"
#include <signal.h>

void send_char(int pid, char c)
{
	int i = 7;
	int bit;

	while(i >= 0)
	{		
		bit = (c >> i) & 1;
		if(bit == 0)
			kill(pid, SIGUSR1);
		else if(bit == 1)
			kill(pid, SIGUSR2);
		usleep(300);
		i--;
	}
}




int main(int argc, char **argv)
{
	int pid;

	if (argc != 2)
	{
		ft_putstr_fd("Error argc is not 2", 1);
		return(1);
	}

	pid = ft_atoi(argv[1]);

	send_char(pid, 'A');
}
