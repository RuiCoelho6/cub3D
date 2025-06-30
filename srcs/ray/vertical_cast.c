/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_cast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:18:41 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/30 16:52:40 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	init_vertical_ray(float ray_angle, t_player *player, float *ray_x, float *ray_y)
{
	float	negative_tangent;

	negative_tangent = -tan(ray_angle);
	if (ray_angle > (PI / 2) && ray_angle < (3 * PI / 2))
	{
		*ray_y = (((int)player->pos_y >> 6) << 6) - 0.0001;
		*ray_x = (player->pos_y - *ray_y) * negative_tangent + player->pos_x;
	}
	else if (ray_angle < (PI / 2) || ray_angle > (3 * PI / 2))
	{
		*ray_y = (((int)player->pos_y >> 6) << 6) + 64;
		*ray_x = (player->pos_y - *ray_y) * negative_tangent + player->pos_x;
	}
	else
	{
		*ray_x = player->pos_x;
		*ray_y = player->pos_y;
	}
}

void	get_vertical_step(float ray_angle, float *x_offset, float *y_offset)
{
	float	negative_tangent;

	negative_tangent = -tan(ray_angle);
	if (ray_angle > (PI / 2) && ray_angle < (3 * PI / 2))
	{
		*y_offset = -64;
		*x_offset = -(*y_offset) * negative_tangent;
	}
	else if (ray_angle < (PI / 2) || ray_angle > (3 * PI / 2))
	{
		*y_offset = 64;
		*x_offset = -(*y_offset) * negative_tangent;
	}
	else
	{
		*x_offset = 0;
		*y_offset = 0;
	}
}

int check_vertical_wall(float rx, float ry, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = (int)(rx) >> 6;
	map_y = (int)(ry) >> 6;
	if (map_x >= 0 && map_x < data->map.max_x && map_y >= 0 && map_y < data->map.max_y && 
		data->map.map[map_y][map_x] == '1')
		return (1);
	return (0);
}

float	cast_vertical_ray(float ray_angle, t_player *player, t_data *data)
{
	float	ray_x;
	float	ray_y;
	float	x_offset;
	float	y_offset;
	int		depth_of_field;

	depth_of_field = 0;
	init_vertical_ray(ray_angle, player, &ray_x, &ray_y);
	get_vertical_step(ray_angle, &x_offset, &y_offset);
	if (ray_angle == 0 || ray_angle == PI)
		depth_of_field = 8;
	while (depth_of_field < 8)
	{
		if (check_vertical_wall(ray_x, ray_y, data))
			return (dist(player->pos_x, player->pos_y, ray_x, ray_y));
		ray_x += x_offset;
		ray_y += y_offset;
		depth_of_field++;
	}
	return (1000000.0f);
}
