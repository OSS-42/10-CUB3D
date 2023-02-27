/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:43:55 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/27 15:31:21 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

//SPRITE CASTING
	//sort sprites from far to close
void	sprite_casting(t_vault *data, int pixels_2d)
{
	int	i;
	t_sprites	sprite[numSprites];
	
	// sprite[numSprites] = ft_calloc(1, sizeof(t_sprites));
	sprite[0] = (t_sprites){33.5, 8.5, 10}; //green light in front of playerstart
	i = 0;
	while (i < numSprites)
	{
		data->sp_param->spriteOrder[i] = i;
		data->sp_param->spriteDistance[i] = ((data->player->row - sprite[i].sprite_x) * (data->player->row - sprite[i].sprite_x) + (data->player->col - sprite[i].sprite_y) * (data->player->col - sprite[i].sprite_y)); //sqrt not taken, unneeded
		i++;
	}
	sortSprites(data->sp_param->spriteOrder, data->sp_param->spriteDistance, numSprites);

	//after sorting the sprites, do the projection and draw them
	i = 0;
	while (i < numSprites)
	{
		//translate sprite position to relative to camera
		data->sp_param->spriteX = sprite[data->sp_param->spriteOrder[i]].sprite_x - data->player->row;
		data->sp_param->spriteY = sprite[data->sp_param->spriteOrder[i]].sprite_y - data->player->col;
		i++;
	}

	//transform sprite with the inverse camera matrix
	// [ planeX   dirX ] -1                                       [ dirY      -dirX ]
	// [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
	// [ planeY   dirY ]                                          [ -planeY  planeX ]

	double invDet;
	
	invDet = 1.0 / (data->raycaster->plane_x * data->raycaster->pdy_ray - data->raycaster->pdx_ray * data->raycaster->plane_y); //required for correct matrix multiplication

	data->sp_param->transformX = invDet * (data->raycaster->pdy_ray * data->sp_param->spriteX - data->raycaster->pdx_ray * data->sp_param->spriteY);
	data->sp_param->transformY = invDet * (-data->raycaster->plane_y * data->sp_param->spriteX + data->raycaster->plane_x * data->sp_param->spriteY); //this is actually the depth inside the screen, that what Z is in 3D

	data->sp_param->spriteScreenX = (int)((WIDTH / 2) * (1 + data->sp_param->transformX / data->sp_param->transformY));

	//calculate height of the sprite on screen
	
	data->sp_param->spriteHeight = abs((int)(HEIGHT / (data->sp_param->transformY))); //using 'transformY' instead of the real distance prevents fisheye
	//calculate lowest and highest pixel to fill in current stripe
	
	data->sp_param->drawStartY = -data->sp_param->spriteHeight / 2 + WIDTH / 2;
	if (data->sp_param->drawStartY < 0)
		data->sp_param->drawStartY = 0;
	
	data->sp_param->drawEndY = data->sp_param->spriteHeight / 2 + HEIGHT / 2;
	if (data->sp_param->drawEndY >= HEIGHT)
		data->sp_param->drawEndY = HEIGHT - 1;

	//calculate width of the sprite
	
	data->sp_param->spriteWidth = fabs((int)HEIGHT / (data->sp_param->transformY));
	
	data->sp_param->drawStartX = -data->sp_param->spriteWidth / 2 + data->sp_param->spriteScreenX;
	if(data->sp_param->drawStartX < 0)
		data->sp_param->drawStartX = 0;
	
	data->sp_param->drawEndX = data->sp_param->spriteWidth / 2 + data->sp_param->spriteScreenX;
	if(data->sp_param->drawEndX >= WIDTH)
		data->sp_param->drawEndX = WIDTH - 1;

	draw_sprite(data, data->tex->tex_light, data->tex->light, sprite, pixels_2d);
}

void	draw_sprite(t_vault *data, xpm_t *texture, int **tex_buff, t_sprites *sprite, int i)
{
	//loop through every vertical stripe of the sprite on screen
	int	stripe;
	(void) texture;
	(void) sprite;
	(void) i;
	
	stripe = data->sp_param->drawStartX;
	while (stripe < data->sp_param->drawEndX)
	{
		int tex_x;
		tex_x = (int)(256 * (stripe - (-data->sp_param->spriteWidth / 2 + data->sp_param->spriteScreenX)) * TEXWIDTH / data->sp_param->spriteWidth) / 256;
		//the conditions in the if are:
		//1) it's in front of camera plane so you don't see things behind you
		//2) it's on the screen (left)
		//3) it's on the screen (right)
		//4) ZBuffer, with perpendicular distance
		if (data->sp_param->transformY > 0 && stripe > 0 && stripe < WIDTH && data->sp_param->transformY < data->sp_param->ZBuffer[stripe])
		{
			int	y;
			y = data->sp_param->drawStartY;
			while (y < data->sp_param->drawEndY)
			{
				int d;
				d = (y) * 256 - HEIGHT * 128 + data->sp_param->spriteHeight * 128; //256 and 128 factors to avoid floats
				int tex_y;
				tex_y = ((d * TEXHEIGHT) / data->sp_param->spriteHeight) / 256;
				mlx_put_pixel(data->game->ddd, stripe, tex_y, tex_buff[tex_y][tex_x]);
				y++; //for every pixel of the current stripe
			}
		}
		stripe++;
	} 
}

void sortSprites(int* order, double* dist, int amount)
{
	// Create temporary arrays to store the distance and order values
	double tempDist[amount];
	int tempOrder[amount];
	for (int i = 0; i < amount; i++) {
		tempDist[i] = dist[i];
		tempOrder[i] = order[i];
	}

	// Sort the arrays using a simple bubble sort algorithm
	for (int i = 0; i < amount - 1; i++) {
		for (int j = 0; j < amount - i - 1; j++) {
			if (tempDist[j] < tempDist[j + 1]) {
				// Swap the j-th and (j+1)-th elements of the arrays
				double tempDistVal = tempDist[j];
				tempDist[j] = tempDist[j + 1];
				tempDist[j + 1] = tempDistVal;

				int tempOrderVal = tempOrder[j];
				tempOrder[j] = tempOrder[j + 1];
				tempOrder[j + 1] = tempOrderVal;
			}
		}
	}

	// Copy the sorted values back to the original arrays
	for (int i = 0; i < amount; i++) {
		dist[i] = tempDist[i];
		order[i] = tempOrder[i];
	}
}