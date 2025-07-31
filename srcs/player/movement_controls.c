/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:39:49 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/31 14:39:58 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		murder_window(data);
	if (keycode == 119 || keycode == 65362)
		data->player->key_up = true;
	if (keycode == 97 || keycode == 65361)
		data->player->key_left = true;
	if (keycode == 115 || keycode == 65364)
		data->player->key_down = true;
	if (keycode == 100 || keycode == 65363)
		data->player->key_right = true;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == 119 || keycode == 65362)
		data->player->key_up = false;
	if (keycode == 97 || keycode == 65361)
		data->player->key_left = false;
	if (keycode == 115 || keycode == 65364)
		data->player->key_down = false;
	if (keycode == 100 || keycode == 65363)
		data->player->key_right = false;
	return (0);
}

static int	is_wall(float x, float y, t_data *data)
{
	int	tile_x;
	int	tile_y;

	tile_x = (int)x >> 6;
	tile_y = (int)y >> 6;
	if (tile_x < 0 || tile_y < 0
		|| tile_y >= data->map.max_y
		|| tile_x >= (int)ft_strlen(data->map.map[tile_y]))
		return (1);
	return (data->map.map[tile_y][tile_x] == '1');
}

static int	can_move(float new_x, float new_y, t_data *data)
{
	if (is_wall(new_x - PLAYER_RADIUS, new_y - PLAYER_RADIUS, data))
		return (0);
	if (is_wall(new_x + PLAYER_RADIUS, new_y - PLAYER_RADIUS, data))
		return (0);
	if (is_wall(new_x - PLAYER_RADIUS, new_y + PLAYER_RADIUS, data))
		return (0);
	if (is_wall(new_x + PLAYER_RADIUS, new_y + PLAYER_RADIUS, data))
		return (0);
	return (1);
}

void	move_forward(t_player *player, t_data *data)
{
	player->pos_x += cos(-(player->angle - PI / 2)) * 2;
	player->pos_y += sin(-(player->angle - PI / 2)) * 2;
	if (!can_move(player->pos_x, player->pos_y, data))
	{
		player->pos_x -= cos(-(player->angle - PI / 2)) * 2;
		player->pos_y -= sin(-(player->angle - PI / 2)) * 2;
	}
}

void	move_backward(t_player *player, t_data *data)
{
	int	tile_x;
	int	tile_y;

	player->pos_x -= cos(-(player->angle - PI / 2)) * 2;
	player->pos_y -= sin(-(player->angle - PI / 2)) * 2;
	tile_y = (int)(player->pos_y) >> 6;
	tile_x = (int)(player->pos_x) >> 6;
	if (!can_move(player->pos_x, player->pos_y, data))
	{
		player->pos_x += cos(-(player->angle - PI / 2)) * 2;
		player->pos_y += sin(-(player->angle - PI / 2)) * 2;
	}
}
