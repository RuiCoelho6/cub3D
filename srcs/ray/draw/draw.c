/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:02:48 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/07 15:23:22 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	draw_textured_wall(t_data *data, int x, t_wall wall, t_ray_result ray_result)
{
	int		y;
	int		tex_x;
	int		tex_y;
	float	texture_step;
	float	texture_pos;
	int		color;

	// Calculate texture X coordinate
	tex_x = calculate_texture_x(ray_result, data);
	
	// Calculate texture step and starting position
	texture_step = (float)data->texture.height / wall.height;
	texture_pos = (wall.start - (WIN_HEIGHT / 2) + wall.height / 2) * texture_step;
	
	// Draw the wall column
	y = wall.start;
	while (y < wall.end)
	{
		tex_y = (int)texture_pos;
		texture_pos += texture_step;
		
		// Get pixel color from texture
		color = get_texture_pixel(data, ray_result.wall_side, tex_x, tex_y);
		
		// Apply distance shading
		color = apply_distance_shading(color, ray_result.distance);
		
		// Put pixel
		my_mlx_pixel_put(data->img, x, y, color);
		y++;
	}
}

void	set_colors(t_wall wall, t_data *data, int x, t_ray_result ray_result)
{
	int	y;

	// Draw ceiling
	y = 0;
	while (y < wall.start)
	{
		my_mlx_pixel_put(data->img, x, y, c_f_color(data->colors.ccolor));
		y++;
	}
	
	// Draw textured wall
	draw_textured_wall(data, x, wall, ray_result);
	
	// Draw floor
	y = wall.end;
	while (y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(data->img, x, y, c_f_color(data->colors.fcolor));
		y++;
	}
}

void	draw_ray_column(t_data *data, int x, t_ray_result ray_result)
{
	t_wall	wall;

	if (x < 0 || x >= WIN_WIDTH)
		return ;
	wall.height = calculate_wall_height(ray_result.distance, data->map);
	wall.start = (WIN_HEIGHT - wall.height) / 2;
	wall.end = wall.start + wall.height;
	
	if (wall.start < 0)
		wall.start = 0;
	if (wall.end > WIN_HEIGHT)
		wall.end = WIN_HEIGHT;
	
	set_colors(wall, data, x, ray_result);
}

void	render_scene(t_player *player, t_data *data)
{
	float			ra;
	t_ray_result	ray_result;
	int				x;
	float			fov;
	float			angle_step;

	fov = DR * 60;
	angle_step = fov / WIN_WIDTH;
	ra = player->angle - (fov / 2);
	ra = normalize_angle(ra);
	x = 0;
	while (x < WIN_WIDTH)
	{
		ray_result = ray_caster(ra, player, data);
		draw_ray_column(data, x, ray_result);
		ra += angle_step;
		ra = normalize_angle(ra);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->ptr, 0, 0);
}
