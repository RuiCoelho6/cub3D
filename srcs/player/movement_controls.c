/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:39:49 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/30 17:28:38 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	move_forward(t_player *player, t_data *data, int tile_x, int tile_y)
{
	player->pos_x += cos(-(player->angle - PI / 2)) * 3;
	player->pos_y += sin(-(player->angle - PI / 2)) * 3;
	tile_y = (int)(player->pos_y) >> 6;
	tile_x = (int)(player->pos_x) >> 6;
	if (data->map.map[tile_y][tile_x] == 1)
	{
		player->pos_x -= cos(-(player->angle - PI / 2)) * 3;
		player->pos_y -= sin(-(player->angle - PI / 2)) * 3;
	}
}

void	move_backward(t_player *player, t_data *data, int tile_x, int tile_y)
{
	player->pos_x -= cos(-(player->angle - PI / 2)) * 3;
	player->pos_y -= sin(-(player->angle - PI / 2)) * 3;
	tile_y = (int)(player->pos_y) >> 6;
	tile_x = (int)(player->pos_x) >> 6;
	if (data->map.map[tile_y][tile_x] == 1)
	{
		player->pos_x += cos(-(player->angle - PI / 2)) * 3;
		player->pos_y += sin(-(player->angle - PI / 2)) * 3;
	}
}

void	strafe_left(t_player *player, t_data *data, int tile_x, int tile_y)
{
	player->pos_x += cos(-((player->angle - PI / 2) + PI / 2)) * 3;
	player->pos_y += sin(-((player->angle - PI / 2) + PI / 2)) * 3;
	tile_y = (int)(player->pos_y) >> 6;
	tile_x = (int)(player->pos_x) >> 6;
	if (data->map.map[tile_y][tile_x] == 1)
	{
		player->pos_x -= cos(-((player->angle - PI / 2) + PI / 2)) * 3;
		player->pos_y -= sin(-((player->angle - PI / 2) + PI / 2)) * 3;
	}
}

void	strafe_right(t_player *player, t_data *data, int tile_x, int tile_y)
{
	player->pos_x += cos(-((player->angle - PI / 2) - PI / 2)) * 3;
	player->pos_y += sin(-((player->angle - PI / 2) - PI / 2)) * 3;
	tile_y = (int)(player->pos_y) >> 6;
	tile_x = (int)(player->pos_x) >> 6;
	if (data->map.map[tile_y][tile_x] == 1)
	{
		player->pos_x -= cos(-((player->angle - PI / 2) - PI / 2)) * 3;
		player->pos_y -= sin(-((player->angle - PI / 2) - PI / 2)) * 3;
	}
}
