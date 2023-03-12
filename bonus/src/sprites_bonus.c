/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:43:55 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/11 23:09:00 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

//SPRITE CASTING
	//sort sprites from far to close

void	load_sprites(t_vault *data)
{
	data->sp_param->sprite[0].sprite_x = 34.5;
	data->sp_param->sprite[0].sprite_y = 8.5;
	data->sp_param->sprite[0].texture = 1;
	
	data->sp_param->sprite[1].sprite_x = 35.5;
	data->sp_param->sprite[1].sprite_y = 8.5;
	data->sp_param->sprite[1].texture = 2;
}

void	sprite_casting(t_vault *data)
{
	int	i;

	i = 0;
	sprite_ordering(data);
	data->sp_param->invDet = 1.0 / (data->raycaster->plane_x
			* data->raycaster->pdy_ray - data->raycaster->pdx_ray
				* data->raycaster->plane_y);
	while (i < numSprites)
	{
		sprite_computing(data, data->sp_param->sprite[i].texture, i);
		i++;
	}
}

void	sprite_ordering(t_vault *data)
{
	int	i;

	i = 0;

	while (i < numSprites)
	{
		data->sp_param->spriteOrder[i] = i;
		data->sp_param->spriteDistance[i]
			= ((data->plr->col - data->sp_param->sprite[i].sprite_x)
				* (data->plr->col - data->sp_param->sprite[i].sprite_x)
				+ (data->plr->row - data->sp_param->sprite[i].sprite_y) 
				* (data->plr->row - data->sp_param->sprite[i].sprite_y)); //sqrt not taken, unneeded
		i++;
	}
	sort_sprites(data);
}

void	sprite_computing(t_vault *data, int sprite_num, int i)
{
	data->sp_param->sprite_y = data->sp_param->sprite[data->sp_param->spriteOrder[numSprites - 1 - i]].sprite_x - data->plr->row;
	data->sp_param->sprite_x = data->sp_param->sprite[data->sp_param->spriteOrder[numSprites - 1 - i]].sprite_y - data->plr->col;

	data->sp_param->transformX = data->sp_param->invDet * (data->raycaster->pdy_ray * data->sp_param->sprite_x - data->raycaster->pdx_ray * data->sp_param->sprite_y);
	data->sp_param->transformY = data->sp_param->invDet * (-data->raycaster->plane_y * data->sp_param->sprite_x + data->raycaster->plane_x * data->sp_param->sprite_y); //this is actually the depth inside the screen, that what Z is in 3D

	data->sp_param->spriteScreenX = ((WIDTH / 2) * (1 + data->sp_param->transformX / data->sp_param->transformY));

	data->sp_param->spriteHeight = fabs((HEIGHT / data->sp_param->transformY)); //using 'transformY' instead of the real distance prevents fisheye

	data->sp_param->drawStartY = -data->sp_param->spriteHeight / 2 + HEIGHT / 2;
	if (data->sp_param->drawStartY < 0)
		data->sp_param->drawStartY = 0;

	data->sp_param->drawEndY = data->sp_param->spriteHeight / 2 + HEIGHT / 2;
	if (data->sp_param->drawEndY >= HEIGHT)
		data->sp_param->drawEndY = HEIGHT - 1;

	data->sp_param->spriteWidth = data->sp_param->spriteHeight;

	data->sp_param->drawStartX = -data->sp_param->spriteWidth / 2 + data->sp_param->spriteScreenX;
	if(data->sp_param->drawStartX < 0)
		data->sp_param->drawStartX = 0;

	data->sp_param->drawEndX = data->sp_param->spriteWidth / 2 + data->sp_param->spriteScreenX;
	if(data->sp_param->drawEndX >= WIDTH)
		data->sp_param->drawEndX = WIDTH - 1;
	if (sprite_num == 1)
		draw_sprite(data, data->tex->sprite1);
	else if (sprite_num == 2)
		draw_sprite(data, data->tex->sprite2);
}

void	draw_sprite(t_vault *data, int **tex_buff)
{
	int	screen_x;

	screen_x = data->sp_param->drawStartX;
	while (screen_x < data->sp_param->drawEndX)
	{
		int tex_x;
		tex_x = (256 * (screen_x - (-data->sp_param->spriteWidth / 2 + data->sp_param->spriteScreenX)) * TEXWIDTH / data->sp_param->spriteWidth) / 256;
		if (data->sp_param->transformY > 0 && screen_x > 0 && screen_x < WIDTH && data->sp_param->transformY < data->sp_param->ZBuffer[screen_x])
		{
			int	screen_y;
			screen_y = data->sp_param->drawStartY;
			while (screen_y < data->sp_param->drawEndY)
			{
				int d;
				d = (screen_y) * 256 - HEIGHT * 128 + data->sp_param->spriteHeight * 128; //256 and 128 factors to avoid floats
				int tex_y;
				tex_y = ((d * TEXHEIGHT) / data->sp_param->spriteHeight) / 256;
				if (tex_buff[tex_y][tex_x] != (int)0xff00ffff)
					mlx_put_pixel(data->game->ddd, screen_x, screen_y, tex_buff[tex_y][tex_x]);
				screen_y++; //for every pixel of the current stripe
			}
		}
		screen_x++;
	}
}

void	sort_sprites(t_vault *data)
{
	int	i;
	int	j;
	int	sprite_i;
	int	sprite_j;
	double dist_i;
	double dist_j;

	i = 0;
	while (i < numSprites - 1)
	{
		j = i + 1;
		while (j < numSprites)
		{
			sprite_i = data->sp_param->spriteOrder[i];
			sprite_j = data->sp_param->spriteOrder[j];
			dist_i = data->sp_param->spriteDistance[sprite_i];
			dist_j = data->sp_param->spriteDistance[sprite_j];
			if (dist_i < dist_j)
			{
				data->sp_param->spriteOrder[i] = sprite_j;
				data->sp_param->spriteOrder[j] = sprite_i;
			}
			j++;
		}
		i++;
	}
}
