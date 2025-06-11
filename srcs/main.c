/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:03:14 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/11 10:53:07 by ppassos          ###   ########.fr       */
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

	ft_memset(&data, 0, sizeof(t_data));
	if (ac != 2)
		return(printf("Error:Wrong input\n"), 1);
	if (!(check_file(av[1])))
		return (printf("Error:Wrong file\n"), 1);
	if (!parsing(av))
		return(printf("Error:Wrong  parsing\n"), 1);
	init_window(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, &handle_no_event, &mlx);
	mlx_hook(mlx.window_ptr, KeyPress, KeyPressMask, &murder_window_key, &mlx);
	mlx_hook(mlx.window_ptr, ClientMessage, NoEventMask, &murder_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
