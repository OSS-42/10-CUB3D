/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:15:45 by ewurstei          #+#    #+#             */
/*   Updated: 2023/01/05 21:27:38 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_str_env_var(char *str, char delimiter)
{
	int	i;

	i = 0;
	if (delimiter == 0)
		(void) delimiter;
	if (ft_isdigit(str[i]) == 1 || str[i] == delimiter)
		return (0);
	while (str[i] && str[i] != delimiter)
	{
		if (str[i] != '_' && (ft_isalnum(str[i])) == 0)
			return (0);
		i++;
	}
	return (1);
}
