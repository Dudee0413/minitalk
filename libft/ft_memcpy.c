/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdudas <zdudas@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:45:32 by zdudas            #+#    #+#             */
/*   Updated: 2025/11/02 19:04:40 by zdudas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int main(void)
{
	char src[] = "Hello";
	char dest[6];
	ft_memcpy(dest, src, 6);
	printf("ft_memcpy: %s\n", dest);

	ft_memcpy(dest + 3, src, 3);
	printf("ft_memcpy: %s\n", dest);
}
*/
