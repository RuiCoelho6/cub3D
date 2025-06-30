/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:04:53 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/30 16:10:31 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	init_player(t_player *player, t_data *data)
{
	player->pos_x = 300;
	player->pos_y = 300;
	if (strcmp(&data->map.player_direction, "N"))
		player->angle = PI / 2;
	else if (strcmp(&data->map.player_direction, "E"))
		player->angle = 2 * PI;
	else if (strcmp(&data->map.player_direction, "S"))
		player->angle = (3 * PI) / 2;
	else if (strcmp(&data->map.player_direction, "W"))
		player->angle = PI;
	player->pitch = 0;
	player->dir_x = cos(player->angle);
	player->dir_y = sin(player->angle);
}

void	check_movement(t_data *data, int keycode, int tile_x, int tile_y)
{
	if (keycode == 119)
		move_forward(data->player, data, tile_x, tile_y);
	else if (keycode == 115)
		move_backward(data->player, data, tile_x, tile_y);
	else if (keycode == 100)
		strafe_left(data->player, data, tile_x, tile_y);
	else if (keycode == 97)
		strafe_right(data->player, data, tile_x, tile_y);
}

void	check_looking(t_data *data, int keycode)
{
	if (keycode == 65361)
		data->player->angle -= 0.1;
	else if (keycode == 65363)
		data->player->angle += 0.1;
	else if (keycode == 65364)
	{
		data->player->pitch -= 0.3;
		if (data->player->pitch < -4.5)
			data->player->pitch = -4.5;
	}
	else if (keycode == 65362)
	{
		data->player->pitch += 0.3;
		if (data->player->pitch > 3.5)
			data->player->pitch = 3.5;
	}
}

int	key_hook(int keycode, t_data *data)
{
	int	tile_x;
	int	tile_y;

	tile_x = 0;
	tile_y = 0;
	if (keycode == 65307)
		exit(0);
	check_movement(data, keycode, tile_x, tile_y);
	check_looking(data, keycode);
	data->player->angle = normalize_angle(data->player->angle);
	render_scene(data->player, data);
	return (0);
}
