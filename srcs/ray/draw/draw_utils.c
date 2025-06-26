/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:04:47 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/26 14:19:51 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	apply_distance_shading(int base_color, float distance)
{
	float	fade_factor;
	int		r;
	int		g;
	int		b;

	fade_factor = 2.0f - (distance / 500.0f);
	if (fade_factor < 0.3f)
		fade_factor = 0.3f;
	r = ((base_color >> 16) & 0xFF) * fade_factor;
	g = ((base_color >> 8) & 0xFF) * fade_factor;
	b = (base_color & 0xFF) * fade_factor;
	return ((r << 16) | (g << 8) | b);
}

int	get_wall_side(float ray_angle, int hit_horizontal)
{
	if (hit_horizontal)
	{
		if (ray_angle > 0 && ray_angle < PI)
			return (0);
		else
			return (1);
	}
	else
	{
		if (ray_angle > PI / 2 && ray_angle < 3 * PI / 2)
			return (2);
		else
			return (3);
	}
}

int	get_wall_color(int wall_side)
{
	if (wall_side == 0)
		return (WALL_NORTH);
	else if (wall_side == 1)
		return (WALL_SOUTH);
	else if (wall_side == 2)
		return (WALL_WEST);
	else
		return (WALL_EAST);
}
