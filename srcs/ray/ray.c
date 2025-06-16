/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:15:57 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/16 10:54:12 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

float	dist(float ax, float ay, float bx, float by, float ang)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	cast_ray(t_player *player, t_data *data)
{
	float	rx, ry, ra, xo, yo, nTan, aTan, distH, distV, distT, hx, hy, vx, vy, lineH, lineO, ca;
	int		r, mx, my, mp, dof, mapX, mapY;

	mapX = 8;
	mapY = 8;
	ra = player->angle - DR * 30;
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	r = 0;
	while (r < 60)
	{
		// Check the colisao no eixo x (2D)
		dof = 0;
		distH = INT_MAX;
		hx = player->pos_x;
		hy = player->pos_y;
		aTan = -1 / tan(ra);
		if (ra > PI)// looking up
		{
			rx = (((int)player->pos_x >> 6) << 6) - 0.0001;
			ry = (player->pos_x - rx) * aTan + player->pos_y;
			xo = -64;
			yo = -xo * aTan;
		}
		if (ra < PI)// looking down
		{
			rx = (((int)player->pos_x >> 6) << 6) + 64;
			ry = (player->pos_x - rx) * aTan + player->pos_y;
			xo = 64;
			yo = -yo * aTan;
		}
		if (ra == 0 || ra == PI)// looking straight left or straight right
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

			if (mp > 0 && mp < mapX * mapY && data->map.map[mp] == 1)// hit wall
			{
				hx = rx;
				hy = ry;
				distH = dist(player->pos_x, player->pos_y, hx, hy, ra);
				dof = 8;
			}
			else// check next line
			{
				rx += xo;
				ry += yo;
				dof += 1;
		}

		}
		// Check the colisao no eixo y (2D)
		dof = 0;
		distV = INT_MAX;
		vx = player->pos_x;
		vy = player->pos_y;
		nTan = -tan(ra);
		if (ra > PI2 && ra < PI3)// looking left
		{
			ry = (((int)player->pos_y >> 6) << 6) - 0.0001;
			rx = (player->pos_y - ry) * nTan + player->pos_x;
			yo = -64;
			xo = -yo * nTan;
		}
		if (ra < PI2 || ra > PI3)// looking right
		{
			ry = (((int)player->pos_y >> 6) << 6) + 64;
			rx = (player->pos_y - ry) * nTan + player->pos_x;
			yo = 64;
			xo = -yo * nTan;
		}
		if (ra == 0 || ra == PI) // looking straight up or straight down
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

			if (mp > 0 && mp < mapX * mapY && data->map.map[mp] == 1)// hit wall
			{
				vx = rx;
				vy = ry;
				distV = dist(player->pos_x, player->pos_y, vx, vy, ra);
				dof = 8;
			}
			else// check next line
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		if (distV < distH)// vertical wall hit
		{
			rx = vx;
			ry = vy;
			distT = distV;
		}
		if (distV > distH)// horizontal wall hit
		{
			rx = hx;
			ry = hy;
			distT = distH;
		}
		ca = player->angle - ra;
		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
		distT = distT * cos(ca);// fix fisheye
		float mapSize = 1;
		lineH = (mapSize * 320) / distT;// line height
		if (lineH > 320)
			lineH = 320;
		lineO = 160 - lineH / 2;// line offset
		ra += DR;
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
		r++;
	}
}
