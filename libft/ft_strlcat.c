/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdudas <zdudas@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:07:26 by zdudas            #+#    #+#             */
/*   Updated: 2025/11/02 16:57:22 by zdudas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	dst_len = i;
	while (src[j])
		j++;
	src_len = j;
	if (size == 0 || dst_len >= size)
		return (size + src_len);
	j = 0;
	while (src[j] && (dst_len + j) < (size - 1))
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	dst[dst_len + j] = '\0';
	return (dst_len + src_len);
}
/*
#include <stdio.h>

int main(void)
{
	char dest1[20] = "Hello ";
	size_t result1 = ft_strlcat(dest1, "World", 20);
	printf("ft_strlcat 1: %s (len=%zu)\n", dest1, result1);

	char dest2[10] = "Hi";
	size_t result2 = ft_strlcat(dest2, " 42Vienna", 10);
	printf("ft_strlcat 2: %s (len=%zu)\n", dest2, result2);

	char dest3[5] = "";
	size_t result3 = ft_strlcat(dest3, "Test", 5);
	printf("ft_strlcat 3: %s (len=%zu)\n", dest3, result3);
}
*/
