/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:03:14 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/12 15:09:46 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_window(t_data *data)
{
	data->img = (t_img_data *)ft_calloc(1, sizeof(t_img_data));
	data->img->bits_per_pixel = 0;
	data->img->line_length = 0;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data->win_ptr)
		return ;
	data->img->ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img->ptr)
		return ;
	data->img->addr = mlx_get_data_addr(data->img->ptr, &data->img->bits_per_pixel,
			&data->img->line_length, &data->img->endian);
}

int	main(int ac, char **av)
{
	t_data		data;
	t_player	player;

	ft_memset(&data, 0, sizeof(t_data));
	ft_memset(&player, 0, sizeof(t_player));
	if (ac != 2)
		return(printf("Error:Wrong input\n"), 1);
	if (!(check_file(av[1])))
		return (printf("Error:Wrong file\n"), 1);
	if (!parsing(av))
		return(printf("Error:Wrong  parsing\n"), 1);
	init_window(&data);
	init_player(&player);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &murder_window_key, &data);
	mlx_hook(data.win_ptr, ClientMessage, NoEventMask, &murder_window, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
