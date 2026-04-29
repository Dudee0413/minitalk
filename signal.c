#include <unistd.h>
#include "libft/libft.h"
#include "signal.h"

void signal_handler(int signal)
{
	if (signal == SIGUSR1)
		write(1, "0", 1);
	else if (signal == SIGUSR2)
		write(1, "1", 1);
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
