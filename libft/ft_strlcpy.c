/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdudas <zdudas@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:51:47 by zdudas            #+#    #+#             */
/*   Updated: 2025/11/02 16:36:19 by zdudas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
/*
#include <stdio.h>

int main(void)
{
	char dest[10];
	ft_strlcpy(dest, "CopyTest", 10);
	printf("ft_strlcpy: %s\n", dest);

	char small[5];
	ft_strlcpy(small, "Overflow!", 5);
	printf("ft_strlcpy (cut): %s\n", small);
}
*/
