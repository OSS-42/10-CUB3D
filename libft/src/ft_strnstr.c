/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:30:54 by ewurstei          #+#    #+#             */
/*   Updated: 2022/04/08 14:52:53 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	char	*src;

	src = (char *)haystack;
	i = 0;
	if (needle[i] == '\0')
		return (src);
	while (haystack[i] != '\0' && i < n)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] == needle[j] && (i + j) < n)
			{
				if (needle[j + 1] == '\0')
					return (&src[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
