/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:43:55 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/13 10:53:46 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

//SPRITE CASTING
	//sort sprites from far to close

void	load_sprites(t_vault *data)
{
	data->sp_param->sprite[0].sprite_row = 33.5;
	data->sp_param->sprite[0].sprite_col = 7.5;
	data->sp_param->sprite[0].texture = 1;

	data->sp_param->sprite[1].sprite_row = 33.5;
	data->sp_param->sprite[1].sprite_col = 8.5;
	data->sp_param->sprite[1].texture = 2;
}

void	sprite_casting(t_vault *data)
{
	int	i;
	int	screen_x;
	int	screen_y;
	int tex_x;

	i = 0;
	sprite_ordering(data);
	while (i < numSprites)
	{
		sprite_computing(data, i);
		screen_x = data->sp_param->drawStartX;
		while (screen_x < data->sp_param->drawEndX)
		{
			tex_x = (int)(256 * (screen_x - (-data->sp_param->spriteWidth / 2 + data->sp_param->spriteScreenX)) * TEXWIDTH / data->sp_param->spriteWidth) / 256;
			if (data->sp_param->transformY > 0 && screen_x > 0 && screen_x < WIDTH && data->sp_param->transformY < data->sp_param->ZBuffer[screen_x])
			{
				screen_y = data->sp_param->drawStartY;
				if (data->sp_param->sprite[data->sp_param->spriteOrder[i]].texture == 1)
					draw_sprite(data, screen_y, tex_x, screen_x, data->tex->sprite1);
				else if (data->sp_param->sprite[data->sp_param->spriteOrder[i]].texture == 2)
					draw_sprite(data, screen_y, tex_x, screen_x, data->tex->sprite2);
			}
			screen_x++;
		}
		i++;
	}
}

void	sprite_ordering(t_vault *data)
{
	int	i;

	i = 0;
	printf("------- NEW CALCULATION -------\n");
	while (i < numSprites)
	{
		data->sp_param->spriteOrder[i] = i;
		data->sp_param->spriteDistance[i]
			= ((data->plr->row - data->sp_param->sprite[i].sprite_row)
				* (data->plr->row - data->sp_param->sprite[i].sprite_row)
				+ (data->plr->col - data->sp_param->sprite[i].sprite_col) 
				* (data->plr->col - data->sp_param->sprite[i].sprite_col));
		printf("s #%d, dist : %f, id_tex : %d\n", i, data->sp_param->spriteDistance[i], data->sp_param->sprite[i].texture);
		i++;
	}
	sort_sprites(data);
}

