/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdudas <zdudas@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 22:49:25 by zdudas            #+#    #+#             */
/*   Updated: 2026/04/27 22:49:27 by zdudas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>

static volatile sig_atomic_t	g_ack = 0;

void	ack_handler(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 1;
	else if (sig == SIGUSR2)
		g_ack = -1;
}

void	send_char(int pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		g_ack = 0;
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ack)
			usleep(100);
		if (g_ack == -1)
			exit(1);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	signal(SIGUSR1, ack_handler);
	signal(SIGUSR2, ack_handler);
	i = 0;
	if (argc != 3)
	{
		ft_putstr_fd("Error argc is not 3", 1);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
