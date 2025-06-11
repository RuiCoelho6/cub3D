/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:03:14 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/11 11:36:02 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_window(t_mlx_data *mlx)
{
	mlx->img = (t_img_data *)ft_calloc(1, sizeof(t_img_data));
	mlx->img->bits_per_pixel = 0;
	mlx->img->line_length = 0;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return ;
	mlx->window_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!mlx->window_ptr)
		return ;
	mlx->img->ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	if (!mlx->img->ptr)
		return ;
	mlx->img->addr = mlx_get_data_addr(mlx->img->ptr, &mlx->img->bits_per_pixel,
			&mlx->img->line_length, &mlx->img->endian);
}

int	main()
{
	t_mlx_data	mlx;

	init_window(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, &handle_no_event, &mlx);
	mlx_hook(mlx.window_ptr, KeyPress, KeyPressMask, &murder_window_key, &mlx);
	mlx_hook(mlx.window_ptr, ClientMessage, NoEventMask, &murder_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
