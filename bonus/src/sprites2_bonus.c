/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:38:33 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/08 21:42:28 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	init_sprites(t_sprites *sprite)
{
    sprite[0] = (t_sprites){33.5, 8.5, 1};
}

void	sort_sprites(t_vault *data)
{
    int i;
    int j;
    int sprite_i;
    int sprite_j;
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
            dist_i = ((data->plr->row - data->sprites[sprite_i].sprite_x) * (data->plr->row - data->sprites[sprite_i].sprite_x) + (data->plr->col - data->sprites[sprite_i].sprite_y) * (data->plr->col - data->sprites[sprite_i].sprite_y));
            dist_j = ((data->plr->row - data->sprites[sprite_j].sprite_x) * (data->plr->row - data->sprites[sprite_j].sprite_x) + (data->plr->col - data->sprites[sprite_j].sprite_y) * (data->plr->col - data->sprites[sprite_j].sprite_y));
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

void calculate_sprite(t_vault *data, t_sprites *sprite, int i)
{
    data->sp_param->spriteY = sprite[data->sp_param->spriteOrder[i]].sprite_x - data->plr->row;
    data->sp_param->spriteX = sprite[data->sp_param->spriteOrder[i]].sprite_y - data->plr->col;

    double invDet;

    invDet = 1.0 / (data->raycaster->plane_x * data->raycaster->pdy_ray - data->raycaster->pdx_ray * data->raycaster->plane_y); //required for correct matrix multiplication

    data->sp_param->transformX = invDet * (data->raycaster->pdy_ray * data->sp_param->spriteX - data->raycaster->pdx_ray * data->sp_param->spriteY);
    data->sp_param->transformY = invDet * (-data->raycaster->plane_y * data->sp_param->spriteX + data->raycaster->plane_x * data->sp_param->spriteY); //this is actually the depth inside the screen, that what Z is in 3D

    data->sp_param->spriteScreenX = (int)((WIDTH / 2) * (1 + data->sp_param->transformX / data->sp_param->transformY));

    data->sp_param->spriteHeight = abs((int)(HEIGHT / data->sp_param->transformY)); //using 'transformY' instead of the real distance prevents fisheye

    data->sp_param->drawStartY = -data->sp_param->spriteHeight / 2 + HEIGHT / 2;
    if (data->sp_param->drawStartY < 0)
        data->sp_param->drawStartY = 0;

    data->sp_param->drawEndY = data->sp_param->spriteHeight / 2 + HEIGHT / 2;
    if (data->sp_param->drawEndY >= HEIGHT)
        data->sp_param->drawEndY = HEIGHT - 1;

    data->sp_param->spriteWidth = abs((int)(data->sp_param->spriteHeight / data->sp_param->transformY));

    data->sp_param->drawStartX = -data->sp_param->spriteWidth / 2 + data->sp_param->spriteScreenX;
    if (data->sp_param->drawStartX < 0)
        data->sp_param->drawStartX = 0;

    data->sp_param->drawEndX = data->sp_param->spriteWidth / 2 + data->sp_param->spriteScreenX;
    if (data->sp_param->drawEndX >= WIDTH)
        data->sp_param->drawEndX = WIDTH - 1;
}

void	draw_sprite(t_vault *data, xpm_t *texture, int **tex_buff)
{
	int	screen_x;
	(void) texture;

	screen_x = data->sp_param->drawStartX;
	while (screen_x < data->sp_param->drawEndX)
	{
		int tex_x;
		tex_x = (int)(256 * (screen_x - (-data->sp_param->spriteWidth / 2 + data->sp_param->spriteScreenX)) * TEXWIDTH / data->sp_param->spriteWidth) / 256;
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
				mlx_put_pixel(data->game->ddd, screen_x, screen_y, tex_buff[tex_y][tex_x]);
				screen_y++; //for every pixel of the current stripe
			}
		}
		screen_x++;
	}
}