/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_ptr_realloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:18:04 by ewurstei          #+#    #+#             */
/*   Updated: 2023/01/09 12:33:53 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

//	if (tab)
//		free_dbl_ptr((void **)tab);

char	**ft_dbl_ptr_realloc(char **tab, int size)
{
	tab = ft_calloc(size, sizeof(char *));
	return (tab);
}
