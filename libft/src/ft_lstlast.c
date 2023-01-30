/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:18:55 by ewurstei          #+#    #+#             */
/*   Updated: 2022/04/21 11:17:46 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	unsigned int	count;
	unsigned int	i;

	if (!lst)
		return (NULL);
	count = ft_lstsize(lst);
	i = 0;
	while (i < count - 1)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
