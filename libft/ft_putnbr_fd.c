/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdudas <zdudas@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 20:43:18 by zdudas            #+#    #+#             */
/*   Updated: 2025/11/03 01:06:26 by zdudas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ft_putnbr_rec(long n, int fd)
{
	char	c;

	if (n >= 10)
		ft_putnbr_rec(n / 10, fd);
	c = '0' + (n % 10);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nl;
	char	c;

	nl = n;
	if (nl < 0)
	{
		write(fd, "-", 1);
		nl = -nl;
	}
	if (nl >= 10)
		ft_putnbr_rec(nl / 10, fd);
	{
		c = '0' + (nl % 10);
		write(fd, &c, 1);
	}
}
