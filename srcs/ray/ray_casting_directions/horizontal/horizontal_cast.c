/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_cast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:20:54 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/09 16:56:32 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	init_horizontal_ray(float ray_angle, t_player *player,
			float *ray_x, float *ray_y)
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

int	check_horizontal_wall(float rx, float ry, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = (int)(rx) >> 6;
	map_y = (int)(ry) >> 6;
	if (map_x < 0 || map_y < 0
		|| map_y >= data->map.max_y
		|| map_x >= (int)ft_strlen(data->map.map[map_y]))
		return (1);
	if (data->map.map[map_y][map_x] == '1')
		return (1);
	return (0);
}
