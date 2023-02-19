#include "../includes/cub3D.h"

void	raycaster(t_vault *data)
{
	int		distance_x;
	int		distance_y;
	double	ray_len_x;
	double	ray_len_y;
	double	deltaDistX;
	double	deltaDistY;
	double	ray_len;

	ray_len = 0;
	data->raycaster->ray_one_a = data->player->pa - degtorad(32);
//	while(data->raycaster->ray_count < 64)
//	{
		data->raycaster->next_x = data->player->ppy / 65;
		data->raycaster->next_y = data->player->ppx / 65;
		find_ray_angle(data);
		deltaDistX = sqrt(65 + (pdy_ray * pdy_ray) / (pdx_ray * pdx_ray));
		distance_x = pix_to_intersection_x(data);
		distance_y = pix_to_intersection_y(data);
		while (wall_in_next_case(data, data->raycaster->next_x, data->raycaster->next_y) == FALSE)
		{
			ray_len_x = fabs(distance_x / cos(data->raycaster->ray_one_a));
			ray_len_y = fabs(distance_y / cos(degtorad(90) - data->raycaster->ray_one_a));
			if (ray_len_x < ray_len_y)
			{
				data->raycaster->last_ray_len = ray_len;
				ray_len = ray_len_x;
				if (data->raycaster->pdx_ray < 0)
					find_next_case(data, data->player->ppx + distance_x, data->player->ppy + opp_side, 'X');
				else
					find_next_case(data, data->player->ppx + distance_x, data->player->ppy + opp_side, 'X');
				if (data->raycaster->pdx_ray < 0)
					distance_x -= 65;
				else
					distance_x += 65;
			}
			else
			{
				data->raycaster->last_ray_len = ray_len;
				ray_len = ray_len_y;
				if (data->raycaster->pdy_ray < 0)
					find_next_case(data, data->player->ppx + opp_side, data->player->ppy + distance_y, 'Y');
				else
					find_next_case(data, data->player->ppx + opp_side, data->player->ppy + distance_y, 'Y');
				if (data->raycaster->pdy_ray < 0)
					distance_y -= 65;
				else
					distance_y += 65;
			}
		}
		draw_ray(data, ray_len);
//		data->raycaster->ray_one_a = data->raycaster->ray_one_a + degtorad(1);
//		data->raycaster->ray_count++;
//	}
	data->raycaster->ray_count = 0;
}