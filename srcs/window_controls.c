/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:59:14 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/11 11:31:48 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	handle_no_event(void)
{
	return (0);
}

int	murder_window(t_mlx_data *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img->ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->window_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx->img);
	exit(1);
	return (0);
}

int	murder_window_key(int keysym, t_mlx_data *mlx)
{
	if (keysym == XK_Escape)
		murder_window(mlx);
	return (0);
}