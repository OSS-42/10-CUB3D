/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:41:57 by momo              #+#    #+#             */
/*   Updated: 2022/11/25 09:12:52 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strcmp(char *str, char *cmp)
{
	unsigned int	i;

	i = 0;
	while (str[i] == cmp[i] && str[i] && cmp[i])
		i++;
	return ((unsigned char)str[i] - (unsigned char)cmp[i]);
}
