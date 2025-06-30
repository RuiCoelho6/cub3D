/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:03:14 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/30 17:15:31 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// Add this function to your parsing code to calculate max_x
void calculate_map_dimensions(t_data *data)
{
    int i;
    int max_width = 0;
    int current_width;
    
    // Calculate max_y (should already be set)
    i = 0;
    while (data->map.map[i])
        i++;
    data->map.max_y = i;
    
    // Calculate max_x (find the longest row)
    i = 0;
    while (i < data->map.max_y)
    {
        current_width = ft_strlen(data->map.map[i]);
        if (current_width > max_width)
            max_width = current_width;
        i++;
    }
    data->map.max_x = max_width;
}

// Debug version to help find issues with player spawn
int find_player_start_debug(t_data *data, t_player *player)
{
    int i, j;
    char player_chars[] = {'N', 'S', 'W', 'E'};
    int player_found = 0;
    
    // Make sure map dimensions are calculated
    calculate_map_dimensions(data);
    
    printf("=== DEBUGGING PLAYER SPAWN ===\n");
    printf("Map dimensions: %d x %d\n", data->map.max_x, data->map.max_y);
    
    // Print the entire map for debugging
    printf("Map contents:\n");
    for (i = 0; i < data->map.max_y; i++)
    {
        if (data->map.map[i])
        {
            printf("Row %2d: [%s] (length: %d)\n", i, data->map.map[i], (int)ft_strlen(data->map.map[i]));
        }
        else
        {
            printf("Row %2d: [NULL]\n", i);
        }
    }
    
    // Search for player characters
    for (i = 0; i < data->map.max_y; i++)
    {
        if (!data->map.map[i])
            continue;
            
        int row_length = ft_strlen(data->map.map[i]);
        
        for (j = 0; j < row_length; j++)
        {
            char cell = data->map.map[i][j];
            
            // Check if this cell contains a player start position
            for (int k = 0; k < 4; k++)
            {
                if (cell == player_chars[k])
                {
                    printf("Found player character '%c' at position (%d, %d)\n", cell, j, i);
                    
                    if (player_found)
                    {
                        printf("Error: Multiple player starting positions found!\n");
                        return (0);
                    }
                    
                    player_found = 1;
                    
                    // Set player position (center in tile)
                    // Using 64 pixels per tile to match your raycasting bit shifting
                    player->pos_x = j * 64 + 32; // Center in tile
                    player->pos_y = i * 64 + 32; // Center in tile
                    
                    // Set starting angle based on direction
                    if (cell == 'N')
                        player->angle = 3 * PI / 2;  // Facing North (up)
                    else if (cell == 'S')
                        player->angle = PI / 2;      // Facing South (down)  
                    else if (cell == 'W')
                        player->angle = PI;          // Facing West (left)
                    else if (cell == 'E')
                        player->angle = 0;           // Facing East (right)
                    
                    // Store player info in map structure
                    data->map.playerx = j;
                    data->map.playery = i;
                    data->map.player_dir = cell;
                    data->map.player_direction = cell;
                    
                    // Replace the player character with empty space
                    data->map.map[i][j] = '0';
                    
                    printf("Player spawned at map position (%d, %d) with direction '%c'\n", 
                           j, i, cell);
                    printf("Player world position: (%.2f, %.2f)\n", 
                           player->pos_x, player->pos_y);
                    printf("Player angle: %.2f radians\n", player->angle);
                }
            }
        }
    }
    
    if (!player_found)
    {
        printf("Error: No player starting position (N/S/W/E) found in map!\n");
        printf("Searched through %d rows\n", data->map.max_y);
    }
    
    printf("=== END DEBUG ===\n");
    return (player_found);
}

