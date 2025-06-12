/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:15:57 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/12 17:26:32 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	cast_ray(t_player *player, t_data *data)
{
	float	rx, ry, ra, xo, yo;
	int		r, mx, my, mp, dof, mapX, mapY;

	mapX = 10;
	mapY = 10;
	ra = player->angle;
	r = 0;
	while (r < 1)
	{
		// Check the colisao no eixo x (2D)
		dof = 0;
		float	aTan = -1 / tan(ra);
		if (ra > PI)
		{
			ry = (((int)player->pos_y >> 6) << 6) - 0.0001;
			rx = (player->pos_y - ry) * aTan + player->pos_x;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra < PI)
		{
			ry = (((int)player->pos_y >> 6) << 6) + 64;
			rx = (player->pos_y - ry) * aTan + player->pos_x;
			yo = 64;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = player->pos_x;
			ry = player->pos_y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int) (rx) >> 6;
			my = (int) (ry) >> 6;
			mp = my * mapX + mx;
		}
		if (mp < mapX * mapY && data->map.map[mp] == 1)
			dof = 8;
		else
		{
			rx += xo;
			ry += yo;
			dof += 1;
		}

		// Check the colisao no eixo x (2D)
		dof = 0;
		float	nTan = -tan(ra);
		if (ra > PI2 && ra < PI3)
		{
			ry = (((int)player->pos_y >> 6) << 6) - 0.0001;
			rx = (player->pos_y - ry) * nTan + player->pos_x;
			yo = -64;
			xo = -yo * nTan;
		}
		if (ra < PI2 || ra > PI3)
		{
			ry = (((int)player->pos_y >> 6) << 6) + 64;
			rx = (player->pos_y - ry) * nTan + player->pos_x;
			yo = 64;
			xo = -yo * nTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = player->pos_x;
			ry = player->pos_y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int) (rx) >> 6;
			my = (int) (ry) >> 6;
			mp = my * mapX + mx;
		}
		if (mp < mapX * mapY && data->map.map[mp] == 1)
			dof = 8;
		else
		{
			rx += xo;
			ry += yo;
			dof += 1;
		}
		r++;
	}
}
