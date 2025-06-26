/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:02:48 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/26 14:17:29 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	set_colors(t_wall wall, t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < wall.start)
	{
		my_mlx_pixel_put(data->img, x, y, CEILING_COLOR);
		y++;
	}
	y = wall.start;
	while (y < wall.end)
	{
		my_mlx_pixel_put(data->img, x, y, wall.color);
		y++;
	}
	y = wall.end;
	while (y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(data->img, x, y, FLOOR_COLOR);
		y++;
	}
}

void	draw_ray_column(t_data *data, int x, t_ray_result ray_result)
{
	t_wall	wall;
	int		pitch_offset;

	if (x < 0 || x >= WIN_WIDTH)
		return ;
	wall.height = calculate_wall_height(ray_result.distance, data->map);
	pitch_offset = data->player->pitch * 100;
	wall.start = (WIN_HEIGHT - wall.height) / 2 + pitch_offset;
	wall.end = wall.start + wall.height;
	wall.color = get_wall_color(ray_result.wall_side);
	wall.color = apply_distance_shading(wall.color, ray_result.distance);
	if (wall.start < 0)
		wall.start = 0;
	if (wall.end > WIN_HEIGHT)
		wall.end = WIN_HEIGHT;
	set_colors(wall, data, x);
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
