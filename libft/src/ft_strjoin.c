/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:43:27 by ewurstei          #+#    #+#             */
/*   Updated: 2022/04/12 10:13:44 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	slen1;
	size_t	slen2;
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	slen1 = ft_strlen((char *)s1);
	slen2 = ft_strlen((char *)s2);
	dst = (char *)malloc(sizeof(char) * (slen1 + slen2 + 1));
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < slen1)
	{
		dst[i] = s1[i];
	}
	j = -1;
	while (++j < slen2)
	{
		dst[i + j] = s2[j];
	}
	dst[i + j] = '\0';
	return (dst);
}
