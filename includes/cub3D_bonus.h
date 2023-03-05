/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:34:40 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/05 12:26:45 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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
# define WIDTH 1280
# define HEIGHT 720
# define TEXWIDTH 64
# define TEXHEIGHT 64
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
	double	row;
	double	col;
	int		old_row;
	int		old_col;
	int		ppx;
	int		ppy;
	double	pdx;
	double	pdy;
	char	direction;
}	t_player;

typedef struct s_rays
{
	double	pdx_ray;
	double	pdy_ray;
	double	delta_dist_x;
	double	delta_dist_y;
	double	screen_2d_x;
	int		map_2d_col;
	int		map_2d_row;
	int		col;
	int		row;
	double	ray_len_x;
	double	ray_len_y;
	int		side;
	double	ray_len;
	double	plane_x;
	double	plane_y;
	double	rot_speed;
	double	mov_speed;
}	t_rays;

typedef struct s_map
{
	char	**map;
	char	**temp_map;
	int		*map2d;
	int		lines;
	int		max_lenght;
}	t_map;

typedef struct s_minimap
{
	void		*start;
	int			x;
	int			y;
	int			img_x;
	int			img_y;
	int			on_screen;
	mlx_image_t	*minimap;
	double		tile_size;
}	t_minimap;

#define numSprites 19

typedef struct s_sprites
{
	double	sprite_x;
	double	sprite_y;
	unsigned int		texture;
}	t_sprites;

typedef struct s_sp_param
{
	double 	ZBuffer[WIDTH];
	int		spriteOrder[numSprites];
	double 	spriteDistance[numSprites];
	double 	spriteX;
	double 	spriteY;
	double	transformX;
	double	transformY;
	int		spriteScreenX;
	int		spriteHeight;
	int		drawStartY;
	int		drawEndY;
	int		spriteWidth;
	int		drawStartX;
	int		drawEndX;
}	t_sp_param;


typedef struct s_game
{
	mlx_image_t		*ddd;
	char			*wall_n;
	char			*wall_s;
	char			*wall_e;
	char			*wall_w;
	int				wall_height;
	int				wall_start;
	int				wall_end;
	unsigned int	wall_color;
	int				tex_x;
}	t_game;

typedef struct s_tex
{
	xpm_t		*tex_n;
	xpm_t		*tex_s;
	xpm_t		*tex_e;
	xpm_t		*tex_w;
	xpm_t		*tex_window;
	xpm_t		*tex_local;
	xpm_t		*tex_lobby;
	xpm_t		*tex_reunion;
	xpm_t		*tex_cuisine;
	xpm_t		*tex_jeux;
	xpm_t		*tex_couloir;
	xpm_t		*tex_detente;
	xpm_t		*tex_c1;
	xpm_t		*tex_c2;
	xpm_t		*tex_c3;
	xpm_t		*tex_lounge;
	xpm_t		*tex_bocal;
	xpm_t		*tex_amphi;
	xpm_t		*tex_secret;
	xpm_t		*tex_door;
	xpm_t		*tex_dungeon;
	xpm_t		*tex_tribute;
	xpm_t		*tex_marc;
	xpm_t		*tex_armada;
	xpm_t		*tex_torrent;
	xpm_t		*tex_wall;
	xpm_t		*tex_mbertin;
	xpm_t		*tex_ewurstei;
	int			**north;
	int			**south;
	int			**east;
	int			**west;
	int			**local;
	int			**window;
	int			**lobby;
	int			**lounge;
	int			**cuisine;
	int			**reunion;
	int			**jeux;
	int			**couloir;
	int			**detente;
	int			**c1;
	int			**c2;
	int			**c3;
	int			**bocal;
	int			**amphi;
	int			**secret;
	int			**door;
	int			**dungeon;
	int			**tribute;
	int			**armada;
	int			**marc;
	int			**torrent;
	int			**wall;
	int			**mbertin;
	int			**ewurstei;
	double		brightness_factor;
	uint32_t	dark;
	uint32_t	color;
	double		step;
	double		tex_pos;
	int			tex_y;
}	t_tex;

typedef struct s_hud_loc
{
	int			hud_height;
	int			location;
	int			**p_loc;
	xpm_t		*tex_p_loc;
	mlx_image_t	*hud_loc_static;
	mlx_image_t	*hud_loc_dynamic;
}	t_hud_loc;

