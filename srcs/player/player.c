/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:04:53 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/21 14:18:23 by rpires-c         ###   ########.fr       */
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
	player->key_up = 0;
	player->key_left = 0;
	player->key_down = 0;
	player->key_right = 0;
}

void	process_movement(t_data *data)
{
	int	moved = 0;

	if (data->player->key_up == 1)
	{
		move_forward(data->player, data);
		moved = 1;
	}
	if (data->player->key_down == 1)
	{
		move_backward(data->player, data);
		moved = 1;
	}
	if (data->player->key_left == 1)
		data->player->angle -= 0.1;
	if (data->player->key_right == 1)
		data->player->angle += 0.1;
	data->player->angle = normalize_angle(data->player->angle);
	if (moved || data->player->key_left || data->player->key_right)
		render_scene(data->player, data);
}

int	game_loop(t_data *data)
{
	process_movement(data);
	return (0);
}
