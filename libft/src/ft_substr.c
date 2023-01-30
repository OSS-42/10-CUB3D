/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/04/11 21:02:55 by ewurstei          #+#    #+#             */
/*   Updated: 2022/04/11 21:02:55 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen((char *)s);
	if (slen < len)
		len = slen;
	if (slen <= start)
		len = 0;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	if (slen <= start)
	{
		dst[i] = '\0';
		return (dst);
	}
	i = -1;
	while (s[start + ++i] && i < len)
		dst[i] = s[start + i];
	dst[i] = '\0';
	return (dst);
}
