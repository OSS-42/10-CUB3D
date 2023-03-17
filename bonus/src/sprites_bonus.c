/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:43:55 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/17 09:19:53 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

// -current-\-old-
//s_par \ sp_param
//s_ds_x \ drawStartX
//s_de_y \ drawEndY
//s_prio \ spriteOrder
//s_dist \ spriteDistance

void	sprite_casting(t_vault *data)
{
	int	i;

	i = -1;
	sprite_ordering(data);
	while (++i < NUMSPRITES)
	{
		sprite_computing(data, i);
		data->s_par->screen_x = data->s_par->s_ds_x;
		while (data->s_par->screen_x < data->s_par->s_de_x)
		{
			data->s_par->tex_sx = fabs((int)(256 * (data->s_par->screen_x
							- (-data->s_par->s_w / 2 + data->s_par->s_sc_x)))
					*TEXWIDTH / data->s_par->s_w / 256);
			if (data->s_par->tr_y > 0 && data->s_par->screen_x > 0
				&& data->s_par->screen_x < WIDTH
				&& data->s_par->tr_y
				< data->s_par->z_buff[data->s_par->screen_x])
				sprite_choice(data, i);
			data->s_par->screen_x++;
		}
	}
}

void	sprite_choice(t_vault *data, int i)
{
	double	now_time;

	now_time = get_time_in_milliseconds();
	data->s_par->screen_y = data->s_par->s_ds_y;
	if (data->s_par->s[data->s_par->s_prio[i]].texture == 1)
		draw_sprite(data, data->tex->sprite1, 0);
	else if (data->s_par->s[data->s_par->s_prio[i]].texture == 2)
		draw_sprite(data, data->tex->sprite2, 0);
	else if (data->s_par->s[data->s_par->s_prio[i]].texture == 3)
		draw_sprite(data, data->tex->pillar, 0);
	else if (data->s_par->s[data->s_par->s_prio[i]].texture == 4)
	{
		if (now_time - data->last_frame_update >= data->anim_update_interval)
		{
			data->anim_frame = (data->anim_frame + 1) % 5;
			data->last_frame_update = now_time;
		}
		data->s_par->tex_sx = fabs((int)(256 * (data->s_par->screen_x
						- (-data->s_par->s_w / 2 + data->s_par->s_sc_x)))
				*TEXWIDTH / data->s_par->s_w / 256);
		draw_sprite(data, data->tex->fire_tor, data->anim_frame);
	}
	else
		sprite_choice2(data, now_time, i);
}

void	sprite_choice2(t_vault *data, double now_time, int i)
{
	if (data->s_par->s[data->s_par->s_prio[i]].texture == 5)
		draw_sprite(data, data->tex->plants, 0);
	else if (data->s_par->s[data->s_par->s_prio[i]].texture == 6)
	{
		if (now_time - data->last_frame_update >= data->anim_update_interval)
		{
			data->anim_frame = (data->anim_frame + 1) % 5;
			data->last_frame_update = now_time;
		}
		data->s_par->tex_sx = fabs((int)(256 * (data->s_par->screen_x
						- (-data->s_par->s_w / 2 + data->s_par->s_sc_x)))
				*TEXWIDTH / data->s_par->s_w / 256);
		draw_sprite(data, data->tex->fire_arm, data->anim_frame);
	}
	else if (data->s_par->s[data->s_par->s_prio[i]].texture == 7)
		draw_sprite(data, data->tex->billard, 0);
	else if (data->s_par->s[data->s_par->s_prio[i]].texture == 8)
		draw_sprite(data, data->tex->babyfoot, 0);
	else if (data->s_par->s[data->s_par->s_prio[i]].texture == 9)
		draw_sprite(data, data->tex->lamp, 0);
	else if (data->s_par->s[data->s_par->s_prio[i]].texture == 11)
		draw_sprite(data, data->tex->table, 0);
	else
		sprite_choice3(data, now_time, i);
}

void	sprite_choice3(t_vault *data, double now_time, int i)
{
	if (data->s_par->s[data->s_par->s_prio[i]].texture == 10)
	{
		if (now_time - data->last_frame_update >= data->anim_update_interval)
		{
			data->anim_frame = (data->anim_frame + 1) % 2;
			data->last_frame_update = now_time;
		}
		data->s_par->tex_sx = fabs((int)(256 * (data->s_par->screen_x
						- (-data->s_par->s_w / 2 + data->s_par->s_sc_x)))
				*TEXWIDTH / data->s_par->s_w / 256);
		draw_sprite(data, data->tex->patrol, data->anim_frame);
	}
	else if (data->s_par->s[data->s_par->s_prio[i]].texture == 12)
	{
		if (now_time - data->last_frame_update >= data->anim_update_interval)
		{
			data->anim_frame = (data->anim_frame + 1) % 12;
			data->last_frame_update = now_time;
		}
		data->s_par->tex_sx = fabs((int)(256 * (data->s_par->screen_x
						- (-data->s_par->s_w / 2 + data->s_par->s_sc_x)))
				*TEXWIDTH / data->s_par->s_w / 256);
		draw_sprite(data, data->tex->fire, data->anim_frame);
	}
}

void	draw_sprite(t_vault *data, int **tex_buff, int frame)
{
	int			tex_y;
	int			d;
	uint32_t	color;
	uint32_t	dark_color;
	double		b_factor;

	b_factor = b_factor_sprites(data->s_par->tr_y);
	while (data->s_par->screen_y < data->s_par->s_de_y)
	{
		d = (int)((data->s_par->screen_y) * 256 - HEIGHT
				* 128 + data->s_par->s_h * 128);
		tex_y = fabs(((d * TEXHEIGHT) / data->s_par->s_h) / 256);
		color = tex_buff[tex_y][data->s_par->tex_sx + frame * 256];
		if (color != (unsigned int)0xff00ffff)
		{
			dark_color = darken_color(color, b_factor, 0);
			mlx_put_pixel(data->game->ddd, data->s_par->screen_x,
				data->s_par->screen_y, dark_color);
		}
		data->s_par->screen_y++;
	}
}
