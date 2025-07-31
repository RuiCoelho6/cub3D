/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:04:47 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/31 16:46:50 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	apply_distance_shading(int base_color, float distance)
{
	float	fade;
	int		r;
	int		g;
	int		b;

	fade = 1.6f - (distance / 500.0f);
	if (fade < 0.0f)
		fade = 0.0f;
	r = (int)(((base_color >> 16) & 0xFF) * fade);
	g = (int)(((base_color >> 8) & 0xFF) * fade);
	b = (int)((base_color & 0xFF) * fade);
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return ((r << 16) | (g << 8) | b);
}

int	get_wall_side(float ray_angle, int hit_horizontal)
{
	if (hit_horizontal)
	{
		if (ray_angle > 0 && ray_angle < PI)
			return (2);
		else
			return (3);
	}
	else
	{
		if (ray_angle > PI / 2 && ray_angle < 3 * PI / 2)
			return (0);
		else
			return (1);
	}
}
