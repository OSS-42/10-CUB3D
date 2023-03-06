/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:38:33 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/06 11:26:28 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

// Determine the position of the camera: This step involves calculating the 
// position and direction of the camera in the 3D world. This information is 
// necessary to determine which sprites should be rendered on the screen.

// Determine the position and orientation of the sprites: This step involves 
// calculating the position and orientation of each sprite in the 3D world. 
// This information is necessary to determine which sprites are visible from the 
// camera's point of view.

// Sort the sprites by distance: This step involves sorting the sprites based on 
// their distance from the camera. This information is necessary to determine the 
// correct order in which to render the sprites, which is important for achieving 
// correct occlusion and transparency effects.

// Calculate the projection of the sprites onto the screen: This step involves 
// projecting the 3D positions of the sprites onto the 2D screen using a 
// perspective projection matrix. This information is necessary to determine the 
// correct position and size of each sprite on the screen.

// Render the sprites: This step involves rendering each sprite onto the screen in
//  the correct order, taking into account any transparency or occlusion effects.

// Repeat for each frame: This process is typically repeated for each frame of 
// the animation or game, as the position of the camera and the sprites may change
//  over time.

// void	distance_to_camera(t_vault *data, t_sprites *sprite)
// {
// 	int	i;

// 	i = 0;
// 	while (i < numSprites)
// 	{
// 		data->sp_param->spriteX
// 			= sprite[data->sp_param->spriteOrder[i]].sprite_x - data->plr->row;
// 		data->sp_param->spriteY
// 			= sprite[data->sp_param->spriteOrder[i]].sprite_y - data->plr->col;
// 		i++;
// 	}
// }

void distance_to_camera(t_vault *data, t_sprites *sprite)
{
	int i;

	i = 0;
	while (i < numSprites)
	{
		data->sp_param->spriteX = sprite[i].sprite_x - data->plr->row;
		data->sp_param->spriteY = sprite[i].sprite_y - data->plr->col;
		data->sp_param->spriteOrder[i] = i;
		data->sp_param->spriteDistance[i] =
			((data->plr->row - sprite[i].sprite_x) *
			 (data->plr->row - sprite[i].sprite_x) +
			 (data->plr->col - sprite[i].sprite_y) *
			 (data->plr->col - sprite[i].sprite_y));
		i++;
	}
}

void	transform_inverse_matrix(t_vault *data)
{
	double	inv_det;

	inv_det
		= 1.0 / (data->raycaster->plane_x * data->raycaster->pdy_ray
			- data->raycaster->pdx_ray * data->raycaster->plane_y);

	data->sp_param->transformX
		= inv_det * (data->raycaster->pdy_ray * data->sp_param->spriteX
			- data->raycaster->pdx_ray * data->sp_param->spriteX);
	data->sp_param->transformY
		= inv_det * (-data->raycaster->plane_y * data->sp_param->spriteY
			+ data->raycaster->plane_x * data->sp_param->spriteY);

	data->sp_param->spriteScreenX
		= (int)((WIDTH / 2)
			* (1 + data->sp_param->transformX / data->sp_param->transformY));
}

void	calculate_sprite_height(t_vault *data)
{
	data->sp_param->spriteHeight
		= abs((int)(HEIGHT / data->sp_param->transformY));
	if (data->sp_param->spriteHeight >= HEIGHT)
		data->sp_param->spriteHeight = HEIGHT - 1;
	if (data->sp_param->spriteHeight < 0)
		data->sp_param->spriteHeight = 0;

	data->sp_param->drawStartY
		= -data->sp_param->spriteHeight / 2 + HEIGHT / 2;
	if (data->sp_param->drawStartY < 0)
		data->sp_param->drawStartY = 0;

	data->sp_param->drawEndY
		= data->sp_param->spriteHeight / 2 + HEIGHT / 2;
	if (data->sp_param->drawEndY >= HEIGHT)
		data->sp_param->drawEndY = HEIGHT - 1;
}

void	calculate_sprite_width(t_vault *data)
{
	data->sp_param->spriteWidth
		= fabs((int)HEIGHT / (data->sp_param->transformY));
	if (data->sp_param->spriteWidth >= HEIGHT)
		data->sp_param->spriteWidth = HEIGHT - 1;
	if (data->sp_param->spriteWidth < 0)
		data->sp_param->spriteWidth = 0;

	data->sp_param->drawStartX
		= -data->sp_param->spriteWidth / 2 + data->sp_param->spriteScreenX;
	if (data->sp_param->drawStartX < 0)
		data->sp_param->drawStartX = 0;

	data->sp_param->drawEndX
		= data->sp_param->spriteWidth / 2 + data->sp_param->spriteScreenX;
	if (data->sp_param->drawEndX >= WIDTH)
		data->sp_param->drawEndX = WIDTH - 1;
}

