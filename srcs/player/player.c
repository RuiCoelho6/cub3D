/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:04:53 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/21 15:07:41 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	init_player(t_player *player, t_data *data)
{
	player->pos_x = data->map.playerx * MAP_SIZE + (MAP_SIZE / 2);
	player->pos_y = data->map.playery * MAP_SIZE + (MAP_SIZE / 2);
	if (data->map.player_dir == 'E')
		player->angle = (3 * PI) / 2;
	else if (data->map.player_dir == 'S')
		player->angle = 0;
	else if (data->map.player_dir == 'W')
		player->angle = PI / 2;
	else if (data->map.player_dir == 'N')
		player->angle = PI;
	player->key_up = false;
	player->key_left = false;
	player->key_down = false;
	player->key_right = false;
}

void	process_movement(t_data *data)
{
	bool	moved;

	moved = false;
	if (data->player->key_up)
	{
		move_forward(data->player, data);
		moved = true;
	}
	if (data->player->key_down)
	{
		move_backward(data->player, data);
		moved = true;
	}
	if (data->player->key_left)
		data->player->angle -= 0.04;
	if (data->player->key_right)
		data->player->angle += 0.04;
	data->player->angle = normalize_angle(data->player->angle);
	if (moved || data->player->key_left || data->player->key_right)
		render_scene(data->player, data);
}

int	game_loop(t_data *data)
{
	process_movement(data);
	return (0);
}
