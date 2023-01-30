/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:54:25 by ewurstei          #+#    #+#             */
/*   Updated: 2023/01/19 20:48:56 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strappend(char *str, char c)
{
	int		i;
	int		len;
	char	*buffer;

	if (!str)
		return ("NULL");
	i = -1;
	len = 0;
	while (str[++i])
		len++;
	buffer = ft_calloc(sizeof(char), len + 2);
	i = -1;
	while (++i < len)
		buffer[i] = str[i];
	buffer[i] = c;
	return (buffer);
}

// int	main(void)
// {
// 	char	c;
// 	char	*str;
// 	char	*temp;

// 	c = '1';
// 	str = "hello";
// 	temp = ft_strappend(str, c);
// 	printf("%s\n", temp);
// 	free (temp);
// 	return (0);
// }