void	sprite_computing(t_vault *data, int i)
{
	printf("--------- NEW SPRITE ---------\n");
	printf("row : %f\n", data->sp_param->sprite[data->sp_param->spriteOrder[i]].sprite_row);
	printf("col : %f\n", data->sp_param->sprite[data->sp_param->spriteOrder[i]].sprite_col);
	data->sp_param->s_diff_row = data->sp_param->sprite[data->sp_param->spriteOrder[i]].sprite_row - (data->plr->row);
	data->sp_param->s_diff_col = data->sp_param->sprite[data->sp_param->spriteOrder[i]].sprite_col - (data->plr->col);

	printf("p_row : %f\n", data->plr->row);
	printf("p_col : %f\n", data->plr->col);

	printf("s_diff_row: %f\n", data->sp_param->s_diff_row);
	printf("s_diff_col: %f\n", data->sp_param->s_diff_col);
	data->sp_param->invDet = 1.0 / (data->raycaster->plane_x * data->raycaster->pdy_ray - data->raycaster->pdx_ray * data->raycaster->plane_y);

	data->sp_param->transformY = data->sp_param->invDet * (data->raycaster->pdy_ray * data->sp_param->s_diff_row - data->raycaster->pdx_ray * data->sp_param->s_diff_col);
	data->sp_param->transformX = data->sp_param->invDet * (-data->raycaster->plane_y * data->sp_param->s_diff_row + data->raycaster->plane_x * data->sp_param->s_diff_col); //this is actually the depth inside the screen, that what Z is in 3D

	data->sp_param->spriteScreenX = (int)((WIDTH / 2) * (1 - data->sp_param->transformX / data->sp_param->transformY));
	printf("screen_x: %f\n", data->sp_param->spriteScreenX);

	data->sp_param->spriteHeight = abs((int)(HEIGHT / data->sp_param->transformY)); //using 'transformY' instead of the real distance prevents fisheye

	data->sp_param->drawStartY = -data->sp_param->spriteHeight / 2 + HEIGHT / 2;
	if (data->sp_param->drawStartY < 0)
		data->sp_param->drawStartY = 0;
	printf("start_y: %f\n", data->sp_param->spriteScreenX);

	data->sp_param->drawEndY = data->sp_param->spriteHeight / 2 + HEIGHT / 2;
	if (data->sp_param->drawEndY >= HEIGHT)
		data->sp_param->drawEndY = HEIGHT - 1;

	data->sp_param->spriteWidth = abs((int)(HEIGHT / data->sp_param->transformY));

	data->sp_param->drawStartX = -data->sp_param->spriteWidth / 2 + data->sp_param->spriteScreenX;
	if(data->sp_param->drawStartX < 0)
		data->sp_param->drawStartX = 0;
	printf("start_x: %f\n", data->sp_param->spriteScreenX);

	data->sp_param->drawEndX = data->sp_param->spriteWidth / 2 + data->sp_param->spriteScreenX;
	if(data->sp_param->drawEndX >= WIDTH)
		data->sp_param->drawEndX = WIDTH - 1;
}

void	draw_sprite(t_vault *data, int screen_y, int tex_x, int screen_x, int **tex_buff)
{
	int	tex_y;
	int	d;

	while (screen_y < data->sp_param->drawEndY)
	{
		d = (int)(screen_y) * 256 - HEIGHT * 128 + data->sp_param->spriteHeight * 128; //256 and 128 factors to avoid floats
		tex_y = ((d * TEXHEIGHT) / data->sp_param->spriteHeight) / 256;
		if (tex_buff[tex_y][tex_x] != (int)0xff00ffff)
			mlx_put_pixel(data->game->ddd, screen_x, screen_y, tex_buff[tex_y][tex_x]);
		screen_y++;
	}
}

void	sort_sprites(t_vault *data)
{
	int		i;
	int		j;
	double	tmp;

	i = 0;
	printf("s #%d, ordre : %d, id_tex : %d\n", i, data->sp_param->spriteOrder[i], data->sp_param->sprite[i].texture);
	printf("s #%d, ordre : %d, id_tex : %d\n", 1, data->sp_param->spriteOrder[1], data->sp_param->sprite[1].texture);
	printf("nouvel ordre\n");
	while (i < numSprites)
	{
		j = 0;
		while (j < numSprites - 1)
		{
			if (data->sp_param->spriteDistance[j] < data->sp_param->spriteDistance[j + 1] && (data->sp_param->spriteOrder[j] < data->sp_param->spriteOrder[j + 1]))
			{
				// tmp = data->sp_param->spriteDistance[j];
				// data->sp_param->spriteDistance[j] = data->sp_param->spriteDistance[j + 1];
				// data->sp_param->spriteDistance[j + 1] = tmp;
				tmp = data->sp_param->spriteOrder[j];
				data->sp_param->spriteOrder[j] = data->sp_param->spriteOrder[j + 1];
				data->sp_param->spriteOrder[j + 1] = (int)tmp;
				printf("coucou\n");
			}
			j++;
		}
		i++;
	}
	printf("s #%d, ordre : %d, id_tex : %d\n", 0, data->sp_param->spriteOrder[0], data->sp_param->sprite[0].texture);
	printf("s #%d, ordre : %d, id_tex : %d\n", 1, data->sp_param->spriteOrder[1], data->sp_param->sprite[1].texture);
}
