/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_cast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:20:54 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/17 14:21:30 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	init_horizontal_ray(float ra, t_player *player, float *rx, float *ry)
{
	float	atan;
	float	xo;
	float	yo;

	atan = -1 / tan(ra);
	if (ra > PI)
	{
		*rx = (((int)player->pos_x >> 6) << 6) - 0.0001;
		*ry = (player->pos_x - *rx) * atan + player->pos_y;
	}
	else if (ra < PI)
	{
		*rx = (((int)player->pos_x >> 6) << 6) + 64;
		*ry = (player->pos_x - *rx) * atan + player->pos_y;
	}
	else
	{
		*rx = player->pos_x;
		*ry = player->pos_y;
	}
}

void	get_horizontal_step(float ra, float *xo, float *yo)
{
	float	atan;

	atan = -1 / tan(ra);
	if (ra > PI)
	{
		*xo = -64;
		*yo = -(*xo) * atan;
	}
	else if (ra < PI)
	{
		*xo = 64;
		*yo = -(*xo) * atan;
	}
	else
	{
		*xo = 0;
		*yo = 0;
	}
}

int	check_horizontal_wall(float rx, float ry, t_data *data)
{
	int	mx;
	int	my;

	mx = (int)(rx) >> 6;
	my = (int)(ry) >> 6;
	if (mx >= 0 && mx < 8 && my >= 0 && my < 8 && data->map.map[my][mx] == 1)
		return (1);
	return (0);
}

float	cast_horizontal_ray(float ra, t_player *player, t_data *data)
{
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	int		dof;

	dof = 0;
	init_horizontal_ray(ra, player, &rx, &ry);
	get_horizontal_step(ra, &xo, &yo);
	if (ra == 0 || ra == PI)
		dof = 8;
	while (dof < 8)
	{
		if (check_horizontal_wall(rx, ry, data))
			return (dist(player->pos_x, player->pos_y, rx, ry));
		rx += xo;
		ry += yo;
		dof++;
	}
	return (INT_MAX);
}
