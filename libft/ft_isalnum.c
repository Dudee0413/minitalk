/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdudas <zdudas@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:43:39 by zdudas            #+#    #+#             */
/*   Updated: 2025/11/02 14:46:38 by zdudas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
	printf("ft_isalnum: %d\n", ft_isalnum('A'));
	printf("ft_isalnum: %d\n", ft_isalnum('5'));
	printf("ft_isalnum: %d\n", ft_isalnum(' '));
}
*/
