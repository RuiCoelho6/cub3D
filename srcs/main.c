/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:03:14 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/30 16:13:27 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	render_scene(&player, &data);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &murder_window_key, &data);
	mlx_hook(data.win_ptr, ClientMessage, NoEventMask, &murder_window, &data);
	mlx_loop(data.mlx_ptr);
	free_data(&data);
	return (0);
}