typedef struct s_param
{
	char			*no_wall_path;
	int				no_exist;
	char			*so_wall_path;
	int				so_exist;
	char			*we_wall_path;
	int				we_exist;
	char			*ea_wall_path;
	int				ea_exist;
	int				f_exist;
	int				c_exist;
	char			*f_color;
	char			*c_color;
	int				r_ceiling;
	int				g_ceiling;
	int				b_ceiling;
	int				a_ceiling;
	int				r_floor;
	int				g_floor;
	int				b_floor;
	int				a_floor;
	unsigned int	hex_ceiling;
	unsigned int	hex_floor;
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
	int			audio;
	int			old_x_cursor;
	t_player	*plr;
	t_param		*scene_param;
	t_map		*map;
	t_point		*size;
	t_point		*actual;
	t_minimap	*minimap;
	t_game		*game;
	t_hud_loc	*hud_loc;
	t_rays		*raycaster;
	t_tex		*tex;
	mlx_image_t	*cursor;
	t_sp_param	*sp_param;
}	t_vault;

/***** FONCTIONS *****/

/***** cub3D.c *****/
int			create_game(t_vault *data);
void		init_data(t_vault *data, char **argv);
void		quit_game(t_vault *data);

/***** error_management.c *****/
void		errors(t_vault *data);
void		errors_2(t_vault *data);
void		free_map(t_vault *data);
void		destroy_and_free_level(t_vault *data);
void		free_all(t_vault *data);

/***** scene_parsing.c *****/
void		check_scene_name(t_vault *data);
void		scene_to_array(t_vault *data);
void		check_scene_params(t_vault *data);
void		check_scene_syntax(t_vault *data, int *x);
void		check_random_scene_params(t_vault *data, int i);

/***** scene_parsing_utils.c *****/
void		check_fd(t_vault *data, int fd);
int			check_param_existence(t_vault *data);
void		skip_white_space(t_vault *data, int x, int y, int *slen);
int			isinset(char *s1, char *set);
void		check_valid_char(t_vault *data, int x);

/***** check_orientation_params.c *****/
void		check_no_params(t_vault *data, int x, int y, int slen);
void		check_so_params(t_vault *data, int x, int y, int slen);
void		check_we_params(t_vault *data, int x, int y, int slen);
void		check_ea_params(t_vault *data, int x, int y, int slen);

/***** check_fc_params.c *****/
void		check_f_params(t_vault *data, int x, int y, int slen);
void		check_c_params(t_vault *data, int x, int y, int slen);
void		check_color_code(t_vault *data);
int			correct_rgb_char(char *rgb_code);

/***** cub3d_utils.c *****/
int			check_white_spaces(char c);
int			ft_find_char(char *src, char c);
void		correct_rgb_range(t_vault *data, char *rgb_code, char c);
void		rgb_to_hex(t_vault *data, char flag);
int			rgb_to_hex2(int r, int g, int b, int a);

/***** map_parsing.c *****/
void		check_map(t_vault *data);
void		find_player_start(t_vault *data);
void		fill_map_void(t_vault *data);
void		replace_voids(t_vault *data, int x);
void		fill_rest_of_line(t_vault *data, int x);

/***** map_parsing_utils.c *****/
void		map_to_new_array(t_vault *data, int x);
void		find_map_start(t_vault *data);
void		map_max_lenght(t_vault *data);

/***** check_ceiling_rgb.c *****/
void		extract_r_ceiling(t_vault *data, char *rgb_code, int *i, int *len);
void		extract_g_ceiling(t_vault *data, char *rgb_code, int *i, int *len);
void		extract_b_ceiling(t_vault *data, char *rgb_code, int *i, int *len);

/***** check_floor_rbg.c *****/
void		extract_r_floor(t_vault *data, char *rgb_code, int *i, int *len);
void		extract_g_floor(t_vault *data, char *rgb_code, int *i, int *len);
void		extract_b_floor(t_vault *data, char *rgb_code, int *i, int *len);

/***** flood_fill *****/
void		flood_fill(t_vault *data, int x, int y, char **temp);

/***** init_player.c *****/
void		load_player(t_vault *data);
void		init_player(t_vault *data);
void		find_orientation(t_vault *data, char direction);
void		find_orientation_2(t_vault *data, char direction);
void		draw_player(t_vault *data);

/***** init_hud.c *****/
void		load_hud(t_vault *data);
void		draw_hud(t_vault *data);
void		draw_tex_location(t_vault *data, xpm_t *texture, int **tex_buff,
				int pixels_2d);
void		draw_tex_location2(t_vault *data, xpm_t *texture, int **tex_buff,
				int pixels_2d);

/***** raycasting.c *****/
void		raycaster(t_vault *data);
void		dda(t_vault *data);
void		creating_3d_img(t_vault *data, int pixels_2d);
void		dist_and_pos(t_vault *data);
void		dist_and_pos2(t_vault *data);

/***** check_wall_texture_bonus.c *****/
void		check_type_wall(t_vault *data, int *impact);
void		check_bonus_type_wall(t_vault *data, int *impact);
void		check_type_wall_d(t_vault *data, int *impact);
void		check_type_wall_3(t_vault *data, int *impact);
void		check_type_wall_4(t_vault *data, int *impact);

