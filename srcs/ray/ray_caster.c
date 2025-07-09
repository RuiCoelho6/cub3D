/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:15:57 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/09 15:10:01 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

float	dist(float start_x, float start_y, float end_x, float end_y)
{
	return (sqrt((end_x - start_x) * (end_x - start_x)
			+ (end_y - start_y) * (end_y - start_y)));
}

float	normalize_angle(float angle)
{
	if (angle < 0)
		angle += 2 * PI;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

float	fix_fisheye(float wall_distance, float player_angle, float ray_angle)
{
	float	angle_difference;

	angle_difference = player_angle - ray_angle;
	angle_difference = normalize_angle(angle_difference);
	return (wall_distance * cos(angle_difference));
}

float	calculate_wall_height(float wall_distance, t_map map)
{
	float	projected_wall_height;

	projected_wall_height = (map.size * WIN_HEIGHT) / wall_distance;
	if (projected_wall_height > WIN_HEIGHT)
		projected_wall_height = WIN_HEIGHT;
	return (projected_wall_height);
}

t_ray_result	ray_caster(float ray_angle, t_player *player, t_data *data)
{
	t_ray_result	result;
	t_ray_hit		horizontal_hit;
	t_ray_hit		vertical_hit;
	int				hit_horizontal_wall;

	horizontal_hit = cast_horizontal_ray_with_hit(ray_angle, player, data);
	vertical_hit = cast_vertical_ray_with_hit(ray_angle, player, data);
	if (vertical_hit.distance < horizontal_hit.distance)
	{
		result.distance = vertical_hit.distance;
		result.hit_x = vertical_hit.hit_x;
		result.hit_y = vertical_hit.hit_y;
		hit_horizontal_wall = 0;
	}
	else
	{
		result.distance = horizontal_hit.distance;
		result.hit_x = horizontal_hit.hit_x;
		result.hit_y = horizontal_hit.hit_y;
		hit_horizontal_wall = 1;
	}
	result.wall_side = get_wall_side(ray_angle, hit_horizontal_wall);
	result.wall_type = 1;
	result.distance = fix_fisheye(result.distance, player->angle, ray_angle);
	return (result);
}
