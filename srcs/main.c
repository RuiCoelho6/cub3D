/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:03:14 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/21 10:59:38 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	calculate_map_dimensions(t_data *data)
{
	int	i;
	int	max_width;
	int	current_width;

	i = 0;
	max_width = 0;
	while (data->map.map[i])
		i++;
	data->map.max_y = i;
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

void	find_player_start(t_data *data)
{
	int		i;
	int		j;
	char	cell;
	int		row_length;

	calculate_map_dimensions(data);
	i = 0;
	while (i < data->map.max_y)
	{
		if (!data->map.map[i])
			continue ;
		row_length = ft_strlen(data->map.map[i]);
		j = 0;
		while (j < row_length)
		{
			cell = data->map.map[i][j];
			if (cell == 'N' || cell == 'S' || cell == 'W' || cell == 'E')
			{
				data->map.playerx = j;
				data->map.playery = i;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data		data;
	t_player	player;

	ft_memset(&data, 0, sizeof(t_data));
	if (ac != 2)
		return (printf("Error:Wrong input\n"), 1);
	if (!(check_file(av[1])))
		return (printf("Error:Wrong file\n"), 1);
	if (!parsing_and_init(av[1], &data))
		return (free_data(&data), 1);
	init_window(&data);
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
