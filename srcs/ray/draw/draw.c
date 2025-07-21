/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:02:48 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/21 11:50:17 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

t_texture_params	calculate_texture_params(t_data *data,
		t_ray_result ray_result)
{
	t_texture_params	params;
	float				full_wall_height;
	float				theoretical_wall_start;
	float				pixels_cut_off_top;

	params.tex_x = calculate_texture_x(ray_result, data);
	full_wall_height = (float)data->map.size * WIN_HEIGHT / ray_result.distance;
	params.texture_step = (float)data->texture.height / full_wall_height;
	theoretical_wall_start = (WIN_HEIGHT - full_wall_height) / 2.0f;
	if (theoretical_wall_start < 0)
	{
		pixels_cut_off_top = -theoretical_wall_start;
		params.texture_pos = pixels_cut_off_top * params.texture_step;
	}
	else
		params.texture_pos = 0;
	return (params);
}

void	draw_textured_wall(t_data *data, int x,
		t_wall wall, t_ray_result ray_result)
{
	t_texture_params	params;
	int					tex_y;
	int					y;
	int					color;

	params = calculate_texture_params(data, ray_result);
	y = wall.start;
	while (y < wall.end)
	{
		tex_y = (int)params.texture_pos;
		params.texture_pos += params.texture_step;
		color = get_texture_pixel(data, ray_result.wall_side,
				params.tex_x, tex_y);
		color = apply_distance_shading(color, ray_result.distance);
		my_mlx_pixel_put(data->img, x, y, color);
		y++;
	}
}

void	set_colors(t_wall wall, t_data *data, int x, t_ray_result ray_result)
{
	int	y;

	y = 0;
	while (y < wall.start)
	{
		my_mlx_pixel_put(data->img, x, y, c_f_color(data->colors.ccolor));
		y++;
	}
	draw_textured_wall(data, x, wall, ray_result);
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
