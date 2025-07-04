/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:03:14 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/03 11:53:55 by ppassos          ###   ########.fr       */
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
    printf("%f\n", data.colors.fcolor[0]);
    printf("%f\n", data.colors.fcolor[1]);
    printf("%f\n", data.colors.fcolor[2]);
    printf("\n\n");
    printf("%f\n", data.colors.ccolor[0]);
    printf("%f\n", data.colors.ccolor[1]);
    printf("%f\n", data.colors.ccolor[2]);
    printf("\n\n");
    printf("1:%s\n", data.texture.no);
    printf("2:%s\n", data.texture.so);
    printf("3:%s\n", data.texture.we);
    printf("4:%s\n", data.texture.ea);
	init_window(&data);
	find_player_start(&data);
	init_player(&player, &data);
    //init_texture(&data);
	data.player = &player;
	render_scene(&player, &data);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &murder_window_key, &data);
	mlx_hook(data.win_ptr, ClientMessage, NoEventMask, &murder_window, &data);
	mlx_loop(data.mlx_ptr);
	free_data(&data);
	return (0);
}