// Improved find_player_start function
int find_player_start(t_data *data, t_player *player)
{
    int i, j;
    char player_chars[] = {'N', 'S', 'W', 'E'};
    int player_found = 0;
    
    // Make sure map dimensions are calculated
    calculate_map_dimensions(data);
    
    for (i = 0; i < data->map.max_y; i++)
    {
        // Check if this row exists and get its length
        if (!data->map.map[i])
            continue;
            
        int row_length = ft_strlen(data->map.map[i]);
        
        for (j = 0; j < row_length; j++)
        {
            char cell = data->map.map[i][j];
            
            // Check if this cell contains a player start position
            for (int k = 0; k < 4; k++)
            {
                if (cell == player_chars[k])
                {
                    // Check if we already found a player (there should be only one)
                    if (player_found)
                    {
                        printf("Error: Multiple player starting positions found!\n");
                        return (0);
                    }
                    
                    player_found = 1;
                    
                    // Set player position (center in tile)
                    // Using 64 pixels per tile to match your raycasting bit shifting
                    player->pos_x = j * 64 + 32; // Center in tile
                    player->pos_y = i * 64 + 32; // Center in tile
                    
                    // Set starting angle based on direction
                    if (cell == 'N')
                        player->angle = 3 * PI / 2;  // Facing North (up)
                    else if (cell == 'S')
                        player->angle = PI / 2;      // Facing South (down)  
                    else if (cell == 'W')
                        player->angle = PI;          // Facing West (left)
                    else if (cell == 'E')
                        player->angle = 0;           // Facing East (right)
                    
                    // Store player info in map structure
                    data->map.playerx = j;
                    data->map.playery = i;
                    data->map.player_dir = cell;
                    data->map.player_direction = cell;
                    
                    // Replace the player character with empty space
                    data->map.map[i][j] = '0';
                    
                    printf("Player spawned at map position (%d, %d) with direction '%c'\n", 
                           j, i, cell);
                    printf("Player world position: (%.2f, %.2f)\n", 
                           player->pos_x, player->pos_y);
                }
            }
        }
    }
    
    if (!player_found)
    {
        printf("Error: No player starting position (N/S/W/E) found in map!\n");
        return (0);
    }
    
    return (1); // Success
}

// Alternative version that validates the spawn position
int find_player_start_safe(t_data *data, t_player *player)
{
    int i, j;
    char player_chars[] = {'N', 'S', 'W', 'E'};
    int player_found = 0;
    
    calculate_map_dimensions(data);
    
    for (i = 0; i < data->map.max_y; i++)
    {
        if (!data->map.map[i])
            continue;
            
        int row_length = ft_strlen(data->map.map[i]);
        
        for (j = 0; j < row_length; j++)
        {
            char cell = data->map.map[i][j];
            
            for (int k = 0; k < 4; k++)
            {
                if (cell == player_chars[k])
                {
                    if (player_found)
                    {
                        printf("Error: Multiple player starting positions found!\n");
                        return (0);
                    }
                    
                    // Validate that the spawn position is not surrounded by walls
                    int valid_spawn = 1;
                    
                    // Check if position is on the edge of the map (invalid)
                    if (i == 0 || i == data->map.max_y - 1 || 
                        j == 0 || j >= row_length - 1)
                    {
                        valid_spawn = 0;
                    }
                    
                    // Check surrounding cells for walls (basic validation)
                    if (valid_spawn)
                    {
                        // You can add more validation here if needed
                        // For example, check if player is completely surrounded by walls
                    }
                    
                    if (!valid_spawn)
                    {
                        printf("Error: Player spawn position is invalid (too close to edge or surrounded by walls)\n");
                        return (0);
                    }
                    
                    player_found = 1;
                    
                    // Set player position using 64-pixel tiles
                    player->pos_x = j * 64 + 32;
                    player->pos_y = i * 64 + 32;
                    
                    // Set starting angle
                    if (cell == 'N')
                        player->angle = 3 * PI / 2;
                    else if (cell == 'S')
                        player->angle = PI / 2;
                    else if (cell == 'W')
                        player->angle = PI;
                    else if (cell == 'E')
                        player->angle = 0;
                    
                    // Store player info
                    data->map.playerx = j;
                    data->map.playery = i;
                    data->map.player_dir = cell;
                    data->map.player_direction = cell;
                    
                    // Replace with empty space
                    data->map.map[i][j] = '0';
                    
                    printf("Player spawned at (%d, %d) facing '%c'\n", j, i, cell);
                }
            }
        }
    }
    
    return (player_found);
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
	if (!find_player_start_safe(&data, &player))
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
