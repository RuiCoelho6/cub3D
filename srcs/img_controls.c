/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:36:00 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/11 15:36:49 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_img_data	*init_image(t_data *data)
{
	t_img_data	*img;

	img = (t_img_data *)ft_calloc(1, sizeof(t_img_data));
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->img->ptr)
		return (NULL);
	img->addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}
