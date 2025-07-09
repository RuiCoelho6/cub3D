/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_sampling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:25:13 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/09 10:15:03 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	get_texture_pixel(t_data *data, int wall_side, int tex_x, int tex_y)
{
	char	*texture_data;
	int		pixel_offset;
	int		*pixel_ptr;

	// Clamp texture coordinates
	if (tex_x < 0) tex_x = 0;
	if (tex_x >= data->texture.width) tex_x = data->texture.width - 1;
	if (tex_y < 0) tex_y = 0;
	if (tex_y >= data->texture.height) tex_y = data->texture.height - 1;

	// Select the appropriate texture based on wall side
	if (wall_side == 0)      // North
		texture_data = data->texture.data_no;
	else if (wall_side == 1) // South
		texture_data = data->texture.data_so;
	else if (wall_side == 2) // West
		texture_data = data->texture.data_we;
	else                     // East
		texture_data = data->texture.data_ea;

	// Calculate pixel offset
	pixel_offset = (tex_y * data->texture.line_len) + (tex_x * (data->texture.bpp / 8));
	pixel_ptr = (int *)(texture_data + pixel_offset);
	
	return (*pixel_ptr);
}

int	calculate_texture_x(t_ray_result ray_result, t_data *data)
{
	float	wall_hit_ratio;
	int		tex_x;

	// Calculate which part of the wall was hit
	if (ray_result.wall_side == 0 || ray_result.wall_side == 1) // North/South walls
	{
		wall_hit_ratio = ray_result.hit_x / MAP_SIZE;
		wall_hit_ratio = wall_hit_ratio - (int)wall_hit_ratio; // Get fractional part
	}
	else // West/East walls
	{
		wall_hit_ratio = ray_result.hit_y / MAP_SIZE;
		wall_hit_ratio = wall_hit_ratio - (int)wall_hit_ratio; // Get fractional part
	}

	// Convert to texture coordinate
	tex_x = (int)(wall_hit_ratio * data->texture.width);
	
	// Flip texture for certain walls to avoid mirroring
	if ((ray_result.wall_side == 0 || ray_result.wall_side == 2))
		tex_x = data->texture.width - tex_x - 1;

	return (tex_x);
}