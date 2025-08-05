/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_release.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:35:33 by rpires-c          #+#    #+#             */
/*   Updated: 2025/08/05 17:30:18 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		murder_window(data);
	if (keycode == 119)
		data->player->key_forward = true;
	if (keycode == 115)
		data->player->key_backward = true;
	if (keycode == 97)
		data->player->key_strafe_left = true;
	if (keycode == 100)
		data->player->key_strafe_right = true;
	if (keycode == 65361)
		data->player->key_turn_left = true;
	if (keycode == 65363)
		data->player->key_turn_right = true;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == 119)
		data->player->key_forward = false;
	if (keycode == 115)
		data->player->key_backward = false;
	if (keycode == 97)
		data->player->key_strafe_left = false;
	if (keycode == 100)
		data->player->key_strafe_right = false;
	if (keycode == 65361)
		data->player->key_turn_left = false;
	if (keycode == 65363)
		data->player->key_turn_right = false;
	return (0);
}

int	is_wall(float x, float y, t_data *data)
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

int	can_move(float new_x, float new_y, t_data *data)
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
