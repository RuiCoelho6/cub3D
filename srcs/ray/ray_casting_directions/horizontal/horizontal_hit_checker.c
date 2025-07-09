/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_hit_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:55:06 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/09 17:01:15 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

t_ray_hit	create_ray_hit(float distance, float hit_x, float hit_y)
{
	t_ray_hit	hit;

	hit.distance = distance;
	hit.hit_x = hit_x;
	hit.hit_y = hit_y;
	return (hit);
}

t_ray_params	setup_horizontal_ray(float ray_angle, t_player *player)
{
	t_ray_params	params;

	init_horizontal_ray(ray_angle, player, &params.ray_x, &params.ray_y);
	get_horizontal_step(ray_angle, &params.x_offset, &params.y_offset);
	return (params);
}

int	is_ray_out_of_bounds(float ray_x, float ray_y, t_data *data)
{
	if (ray_x < -100 || ray_x > (data->map.max_x * MAP_SIZE + 100))
		return (1);
	if (ray_y < -100 || ray_y > (data->map.max_y * MAP_SIZE + 100))
		return (1);
	return (0);
}

t_ray_hit	cast_horizontal_ray_loop(t_ray_params *params,
			t_player *player, t_data *data)
{
	int	depth_of_field;

	depth_of_field = 0;
	while (depth_of_field < 32)
	{
		if (check_horizontal_wall(params->ray_x, params->ray_y, data))
		{
			return (create_ray_hit(
					dist(player->pos_x, player->pos_y,
						params->ray_x, params->ray_y),
					params->ray_x, params->ray_y));
		}
		params->ray_x += params->x_offset;
		params->ray_y += params->y_offset;
		depth_of_field++;
		if (is_ray_out_of_bounds(params->ray_x, params->ray_y, data))
			break ;
	}
	return (create_ray_hit(1000000.0f, params->ray_x, params->ray_y));
}

t_ray_hit	cast_horizontal_ray_with_hit(float ray_angle,
			t_player *player, t_data *data)
{
	t_ray_params	params;

	params = setup_horizontal_ray(ray_angle, player);
	if (ray_angle == 0 || ray_angle == PI)
		return (create_ray_hit(1000000.0f, params.ray_x, params.ray_y));
	return (cast_horizontal_ray_loop(&params, player, data));
}
