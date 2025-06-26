/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:59:14 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/26 11:07:33 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_window(t_data *data)
{
	data->img = ft_calloc(1, sizeof(t_img_data));
	if (!data->img)
		exit(EXIT_FAILURE);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data->win_ptr)
		exit(EXIT_FAILURE);
	data->img->ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img->ptr)
		exit(EXIT_FAILURE);
	data->img->addr = mlx_get_data_addr(data->img->ptr,
			&data->img->bits_per_pixel,
			&data->img->line_length,
			&data->img->endian);
	if (!data->img->addr)
	{
		write(2, "Error: Failed to get image data address.\n", 41);
		exit(EXIT_FAILURE);
	}
}

void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	handle_no_event(void)
{
	return (0);
}

int	murder_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->img);
	exit(1);
	return (0);
}

int	murder_window_key(int keysym, t_data *mlx)
{
	if (keysym == XK_Escape)
		murder_window(mlx);
	return (0);
}
