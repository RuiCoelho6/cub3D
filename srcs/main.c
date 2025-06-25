/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:03:14 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/25 14:29:35 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int key_hook(int keycode, t_data *data)
{
	t_player *player = data->player; // Get player from data

	if (keycode == 65307) // ESC key
		exit(0);
	else if (keycode == 119) // W key - move forward
	{
		player->pos_x += cos(player->angle) * 5;
		player->pos_y += sin(player->angle) * 5;
	}
	else if (keycode == 115) // S key - move backward
	{
		player->pos_x -= cos(player->angle) * 5;
		player->pos_y -= sin(player->angle) * 5;
	}
	else if (keycode == 97) // A key - turn left
		player->angle -= 0.1;
	else if (keycode == 100) // D key - turn right
		player->angle += 0.1;
	player->angle = normalize_angle(player->angle);
	render_scene(player, data);
	return (0);
}

// Initialize map
void	init_map(t_data *data)
{
	int	i;
	int	j;
	int	map_data[MAP_SIZE][MAP_SIZE] = {
		{1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,1},
		{1,0,1,0,0,1,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,1,0,0,1,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1}
	};
	for (i = 0; i < MAP_SIZE; i++)
	{
		for (j = 0; j < MAP_SIZE; j++)
			data->map.map[i][j] = map_data[i][j];
	}
	data->map.size = 64;
	data->map.width = MAP_SIZE;
	data->map.height = MAP_SIZE;
}

// Main function
int main(void)
{
	t_data		data;
	t_player	player;

	init_window(&data);
	init_map(&data);
	init_player(&player);
	data.player = &player;
	render_scene(&player, &data);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &murder_window_key, &data);
	mlx_hook(data.win_ptr, ClientMessage, NoEventMask, &murder_window, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
