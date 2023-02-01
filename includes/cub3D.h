/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:34:40 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/01 13:49:46 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libart/includes/libart.h"
# include "../libft/includes/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/***** STRUCTURES *****/

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

typedef struct s_param
{
	char	*no_wall_path;
	int		no_exist;
	char	*so_wall_path;
	int		so_exist;
	char	*we_wall_path;
	int		we_exist;
	char	*ea_wall_path;
	int		ea_exist;
	char	*f_color;
	int		f_exist;
	char	*c_color;
	int		c_exist;
}	t_param;

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
	int			collect;
	int			total_c;
	int			player_x;
	int			player_y;
	int			p_dir;
	t_player	*player;
	t_level		*lvl1;
	t_param		*map_param;
}	t_vault;

/***** cub3D.c *****/
int		create_win(t_vault *data);
void	keyhandler(mlx_key_data_t keydata, void *param);
void	quit_game(t_vault *data);

/***** error_management.c *****/
void	errors(t_vault *data);
void	free_map(t_vault *data);
void	destroy_and_free_level(t_vault *data);
void	destroy_and_free_player(t_vault *data);
void	free_all(t_vault *data);

/***** map_parsing.c *****/
void	check_map_name(t_vault *data);
void	check_fd(t_vault *data, int fd);
void	scene_to_array(t_vault *data);
void	check_map(t_vault *data); //relevance ? a integrer ailleurs
void	check_map_params(t_vault *data);
void	check_wall_path(t_vault *data);
void	check_color_code(t_vault *data);
int		check_param_existence(t_vault *data);
int		check_white_spaces(char c);
int		isinset(char *s1, char *set);
void	check_valid_char(t_vault *data);

/***** cub3d_utils.c *****/
int		correct_rgb_char(char *rgb_code);
int		correct_rgb_range(char *rgb_code);

#endif