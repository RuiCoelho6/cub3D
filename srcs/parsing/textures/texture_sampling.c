/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_sampling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:25:13 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/24 14:22:45 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	get_texture_pixel(t_data *data, int wall_side, int tex_x, int tex_y)
{
	char	*texture_data;
	int		pixel_offset;
	int		*pixel_ptr;

	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= data->texture.width)
		tex_x = data->texture.width - 1;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= data->texture.height)
		tex_y = data->texture.height - 1;
	if (wall_side == 0)
		texture_data = data->texture.data_so;
	else if (wall_side == 1)
		texture_data = data->texture.data_no;
	else if (wall_side == 2)
		texture_data = data->texture.data_ea;
	else
		texture_data = data->texture.data_we;
	pixel_offset = (tex_y * data->texture.line_len)
		+ (tex_x * (data->texture.bpp / 8));
	pixel_ptr = (int *)(texture_data + pixel_offset);
	return (*pixel_ptr);
}

int	calculate_texture_x(t_ray_result ray_result, t_data *data)
{
	float	wall_hit_ratio;
	int		tex_x;

	if (ray_result.wall_side == 0 || ray_result.wall_side == 1)
	{
		wall_hit_ratio = ray_result.hit_x / TILE_SIZE;
		wall_hit_ratio = wall_hit_ratio - (int)wall_hit_ratio;
	}
	else
	{
		wall_hit_ratio = ray_result.hit_y / TILE_SIZE;
		wall_hit_ratio = wall_hit_ratio - (int)wall_hit_ratio;
	}
	tex_x = (int)(wall_hit_ratio * data->texture.width);
	if ((ray_result.wall_side == 0 || ray_result.wall_side == 2))
		tex_x = data->texture.width - tex_x - 1;
	return (tex_x);
}
