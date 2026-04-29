/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdudas <zdudas@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:29:27 by zdudas            #+#    #+#             */
/*   Updated: 2025/11/02 14:58:00 by zdudas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *c)
{
	size_t	len;

	len = 0;
	while (c[len] != '\0')
		len++;
	return (len);
}
/*
#include <stdio.h>

int main(void)
{
	printf("ft_strlen: %zu\n", ft_strlen("Hello"));
	printf("ft_strlen: %zu\n", ft_strlen("Vienna"));
}
*/
