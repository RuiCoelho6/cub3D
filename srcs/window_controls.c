/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:59:14 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/11 15:36:42 by rpires-c         ###   ########.fr       */
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
