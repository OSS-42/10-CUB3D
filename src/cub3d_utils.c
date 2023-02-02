/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:21:15 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/02 13:32:42 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	correct_rgb_char(char *rgb_code)
{
	int	x;

	x = 0;
	while (rgb_code && rgb_code[x])
	{
		while (rgb_code[x] == ' ')
		{
			x++;
			if (rgb_code[x] == '\0')
				return (0);
		}
		if (ft_isdigit(rgb_code[x]) == 1 || rgb_code[x] == ',')
			x++;
		else
			return (0);
	}
	return (1);
}

// on ne gere pas si le code rgb a plus que ou moins que 3 parametres
int	correct_rgb_range(char *rgb_code)
{
	int		code_r;
	int		code_g;
	int		code_b;
	int		x;
	int		len;
	char	*temp;

	code_r = 0;
	code_g = 0;
	code_b = 0;
	x = 0;
	len = 0;
	temp = NULL;
	while (rgb_code && rgb_code[x] && rgb_code[x] != ',')
	{
		if (ft_isdigit(rgb_code[x]) == 1)
			x++;
	}
	temp = ft_substr(rgb_code, len, x - len);
	code_r = ft_atoi(temp);
	free (temp);
	x++;
	len = x;
	while (rgb_code && rgb_code[x] && rgb_code[x] != ',')
	{
		if (ft_isdigit(rgb_code[x]) == 1)
			x++;
	}
	temp = ft_substr(rgb_code, len, x - len);
	code_g = ft_atoi(temp);
	free (temp);
	x++;
	len = x;
	while (rgb_code && rgb_code[x] && rgb_code[x] != ',')
	{
		if (ft_isdigit(rgb_code[x]) == 1)
			x++;
	}
	temp = ft_substr(rgb_code, len, x - len);
	code_b = ft_atoi(temp);
	free (temp);
	temp = NULL;
	if (code_r > 255 || code_g > 255 || code_b > 255
		|| code_r < 0 || code_g < 0 || code_b < 0)
		return (0);
	return (1);
}

int	check_white_spaces(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f'
		|| c == ' ')
		return (0);
	return (1);
}

// void	map_to_new_array(t_vault *data, int x)
// {
// 	int	line;

// 	line = x;
// 	while (data->scene[line])
// 		line++;
// 	data->map->map = ft_calloc(line - x + 1, sizeof(char *));
// 	line = 0;
// 	while (data->scene[x])
// 	{
// 		data->map->map[line] = ft_strdup(data->scene[x]);
// 		line++;
// 		x++;
// 	}
// 	data->map->lines = line;
// }
