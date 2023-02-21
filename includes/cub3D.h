/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:34:40 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/21 14:01:42 by mbertin          ###   ########.fr       */
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
# include <math.h>

# define TRUE 1
# define FALSE 0
# define PI 3.1415926535
# define WIDTH 1020
# define HEIGHT 780
# define TILE 11
# define P_OFFSET 4
# define RED 0xFF0000FF
# define YELLOW 0xFFFF00FF
# define GREEN 0x00FF00FF
# define BLUE 0x00FFFFFF
# define DGRAY 0x3C3C3FFF
# define LGRAY 0x89898DFF

/***** STRUCTURES *****/

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	void	*p_right;
	void	*p_left;
	int		start_x;
	int		start_y;
	double	px;
	double	py;
	int		ppx;
	int		ppy;
	double	pdx;
	double	pdy;
	double	pdlen;
	double	pa;
	char	direction;
}	t_player;

typedef struct s_rays
{
	double	pdx_ray;
	double	pdy_ray;
	int		dist_x;
	int		dist_y;
	double	ray_len;
	double	last_ray_len;
	double	ray_one_a;
	double	plane_x; // y du plan 'FOV' du joueur --> va etre modifie avec le deplacement du joueur.
	double	plane_y; // x du plan 'FOV' du joueur --> va etre modifie avec le deplacement du joueur.
}	t_rays;

typedef struct s_map
{
	char	**map;
	int		*map2d;
	int		lines;
	int		max_lenght;
}	t_map;

typedef struct s_minimap
{
	xpm_t		*wall;
	xpm_t		*floor;
	xpm_t		*player;
	xpm_t		*floor_void;
	void		*start;
	int			x;
	int			y;
	int			img_x;
	int			img_y;
	mlx_image_t	*minimap;
}	t_minimap;

typedef struct s_game
{
	mlx_image_t	*ddd;
}	t_game;

typedef struct s_hud
{
	int			lives_count;
	int			collected;
	int			total_c;
	mlx_image_t	*lives;
	mlx_image_t	*hud;
}	t_hud;

typedef struct s_level
{
	void		*corner_1;
	void		*corner_2;
	void		*corner_3;
	void		*corner_4;
	void		*wall_left;
	void		*wall_right;
	void		*wall_top;
	void		*wall_bottom;
	void		*floor;
	void		*pilar;
	void		*collect;
	void		*start;
	void		*exit;
	int			x;
	int			y;
	int			img_x;
	int			img_y;
	mlx_image_t	*floor_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*player_img;
	mlx_image_t	*void_img;
}	t_level;

typedef struct s_param
{
	char	*no_wall_path;
	int		no_exist;
	int		r_ceiling;
	int		g_ceiling;
	int		b_ceiling;
	int		r_floor;
	int		g_floor;
	int		b_floor;
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
	int		a_ceiling;
	int		a_floor;
}	t_param;

typedef struct s_vault
{
	void		*img;
	void		*mlx;
	void		*mlx_win;
	char		**scene;
	char		*argv;
	int			map_start;
	int			error_code;
	int			char_check;
	int			char_p;
	int			char_e;
	int			width;
	int			height;
	int			lines;
	int			lenght;
	int			p_dir;
	t_player	*player;
	t_level		*lvl1;
	t_param		*scene_param;
	t_map		*map;
	t_point		*size;
	t_point		*actual;
	t_minimap	*minimap;
	t_game		*game;
	t_hud		*hud;
	t_rays		*raycaster;
}	t_vault;

/***** FONCTIONS *****/

/***** cub3D.c *****/
int		create_game(t_vault *data);
void	keyhandler(mlx_key_data_t keydata, void *param);
void	init_data(t_vault *data, char **argv);
void	quit_game(t_vault *data);

/***** error_management.c *****/
void	errors(t_vault *data);
void	errors_2(t_vault *data);
void	free_map(t_vault *data);
void	destroy_and_free_level(t_vault *data);
void	destroy_and_free_player(t_vault *data);
void	free_all(t_vault *data);

/***** scene_parsing.c *****/
void	check_scene_name(t_vault *data);
void	scene_to_array(t_vault *data);
void	check_scene_params(t_vault *data);
void	check_scene_syntax(t_vault *data, int *x);

