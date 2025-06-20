/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:03:14 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/20 14:10:24 by ppassos          ###   ########.fr       */
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
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!data->win_ptr)
		return ;
	data->img->ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->img->ptr)
		return ;
	data->img->addr = mlx_get_data_addr(data->img->ptr, &data->img->bits_per_pixel,
			&data->img->line_length, &data->img->endian);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (ac != 2)
		return(printf("Error:Wrong input\n"), 1);
	if (!(check_file(av[1])))
		return (printf("Error:Wrong file\n"), 1);
	if (!parsing_and_init(av[1], &data))
		return (free_data(&data), 1);
	/*init_window(&data);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &murder_window_key, &data);
	mlx_hook(data.win_ptr, ClientMessage, NoEventMask, &murder_window, &data);
	mlx_loop(data.mlx_ptr);*/
	free_data(&data);
	return (0);
}
