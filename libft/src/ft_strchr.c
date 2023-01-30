/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:27:24 by ewurstei          #+#    #+#             */
/*   Updated: 2022/04/08 09:14:38 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	char	*src;
	size_t	i;
	size_t	len;

	src = (char *)s;
	len = ft_strlen(src);
	a = (char)c;
	i = 0;
	while (i <= len)
	{
		if (src[i] == a)
			return (&src[i]);
		i++;
	}
	return (NULL);
}
