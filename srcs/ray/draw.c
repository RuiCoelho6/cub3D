/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:02:48 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/25 15:37:37 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	get_wall_side(float ray_angle, int hit_horizontal)
{
	if (hit_horizontal)
	{
		if (ray_angle > 0 && ray_angle < PI)
			return (0); // North wall
		else
			return (1); // South wall
	}
	else
	{
		if (ray_angle > PI/2 && ray_angle < 3*PI/2)
			return (2); // West wall
		else
			return (3); // East wall
	}
}

int	get_wall_color(int wall_side)
{
	if (wall_side == 0)
		return (WALL_NORTH);
	else if (wall_side == 1)
		return (WALL_SOUTH);
	else if (wall_side == 2)
		return (WALL_WEST);
	else
		return (WALL_EAST);
}

int	apply_distance_shading(int base_color, float distance)
{
	float	fade_factor;
	int		r;
	int		g;
	int		b;

	fade_factor = 1.0f - (distance / 500.0f);
	if (fade_factor < 0.3f)
		fade_factor = 0.3f;
	r = ((base_color >> 16) & 0xFF) * fade_factor;
	g = ((base_color >> 8) & 0xFF) * fade_factor;
	b = (base_color & 0xFF) * fade_factor;
	return ((r << 16) | (g << 8) | b);
}

void	draw_ray_column(t_data *data, int x, t_ray_result ray_result)
{
	int	wall_height;
	int	wall_start;
	int	wall_end;
	int	wall_color;
	int	y;
	int	pitch_offset;

	if (x < 0 || x >= WIN_WIDTH)
		return ;
	wall_height = calculate_wall_height(ray_result.distance, data->map);
	pitch_offset = data->player->pitch * 100;
	wall_start = (WIN_HEIGHT - wall_height) / 2 + pitch_offset;
	wall_end = wall_start + wall_height;
	wall_color = get_wall_color(ray_result.wall_side);
	wall_color = apply_distance_shading(wall_color, ray_result.distance);
	if (wall_start < 0)
		wall_start = 0;
	if (wall_end > WIN_HEIGHT)
		wall_end = WIN_HEIGHT;
	// Draw ceiling
	y = 0;
	while (y < wall_start)
	{
		my_mlx_pixel_put(data->img, x, y, CEILING_COLOR);
		y++;
	}
	// Draw wall
	y = wall_start;
	while ( y < wall_end)
	{
		my_mlx_pixel_put(data->img, x, y, wall_color);
		y++;
	}
	// Draw floor
	y = wall_end;
	while (y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(data->img, x, y, FLOOR_COLOR);
		y++;
	}
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
	while ( x < WIN_WIDTH)
	{
		ray_result = ray_caster(ra, player, data);
		draw_ray_column(data, x, ray_result);
		ra += angle_step;
		ra = normalize_angle(ra);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->ptr, 0, 0);
}
