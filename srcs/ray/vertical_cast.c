/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:18:41 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/17 14:20:18 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	init_vertical_ray(float ra, t_player *player, float *rx, float *ry)
{
	float	ntan;

	ntan = -tan(ra);
	if (ra > (PI / 2) && ra < (3 * PI / 2))
	{
		*ry = (((int)player->pos_y >> 6) << 6) - 0.0001;
		*rx = (player->pos_y - *ry) * ntan + player->pos_x;
	}
	else if (ra < (PI / 2) || ra > (3 * PI / 2))
	{
		*ry = (((int)player->pos_y >> 6) << 6) + 64;
		*rx = (player->pos_y - *ry) * ntan + player->pos_x;
	}
	else
	{
		*rx = player->pos_x;
		*ry = player->pos_y;
	}
}

void	get_vertical_step(float ra, float *xo, float *yo)
{
	float	ntan;

	ntan = -tan(ra);
	if (ra > (PI / 2) && ra < (3 * PI / 2))
	{
		*yo = -64;
		*xo = -(*yo) * ntan;
	}
	else if (ra < (PI / 2) || ra > (3 * PI / 2))
	{
		*yo = 64;
		*xo = -(*yo) * ntan;
	}
	else
	{
		*xo = 0;
		*yo = 0;
	}
}

int	check_vertical_wall(float rx, float ry, t_data *data)
{
	int	mx;
	int	my;

	mx = (int)(rx) >> 6;
	my = (int)(ry) >> 6;
	if (mx >= 0 && mx < 8 && my >= 0 && my < 8 && data->map.map[my][mx] == 1)
		return (1);
	return (0);
}

float	cast_vertical_ray(float ra, t_player *player, t_data *data)
{
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	int		dof;

	dof = 0;
	init_vertical_ray(ra, player, &rx, &ry);
	get_vertical_step(ra, &xo, &yo);
	if (ra == 0 || ra == PI)
		dof = 8;
	while (dof < 8)
	{
		if (check_vertical_wall(rx, ry, data))
			return (dist(player->pos_x, player->pos_y, rx, ry));
		rx += xo;
		ry += yo;
		dof++;
	}
	return (INT_MAX);
}
