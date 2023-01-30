/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:53:34 by ewurstei          #+#    #+#             */
/*   Updated: 2022/05/25 10:53:34 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_search(char *string, char c)
{
	if (!string)
		return (NULL);
	while (*string || *string == c)
	{
		if (*string == (char)c)
			return ((char *)string);
		++string;
	}
	return (NULL);
}

size_t	ft_lenght(char *string)
{
	size_t	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
		i++;
	return (i);
}

char	*ft_join(char *stash, char *buffer)
{
	char	*dst;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!stash)
	{
		stash = (char *)malloc(sizeof(char) * 1);
		stash[0] = '\0';
	}
	if (!stash || !buffer)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_lenght(stash) + ft_lenght(buffer) + 1));
	if (!dst)
		return (NULL);
	if (stash)
		while (stash[++i] != '\0')
			dst[i] = stash[i];
	while (buffer[j] != '\0')
		dst[i++] = buffer[j++];
	dst[ft_lenght(stash) + ft_lenght(buffer)] = '\0';
	free (stash);
	return (dst);
}
