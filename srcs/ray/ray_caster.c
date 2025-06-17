/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:15:57 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/17 14:21:20 by rpires-c         ###   ########.fr       */
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

void	ray_caster(t_player *player, t_data *data, t_map map)
{
	float	ra;
	float	disth;
	float	distv;
	float	distt;
	int		r;

	ra = player->angle - DR * 30;
	ra = normalize_angle(ra);
	r = 0;
	while (r < 60)
	{
		disth = cast_horizontal_ray(ra, player, data);
		distv = cast_vertical_ray(ra, player, data);
		if (distv < disth)
			distt = distv;
		else
			distt = disth;
		distt = fix_fisheye(distt, player->angle, ra);
		calculate_wall_height(distt, map);
		ra += DR;
		ra = normalize_angle(ra);
		r++;
	}
}
