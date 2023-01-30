/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:34:40 by ewurstei          #+#    #+#             */
/*   Updated: 2023/01/30 10:25:48 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libart/includes/libart.h"
# include "../libft/includes/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
// # include "../MLX42/include/MLX42/MLX42_Int.h"
// # include "../MLX42/include/MLX42/MLX42_Input.h"
// # include "../MLX42/include/glad/glad.h"
// # include "../MLX42/include/KHR/khrplatform.h"
// # include "../MLX42/include/lodepng/lodepng.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_player
{
	void	*p_right;
	void	*p_left;
}	t_player;

typedef struct s_level
{
	void	*corner_1;
	void	*corner_2;
	void	*corner_3;
	void	*corner_4;
	void	*wall_left;
	void	*wall_right;
	void	*wall_top;
	void	*wall_bottom;
	void	*floor;
	void	*pilar;
	void	*collect;
	void	*start;
	void	*exit;
	int		x;
	int		y;
	int		img_x;
	int		img_y;
}	t_level;

typedef struct s_vault
{
	void		*img;
	void		*mlx;
	void		*mlx_win;
	char		**map;
	char		*argv;
	int			error_code;
	int			char_check;
	int			char_p;
	int			char_e;
	int			width;
	int			height;
	int			lines;
	int			lenght;
	int			moves;
	int			collect;
	int			total_c;
	int			player_x;
	int			player_y;
	int			p_dir;
	t_player	*player;
	t_level		*lvl1;
}	t_vault;

#endif