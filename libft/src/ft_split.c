/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:24:56 by ewurstei          #+#    #+#             */
/*   Updated: 2022/04/19 13:08:11 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
//#include <stdio.h>

static unsigned int	ft_wordcount(char *s, char c)
{
	unsigned int	i;
	unsigned int	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			wordcount++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wordcount);
}

static char	*ft_wordstring(char *s, int i, unsigned int wordlen)
{
	char			*word;
	unsigned int	pos;

	pos = 0;
	word = (char *)malloc(sizeof(char) * (wordlen + 1));
	if (!word)
		return (NULL);
	while (pos < wordlen)
	{
		word[pos] = s[i];
		pos++;
		i++;
	}
	word[pos] = '\0';
	return (word);
}

static unsigned int	ft_wordlen(char *s, int i, char c)
{
	unsigned int	wordlen;

	wordlen = 0;
	while (s[i + wordlen] && s[i + wordlen] != c)
		wordlen++;
	return (wordlen);
}

char	**ft_split(const char *s, char c)
{
	unsigned int	i;
	unsigned int	row;
	char			**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_wordcount((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	row = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			tab[row] = ft_wordstring((char *)s, i, ft_wordlen((char *)s, i, c));
			row++;
			i = i + ft_wordlen((char *)s, i, c);
		}
	}
	tab[row] = NULL;
	return (tab);
}

/*
int	main (void)
{
	char **tab;
	int i;

	i = 0;
	while (i < 10)
	{
		tab = ft_split("  OSS 117 - Alerte Rouge en Afrique Noire !", ' ');
		printf("ligne #%d : %s\n", i, tab[i]);
		i++;
	}
	return (0);
}
*/