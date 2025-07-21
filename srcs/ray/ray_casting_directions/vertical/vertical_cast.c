/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_cast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:18:41 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/21 10:30:16 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../main.h"

void	init_vertical_ray(float ray_angle, t_player *player,
			float *ray_x, float *ray_y)
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
		*ray_y = (((int)player->pos_y >> 6) << 6) + MAP_SIZE;
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
		*y_offset = -MAP_SIZE;
		*x_offset = -(*y_offset) * negative_tangent;
	}
	else if (ray_angle < (PI / 2) || ray_angle > (3 * PI / 2))
	{
		*y_offset = MAP_SIZE;
		*x_offset = -(*y_offset) * negative_tangent;
	}
	else
	{
		*x_offset = 0;
		*y_offset = 0;
	}
}

int	check_vertical_wall(float rx, float ry, t_data *data)
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
