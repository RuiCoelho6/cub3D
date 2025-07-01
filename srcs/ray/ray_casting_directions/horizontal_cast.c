/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_cast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:20:54 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/01 16:57:40 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	init_horizontal_ray(float ray_angle, t_player *player, float *ray_x, float *ray_y)
{
	float	inverse_tan;

	inverse_tan = -1 / tan(ray_angle);
	if (ray_angle > PI)
	{
		*ray_x = (((int)player->pos_x >> 6) << 6) - 0.0001;
		*ray_y = (player->pos_x - *ray_x) * inverse_tan + player->pos_y;
	}
	else if (ray_angle < PI)
	{
		*ray_x = (((int)player->pos_x >> 6) << 6) + MAP_SIZE;
		*ray_y = (player->pos_x - *ray_x) * inverse_tan + player->pos_y;
	}
	else
	{
		*ray_x = player->pos_x;
		*ray_y = player->pos_y;
	}
}

void	get_horizontal_step(float ray_angle, float *x_offset, float *y_offset)
{
	float	inverse_tan;

	inverse_tan = -1 / tan(ray_angle);
	if (ray_angle > PI)
	{
		*x_offset = -MAP_SIZE;
		*y_offset = -(*x_offset) * inverse_tan;
	}
	else if (ray_angle < PI)
	{
		*x_offset = MAP_SIZE;
		*y_offset = -(*x_offset) * inverse_tan;
	}
	else
	{
		*x_offset = 0;
		*y_offset = 0;
	}
}
int check_horizontal_wall(float rx, float ry, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = (int)(rx) >> 6;
	map_y = (int)(ry) >> 6;
	if (map_x < 0 || map_x >= data->map.max_x
		|| map_y < 0 || map_y >= data->map.max_y)
		return (1);
	if (data->map.map[map_y][map_x] == '1')
		return (1);
	return (0);
}

float	cast_horizontal_ray(float ray_angle, t_player *player, t_data *data)
{
	float	ray_x;
	float	ray_y;
	float	x_offset;
	float	y_offset;
	int		depth_of_field;

	depth_of_field = 0;
	init_horizontal_ray(ray_angle, player, &ray_x, &ray_y);
	get_horizontal_step(ray_angle, &x_offset, &y_offset);
	if (ray_angle == 0 || ray_angle == PI)
		return (1000000.0f);
	while (depth_of_field < 32)
	{
		if (check_horizontal_wall(ray_x, ray_y, data))
			return (dist(player->pos_x, player->pos_y, ray_x, ray_y));
		ray_x += x_offset;
		ray_y += y_offset;
		depth_of_field++;
		if (ray_x < -100 || ray_x > (data->map.max_x * MAP_SIZE + 100)
			|| ray_y < -100 || ray_y > (data->map.max_y * MAP_SIZE + 100))
			break ;
	}
	return (1000000.0f);
}
