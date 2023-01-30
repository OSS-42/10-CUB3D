/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:42:19 by ewurstei          #+#    #+#             */
/*   Updated: 2022/04/08 09:57:06 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*src;

	src = (char *)s;
	len = ft_strlen(src);
	if (c == 0)
		return (&src[len]);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return (&src[len]);
		len--;
	}
	return (NULL);
}
