/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdudas <zdudas@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 22:48:30 by zdudas            #+#    #+#             */
/*   Updated: 2026/05/08 23:39:39 by zdudas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include <signal.h>

static void	reset_message(char *c, int *bit_count)
{
	*c = 0;
	*bit_count = 0;
}

static void	process_bit(int signal, char *c, int *bit_count)
{
	*c <<= 1;
	if (signal == SIGUSR2)
		*c |= 1;
	(*bit_count)++;
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static char	c;
	static int	bit_count;
	static int	current_pid;

	(void)context;
	if (current_pid == 0)
		current_pid = info->si_pid;
	if (info->si_pid != current_pid)
	{
		kill(info->si_pid, SIGUSR2);
		return ;
	}
	process_bit(signal, &c, &bit_count);
	if (bit_count == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			current_pid = 0;
		}
		else
			write(1, &c, 1);
		reset_message(&c, &bit_count);
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("Server ID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
