/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:15:57 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/18 10:22:31 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

float	dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

float	normalize_angle(float angle)
{
	if (angle < 0)
		angle += 2 * PI;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

float	fix_fisheye(float distance, float player_angle, float ray_angle)
{
	float	ca;

	ca = player_angle - ray_angle;
	ca = normalize_angle(ca);
	return (distance * cos(ca));
}

float	calculate_wall_height(float distance, t_map map)
{
	float	lineh;

	lineh = (map.size * 320) / distance;
	if (lineh > 320)
		lineh = 320;
	return (lineh);
}

t_ray_result	ray_caster(float ra, t_player *player, t_data *data)
{
	t_ray_result	result;
	float			disth;
	float			distv;
	int				hit_horizontal;

	disth = cast_horizontal_ray(ra, player, data);
	distv = cast_vertical_ray(ra, player, data);
	if (distv < disth)
	{
		result.distance = distv;
		hit_horizontal = 0;
	}
	else
	{
		result.distance = disth;
		hit_horizontal = 1;
	}
	result.wall_side = get_wall_side(ra, hit_horizontal);
	result.wall_type = 1;
	result.distance = fix_fisheye(result.distance, player->angle, ra);
	return (result);
}
