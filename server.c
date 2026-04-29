#include <unistd.h>
#include "libft/libft.h"
#include "signal.h"

void signal_handler(int signal)
{
	static char c;
	static int bit_count;

	if (signal == SIGUSR1)
		c <<= 1;
	else if (signal == SIGUSR2)
	{
		c <<= 1;
		c |= 1;
	}
	bit_count++;
	if(bit_count == 8)
	{
		write(1, &c, 1);
		bit_count = 0;
		c = 0;
	}
}


int main(void)
{
	ft_putstr_fd("Server ID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while(1)
		pause();
}
