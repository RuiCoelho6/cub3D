/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:03:14 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/30 16:54:09 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int find_player_start(t_data *data, t_player *player)
{
    int i, j;
    char player_chars[] = {'N', 'S', 'W', 'E'};
    
    for (i = 0; i < data->map.max_y; i++)
    {
        for (j = 0; j < data->map.max_x; j++)
        {
            char cell = data->map.map[i][j];
            
            // Check if this cell contains a player start position
            for (int k = 0; k < 4; k++)
            {
                if (cell == player_chars[k])
                {
                    // Found player start position
                    player->pos_x = j * data->map.size + (data->map.size / 2); // Center in tile
                    player->pos_y = i * data->map.size + (data->map.size / 2); // Center in tile
                    
                    // Set starting angle based on direction
                    if (cell == 'N')
                        player->angle = 3 * PI / 2;  // Facing North (up)
                    else if (cell == 'S')
                        player->angle = PI / 2;      // Facing South (down)  
                    else if (cell == 'W')
                        player->angle = PI;          // Facing West (left)
                    else if (cell == 'E')
                        player->angle = 0;           // Facing East (right)
                    
                    // Store player info in your map structure
                    data->map.playerx = j;
                    data->map.playery = i;
                    data->map.player_dir = cell;
                    data->map.player_direction = cell;
                    
                    // Replace the player character with empty space
                    data->map.map[i][j] = '0';
                    
                    return (1); // Success
                }
            }
        }
    }
    return (0); // No player start found
}

// Main function
int	main(int ac, char **av)
{
	t_data		data;
	t_player	player;

	ft_memset(&data, 0, sizeof(t_data));
	if (ac != 2)
		return(printf("Error:Wrong input\n"), 1);
	if (!(check_file(av[1])))
		return (printf("Error:Wrong file\n"), 1);
	if (!parsing_and_init(av[1], &data))
		return (free_data(&data), 1);
	init_window(&data);
	init_player(&player, &data);
	data.player = &player;
	if (!find_player_start(&data, &player))
    {
        printf("Error: No player starting position (N/S/W/E) found in map!\n");
        return (1);
    }
	render_scene(&player, &data);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &murder_window_key, &data);
	mlx_hook(data.win_ptr, ClientMessage, NoEventMask, &murder_window, &data);
	mlx_loop(data.mlx_ptr);
	free_data(&data);
	return (0);
}
