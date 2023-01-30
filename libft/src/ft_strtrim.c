/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:21:12 by ewurstei          #+#    #+#             */
/*   Updated: 2022/04/12 19:41:17 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_isinset(const char *set, const char c);

int	ft_isinset(const char *set, const char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	slen1;
	size_t	delstart;
	size_t	delend;
	char	*dst;

	if (!s1 || !set)
		return (NULL);
	slen1 = ft_strlen((char *)s1);
	i = -1;
	delstart = 0;
	while (++i < slen1 && ft_isinset(set, s1[i]) == 1)
		delstart++;
	if (slen1 - delstart == 0)
		return (ft_strdup(""));
	delend = 0;
	while (slen1 - 1 > 0 && ft_isinset(set, s1[slen1 - 1]) == 1)
	{
		delend++;
		slen1--;
	}
	return (dst = ft_substr((char *)s1, delstart, (slen1 - delstart)));
}
