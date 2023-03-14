/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:43:55 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/14 00:13:39 by ewurstei         ###   ########.fr       */
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
	int	tex_x;

	i = -1;
	sprite_ordering(data);
	while (++i < NUMSPRITES)
	{
		sprite_computing(data, i);
		data->s_par->screen_x = data->s_par->s_ds_x;
		while (data->s_par->screen_x < data->s_par->s_de_x)
		{
			tex_x = (int)(256 * (data->s_par->screen_x
						- (-data->s_par->s_w / 2 + data->s_par->s_sc_x))
					* TEXWIDTH / data->s_par->s_w) / 256;
			if (data->s_par->tr_y > 0 && data->s_par->screen_x > 0
				&& data->s_par->screen_x < WIDTH
				&& data->s_par->tr_y
				< data->s_par->z_buff[data->s_par->screen_x])
				sprite_choice(data, tex_x, i);
			data->s_par->screen_x++;
		}
	}
}

void	sprite_choice(t_vault *data, int tex_x, int i)
{
	data->s_par->screen_y = data->s_par->s_ds_y;
	if (data->s_par->s[data->s_par->s_prio[i]].texture == 1)
		draw_sprite(data, tex_x, data->tex->sprite1);
	else if (data->s_par->s[data->s_par->s_prio[i]].texture == 2)
		draw_sprite(data, tex_x, data->tex->sprite2);
	else if (data->s_par->s[data->s_par->s_prio[i]].texture == 3)
		draw_sprite(data, tex_x, data->tex->pillar);
	else if (data->s_par->s[data->s_par->s_prio[i]].texture == 4)
		draw_sprite_loop(data, tex_x, data->tex->fire_tor);
}

void	sprite_computing(t_vault *data, int i)
{
	data->s_par->s_diff_col
		= data->s_par->s[data->s_par->s_prio[i]].s_row - (data->plr->row);
	data->s_par->s_diff_row
		= data->s_par->s[data->s_par->s_prio[i]].s_col - (data->plr->col);
	data->s_par->inv_det = 1.0 / (data->raycaster->plane_x * data->plr->pdy
			- data->plr->pdx * data->raycaster->plane_y);
	data->s_par->tr_x
		= data->s_par->inv_det * (data->plr->pdy * data->s_par->s_diff_row
			- data->plr->pdx * data->s_par->s_diff_col);
	data->s_par->tr_y
		= data->s_par->inv_det * (-data->raycaster->plane_y
			* data->s_par->s_diff_row + data->raycaster->plane_x
			* data->s_par->s_diff_col);
	data->s_par->s_sc_x = (int)((WIDTH / 2)
			* (1 + data->s_par->tr_x / data->s_par->tr_y));
	sprite_computing2(data);
}

void	sprite_computing2(t_vault *data)
{
	data->s_par->s_h = abs((int)(HEIGHT / data->s_par->tr_y));
	data->s_par->s_ds_y = -data->s_par->s_h / 2 + HEIGHT / 2;
	if (data->s_par->s_ds_y < 0)
		data->s_par->s_ds_y = 0;
	data->s_par->s_de_y = data->s_par->s_h / 2 + HEIGHT / 2;
	if (data->s_par->s_de_y >= HEIGHT)
		data->s_par->s_de_y = HEIGHT - 1;
	data->s_par->s_w = abs((int)(HEIGHT / data->s_par->tr_y));
	data->s_par->s_ds_x = -data->s_par->s_w / 2 + data->s_par->s_sc_x;
	if (data->s_par->s_ds_x < 0)
		data->s_par->s_ds_x = 0;
	data->s_par->s_de_x = data->s_par->s_w / 2 + data->s_par->s_sc_x;
	if (data->s_par->s_de_x >= WIDTH)
		data->s_par->s_de_x = WIDTH - 1;
}

void	draw_sprite(t_vault *data, int tex_x, int **tex_buff)
{
	int	tex_y;
	int	d;

	while (data->s_par->screen_y < data->s_par->s_de_y)
	{
		d = (int)((data->s_par->screen_y) * 256 - HEIGHT
				* 128 + data->s_par->s_h * 128);
		tex_y = ((d * TEXHEIGHT) / data->s_par->s_h) / 256;
		if (tex_buff[tex_y][tex_x] != (int)0xff00ffff)
			mlx_put_pixel(data->game->ddd, data->s_par->screen_x,
				data->s_par->screen_y, tex_buff[tex_y][tex_x]);
		data->s_par->screen_y++;
	}
}

void	draw_sprite_loop(t_vault *data, int tex_x, int **tex_buff)
{
	int	tex_y;
	int	d;
	int	loop;
	int	max;

	loop = 0;
	max = 0;
	while (loop < 5 && max < 100)
	{
		printf("loop #%d\n", loop);
		while (data->s_par->screen_y < data->s_par->s_de_y)
		{
			printf("coucou\n");
			d = (int)((data->s_par->screen_y) * 256 - HEIGHT
					* 128 + data->s_par->s_h * 128);
			tex_y = ((d * TEXHEIGHT) / data->s_par->s_h) / 256;
			if (tex_buff[tex_y][tex_x] != (int)0xff00ffff)
				mlx_put_pixel(data->game->ddd, data->s_par->screen_x,
					data->s_par->screen_y, tex_buff[tex_y + loop * 256][tex_x]);
			data->s_par->screen_y++;
		}
		loop++;
		if (loop == 5)
			loop = 0;
		max++;
	}
}
