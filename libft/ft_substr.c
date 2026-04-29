/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdudas <zdudas@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:55:57 by zdudas            #+#    #+#             */
/*   Updated: 2025/11/02 22:27:53 by zdudas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		return (ft_calloc(1, 1));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
#include <stdio.h>

int main(void)
{
    char *s = "Hello, 42 Vienna!";
    char *sub;

    // Kivágás a 7. index-től (az '4'-től), max 8 karakter
    sub = ft_substr("", 0, 0);
    if (!sub)
    {
        printf("Error allocating memory\n");
        return (1);
    }
    printf("Eredeti string: %s\n", s);
    printf("Részstring: %s\n", sub);

    free(sub); // fontos felszabadítani a malloc által lefoglalt memóriát

    return (0);
}
*/