/***** scene_parsing_utils.c *****/
void	check_fd(t_vault *data, int fd);
int		check_param_existence(t_vault *data);
void	skip_white_space(t_vault *data, int x, int y, int *slen);
int		isinset(char *s1, char *set);
void	check_valid_char(t_vault *data, int x);

/***** check_orientation_params.c *****/
void	check_no_params(t_vault *data, int x, int y, int slen);
void	check_so_params(t_vault *data, int x, int y, int slen);
void	check_we_params(t_vault *data, int x, int y, int slen);
void	check_ea_params(t_vault *data, int x, int y, int slen);
void	check_wall_path(t_vault *data);

/***** check_fc_params.c *****/
void	check_f_params(t_vault *data, int x, int y, int slen);
void	check_c_params(t_vault *data, int x, int y, int slen);
void	check_color_code(t_vault *data);
int		correct_rgb_char(char *rgb_code);
void	correct_rgb_range(t_vault *data, char *rgb_code, char c);

/***** cub3d_utils.c *****/
void	map_to_new_array(t_vault *data, int x);
int		check_white_spaces(char c);
int		ft_find_char(char *src, char c);

/***** map_parsing.c *****/
void	check_map(t_vault *data);
void	find_player_start(t_vault *data);
void	fill_map_void(t_vault *data);
void	replace_voids(t_vault *data, int x);
void	fill_rest_of_line(t_vault *data, int x);

/***** map_parsing_utils.c *****/
void	map_to_new_array(t_vault *data, int x);
void	find_map_start(t_vault *data);
void	map_max_lenght(t_vault *data);

/***** check_ceiling_rgb.c *****/
void	extract_r_ceiling(t_vault *data, char *rgb_code, int *i, int *len);
void	extract_g_ceiling(t_vault *data, char *rgb_code, int *i, int *len);
void	extract_b_ceiling(t_vault *data, char *rgb_code, int *i, int *len);

/***** check_floor_rbg.c *****/
void	extract_r_floor(t_vault *data, char *rgb_code, int *i, int *len);
void	extract_g_floor(t_vault *data, char *rgb_code, int *i, int *len);
void	extract_b_floor(t_vault *data, char *rgb_code, int *i, int *len);

/***** init_assets_bonus.c *****/
void	load_minimap_assets(t_vault *data);

/***** flood_fill *****/
void	flood_fill(t_vault *data, int x, int y, char **temp);

/***** init_player.c *****/
void	load_player(t_vault *data);
void	init_player(t_vault *data);
void	find_orientation(t_vault *data, char direction);
void	draw_player(t_vault *data);

/***** init_hud.c *****/
void	load_hud(t_vault *data);
void	draw_hud(t_vault *data);
void	full_line_hud_hor(t_vault *data, int screen_y, unsigned int color);
void	full_line_hud_ver(t_vault *data, int screen_x, unsigned int color);

/***** raycasting.c *****/
void	raycaster(t_vault *data);
void	draw_ray_minimap(t_vault *data, float ray_len);
void	find_ray_angle(t_vault *data);
void	draw_wall_3d(t_vault *data, int wall_start, int wall_end, int  screen_2d_x, unsigned int wall_color);

/***** init_minimap.c *****/
void	load_minimap(t_vault *data);
void	draw_minimap(t_vault *data);
void	draw_tiles(t_vault *data,
			int screen_x, int screen_y, unsigned int color);
void	full_line_minimap_hor(t_vault *data, int screen_y, unsigned int color);
void	full_line_minimap_ver(t_vault *data, int screen_x, unsigned int color);

/***** moves.c *****/
void	reinit_minimap(t_vault *data);
void	move_forward(t_vault *data);
void	move_backward(t_vault *data);
void	move_left(t_vault *data);
void	move_right(t_vault *data);

/***** camera.c *****/
void	draw_pov(t_vault *data);
void	rotate_left(t_vault *data);
void	rotate_right(t_vault *data);

/***** raycasting_utils.c *****/
float	degtorad(float angle);
int		fix_angle(int angle);
// int		ray_seg_len_x(t_vault *data, int start_x, char flag);
// int		ray_seg_len_y(t_vault *data, int start_y, char flag);
// void	find_next_case(t_vault *data, int intersec_x, int intersec_y, char flag);
// int		wall_in_next_case(t_vault *data, int x, int y);

/***** init_3d.c *****/
void	load_3d(t_vault *data);

#endif