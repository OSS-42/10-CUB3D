/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:33:50 by ewurstei          #+#    #+#             */
/*   Updated: 2023/01/30 12:45:53 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_map_name(t_vault *data)
{
	char	*filename;
	int		fd;

	fd = open(data->argv, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		data->error_code = 12;
		errors(data);
	}
	filename = ft_strrchr(data->argv, '.');
	if (filename == NULL)
	{
		data->error_code = 8;
		errors(data);
	}
	if (ft_strncmp(filename, ".cub", ft_strlen(filename)) != 0)
	{
		data->error_code = 8;
		errors(data);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_vault	data;

	(void)argc;
	(void)argv;
	(void)env;
	data.error_code = 0;
	if (argc != 2)
		data.error_code = 9;
	errors(&data);
	data.argv = argv[1];
	check_map_name(&data);
	// map_to_array(&data);
	// check_map(&data);
	errors(&data);
	// newgame(&data);
	printf("hello\n");
	return (0);
}
