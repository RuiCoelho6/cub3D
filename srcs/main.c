/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:03:14 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/09 11:06:05 by rpires-c         ###   ########.fr       */
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

// Alternative version that validates the spawn position
void find_player_start(t_data *data)
{
	int	i;
	int	j;

    calculate_map_dimensions(data);
    for (i = 0; i < data->map.max_y; i++)
    {
        if (!data->map.map[i])
            continue ;
        int row_length = ft_strlen(data->map.map[i]);
        
        for (j = 0; j < row_length; j++)
        {
            char cell = data->map.map[i][j];

            if (cell == 'N'|| cell == 'S' || cell == 'W' || cell == 'E')
            {
                data->map.playerx = j;
                data->map.playery = i;
            }
        }
    }
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
	// Initialize textures AFTER initializing MLX
	if (!init_texture(&data))
		return (free_data(&data), 1);
	
	find_player_start(&data);
	init_player(&player, &data);
	data.player = &player;
	render_scene(&player, &data);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &murder_window_key, &data);
	mlx_hook(data.win_ptr, ClientMessage, NoEventMask, &murder_window, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