/***** check_wall_texture_bonus2.c *****/
void		check_type_wall_5(t_vault *data, int *impact);
void		check_type_wall_6(t_vault *data, int *impact);
void		check_type_wall_7(t_vault *data, int *impact);
void		check_type_wall_8(t_vault *data, int *impact);
void		check_type_wall_9(t_vault *data, int *impact);
void		check_type_wall_z(t_vault *data, int *impact);

/***** check_wall_texture_bonus3.c *****/

/***** draw_wall_texture_bonus.c *****/
void		draw_tex_wall(t_vault *data, int pixels_2d);
void		draw_tex_wall_2(t_vault *data, int pixels_2d);
void		draw_tex_wall_3(t_vault *data, int pixels_2d);
void		draw_tex_wall_4(t_vault *data, int pixels_2d);

/***** textures.c *****/
void		load_textures(t_vault *data);
int			**get_texture(xpm_t *tex);
void		draw_line(t_vault *data, xpm_t *texture, int **tex_buff,
				int pixels_2d);
double		calculate_brightness_factor(t_vault *data);
uint32_t	darken_color(uint32_t color, double brightness_factor,
				uint32_t dark_color);

/***** textures_utils.c *****/
void		find_tex_hit(t_vault *data, xpm_t *texture);
void		find_tex_hit2(t_vault *data, xpm_t *texture, int side);

/***** utils_bonus.c *****/
void		check_wall_path(t_vault *data);
void		full_line_hud_hor(mlx_image_t *hud, int screen_y,
				unsigned int color);
void		full_line_hud_ver(mlx_image_t *hud, int screen_x,
				unsigned int color);
void		reinit_and_draw(t_vault *data);
int			is_not_wall(t_vault *data, int row, int col);

/***** extra_textures.c *****/
void		load_extra_textures(t_vault *data);
void		check_extra_textures(t_vault *data);
void		get_extra_textures(t_vault *data);

/***** init_minimap.c *****/
void		reinit_minimap(t_vault *data);
void		show_minimap(t_vault *data);
void		load_minimap(t_vault *data);
void		draw_minimap(t_vault *data);
void		draw_tiles_loop(t_vault *data, int screen_x, int screen_y);

/***** minimap_utils.c *****/
void		draw_tiles(t_vault *data,
				int screen_x, int screen_y, unsigned int color);
void		full_line_minimap_hor(t_vault *data, int screen_y,
				unsigned int color);
void		full_line_minimap_ver(t_vault *data, int screen_x,
				unsigned int color);
void		draw_ray_minimap(t_vault *data);

/***** moves.c *****/
void		move_forward(t_vault *data, int check_row, int check_col);
void		move_backward(t_vault *data, int check_row, int check_col);
void		move_left(t_vault *data, int check_row, int check_col);
void		move_right(t_vault *data, int check_row, int check_col);
void		move_mouse(double x, double y, void *temp);

/***** camera.c *****/
void		reinit_hud(t_vault *data);
void		draw_pov(t_vault *data);
void		rotate_left(t_vault *data);
void		rotate_right(t_vault *data);

/***** init_3d.c *****/
void		load_3d(t_vault *data);
void		reinit_3d(t_vault *data);
void		background_3d(t_vault *data);

/***** audio.c *****/
void		play_song(t_vault *data);
void		check_and_play_song(t_vault *data);

/***** keyhandler.c *****/
void		keyhandler(mlx_key_data_t keydata, void *param);
void		keyhandler_2(mlx_key_data_t keydata, t_vault *data);
void		open_door(t_vault *data);

/***** sprites_bonus.c *****/
void		sprite_casting(t_vault *data);
int			compareSprites(t_sprites *a, t_sprites *b);
void		sortSprites(int *order, double *dist, int amount);
void		draw_sprite(t_vault *data, xpm_t *texture, int **tex_buff);

/***** player_location_bonus.c *****/
void		player_location(t_vault *data, int col, int row);
void		player_location_2(t_vault *data, int col, int row);
void		player_location_3(t_vault *data, int col, int row);
void		player_location_4(t_vault *data, int col, int row);

// /***** sprites_bonus.c *****/
// void	sprite_casting(t_vault *data);
// int		compareSprites(t_sprites *a, t_sprites *b);
// void	sortSprites(int *order, double *dist, int amount);
// void	draw_sprite(t_vault *data, xpm_t *texture, int **tex_buff);

/***** sprites2_bonus.c *****/
void	sprite_casting(t_vault *data);
void	distance_to_camera(t_vault *data, t_sprites *sprite);
void	transform_inverse_matrix(t_vault *data);
void	calculate_sprite_height(t_vault *data);
void	calculate_sprite_width(t_vault *data);
void	draw_sprite(t_vault *data, int **tex_buff);
void	sort_sprites(int *order, double *distance, int count);

#endif