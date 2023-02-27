/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:43:55 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/26 19:01:48 by ewurstei         ###   ########.fr       */
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
	sprite[numSprites] = {{33.5, 8.5, 10}}; //green light in front of playerstart
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

	draw_sprite(data, data->tex->tex_light, data->tex->light, sprite, i);
}

void	draw_sprite(t_vault *data, xpm_t *texture, int **tex_buff, t_sprites *sprite, int i)
{
	//loop through every vertical stripe of the sprite on screen
	int	stripe;

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
				unsigned int color;
				color = texture[sprite[data->sp_param->spriteOrder[i]].texture][TEXWIDTH * tex_y + tex_x]; //get current color from the texture
				if ((color & 0x00FFFFFF) != 0)
					tex_buff[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
				y++; //for every pixel of the current stripe
			}
		}
		stripe++;
	} 
}

//sort algorithm
//sort the sprites based on distance

int compareSprites(t_sprites *a, t_sprites *b)
{
	t_sprites *spriteA;
		spriteA = a;
	t_sprites *spriteB;
		spriteB = b;
	double diff;
	diff = spriteB.first - spriteA.first;
	if (diff > 0) {
		return 1;
	}
	if (diff < 0) {
		return -1;
	}
	return 0;
}

//function used to sort the sprites
void sortSprites(int* order, double* dist, int amount)
{
	t_sprites	sprites[amount];
	int i = 0;
	while (i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	qsort(sprites, amount, sizeof(t_sprites), compareSprites);
	i = 0;
	while (i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
		i++;
	}
}
