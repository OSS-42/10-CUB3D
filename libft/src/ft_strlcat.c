/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:41:09 by ewurstei          #+#    #+#             */
/*   Updated: 2022/04/20 11:43:00 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	i = 0;
	j = ft_strlen(dest);
	dlen = j;
	slen = ft_strlen((char *)src);
	if (dstsize <= 0)
		return (slen);
	if (dlen > dstsize)
		return (dstsize + slen);
	while (src[i] != '\0' && j < dstsize - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dlen + slen);
}

/*
int main (void)
{
	char	dest[30];
	dest[0] = 'B';
	memset(dest, 0, 30);
	printf("mine : %zu\n", ft_strlcat(dest, "123", 0));
	printf("libc : %zu\n", strlcat(dest, "123", 0));
	printf("mem : %s\n", dest);
	return (0);
}
*/