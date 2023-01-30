/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:05:14 by ewurstei          #+#    #+#             */
/*   Updated: 2022/04/13 09:40:17 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_size(long nb);

int	ft_size(long nb)
{
	int	count;

	count = 1;
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb / 10 > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*dst;
	int		size;
	long	nb;

	nb = n;
	size = ft_size(n);
	dst = (char *)malloc(sizeof(char) * (size + 1));
	if (!dst)
		return (NULL);
	dst[size] = '\0';
	if (nb == 0)
		dst[0] = 48;
	if (nb < 0)
	{
		dst[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		dst[size - 1] = 48 + nb % 10;
		nb = nb / 10;
		size--;
	}
	return (dst);
}