// void	sprite_casting(t_vault *data)
// {
// 	t_sprites	*sprite;
// 	int i;

// 	i = 0;
// 	sprite = ft_calloc(numSprites, sizeof(t_sprites));
// 	sprite[0] = (t_sprites){33.5, 8.5, 10};
// 	while (i < numSprites)
// 	{
// 		data->sp_param->spriteX = sprite[data->sp_param->spriteOrder[i]].sprite_x - data->plr->row;
// 		data->sp_param->spriteY = sprite[data->sp_param->spriteOrder[i]].sprite_y - data->plr->col;
// 		transform_inverse_matrix(data);
// 		calculate_sprite_height(data);
// 		calculate_sprite_width(data);
// 		draw_sprite(data, sprite, data->sp_param->spriteOrder[i]);
// 		i++;
// 	}
// 	free (sprite);
// }

void	sprite_casting(t_vault *data)
{
	t_sprites	*sprite;
	int i;

	i = 0;
	sprite = ft_calloc(numSprites, sizeof(t_sprites));
	sprite[0] = (t_sprites){33.5, 8.5, 10};
	while (i < numSprites)
	{
		data->sp_param->spriteX = sprite[data->sp_param->spriteOrder[i]].sprite_x - data->plr->row;
		data->sp_param->spriteY = sprite[data->sp_param->spriteOrder[i]].sprite_y - data->plr->col;
		transform_inverse_matrix(data);
		calculate_sprite_height(data);
		calculate_sprite_width(data);
		draw_sprite(data, sprite, data->sp_param->spriteOrder[i]);
		i++;
	}
	free(sprite);
}

void draw_sprite(t_vault *data, int **tex_buff, int sprite_order, int sprite_screen_x)
{
    int screen_x = data->sp_param->drawStartX;
    int sprite_width = data->sp_param->spriteWidth;
    int sprite_height = data->sp_param->spriteHeight;
    double inv_det = 1.0 / (data->raycaster->plane_x * data->raycaster->pdy_ray - data->raycaster->pdx_ray * data->raycaster->plane_y);
    double transform_y = data->sp_param->transformY;

    double *tex_coords = calloc((sprite_width + 501), sizeof(double));
    int *screen_x_diff = calloc((sprite_width + 501), sizeof(int));

    int i = 0;
    while (i < sprite_width)
    {
        screen_x_diff[i] = (double)(256 * (i - (sprite_width / 2 + sprite_screen_x)) * TEXWIDTH / sprite_width) / 256;
        tex_coords[i] = inv_det * (screen_x_diff[i] * data->raycaster->pdy_ray - transform_y * data->raycaster->pdx_ray);
        i++;
    }

    while (screen_x < data->sp_param->drawEndX)
    {
        if (transform_y > 0 && screen_x > 0 && screen_x < WIDTH && transform_y < data->sp_param->ZBuffer[screen_x])
        {
            int screen_y = data->sp_param->drawStartY;
            while (screen_y < data->sp_param->drawEndY)
            {
                int d = (screen_y) * 256 - HEIGHT * 128 + sprite_height * 128;
                int tex_y = ((d * TEXHEIGHT) / sprite_height) / 256;
                int color = tex_buff[tex_y][(int)tex_coords[(int)(screen_x - data->sp_param->drawStartX + (sprite_width / 2))]];

                if ((color & 0x00FFFFFF) != 0)
                {
                    mlx_put_pixel(data->game->ddd, screen_x, screen_y, color);
                }
                screen_y++;
            }
        }
        screen_x++;
    }

    free(tex_coords);
    tex_coords = NULL;
    free(screen_x_diff);
    screen_x_diff = NULL;
}


void sort_sprites(t_vault *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < numSprites - 1)
	{
		j = i + 1;
		while (j < numSprites)
		{
			if (data->sp_param->spriteDistance[data->sp_param->spriteOrder[i]] <
				data->sp_param->spriteDistance[data->sp_param->spriteOrder[j]])
			{
				ft_swap_int(&data->sp_param->spriteOrder[i],
					&data->sp_param->spriteOrder[j]);
			}
			j++;
		}
		i++;
	}
}
