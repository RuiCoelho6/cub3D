/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:04:53 by rpires-c          #+#    #+#             */
/*   Updated: 2025/08/05 17:42:50 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	init_player(t_player *player, t_data *data)
{
	player->pos_x = data->map.playerx * TILE_SIZE + (TILE_SIZE / 2);
	player->pos_y = data->map.playery * TILE_SIZE + (TILE_SIZE / 2);
	if (data->map.player_dir == 'E')
		player->angle = (3 * PI) / 2;
	else if (data->map.player_dir == 'S')
		player->angle = 0;
	else if (data->map.player_dir == 'W')
		player->angle = PI / 2;
	else if (data->map.player_dir == 'N')
		player->angle = PI;
	player->key_forward = false;
	player->key_backward = false;
	player->key_strafe_left = false;
	player->key_strafe_right = false;
	player->key_turn_left = false;
	player->key_turn_right = false;
}

bool	handle_movement_keys(t_data *data)
{
	bool	moved;

	moved = false;
	if (data->player->key_forward)
	{
		move_forward(data->player, data);
		moved = true;
	}
	if (data->player->key_backward)
	{
		move_backward(data->player, data);
		moved = true;
	}
	if (data->player->key_strafe_left)
	{
		strafe_left(data->player, data);
		moved = true;
	}
	if (data->player->key_strafe_right)
	{
		strafe_right(data->player, data);
		moved = true;
	}
	return (moved);
}

void	process_movement(t_data *data)
{
	bool	moved;

	moved = handle_movement_keys(data);
	if (data->player->key_turn_left)
		data->player->angle -= 0.04;
	if (data->player->key_turn_right)
		data->player->angle += 0.04;
	data->player->angle = normalize_angle(data->player->angle);
	if (moved || data->player->key_turn_left || data->player->key_turn_right)
		render_scene(data->player, data);
}

int	game_loop(t_data *data)
{
	process_movement(data);
	return (0);
}
