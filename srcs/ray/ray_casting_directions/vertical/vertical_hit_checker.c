/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_hit_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:24:20 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/09 17:31:50 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../main.h"

t_ray_params	setup_vertical_ray(float ray_angle, t_player *player)
{
	t_ray_params	params;

	init_vertical_ray(ray_angle, player, &params.ray_x, &params.ray_y);
	get_vertical_step(ray_angle, &params.x_offset, &params.y_offset);
	return (params);
}

t_ray_hit	cast_vertical_ray_loop(t_ray_params *params,
		t_player *player, t_data *data)
{
	int	depth_of_field;

	depth_of_field = 0;
	while (depth_of_field < 32)
	{
		if (check_vertical_wall(params->ray_x, params->ray_y, data))
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

t_ray_hit	cast_vertical_ray_with_hit(float ray_angle,
		t_player *player, t_data *data)
{
	t_ray_params	params;

	params = setup_vertical_ray(ray_angle, player);
	if (ray_angle == PI / 2 || ray_angle == (3 * PI) / 2)
		return (create_ray_hit(1000000.0f, params.ray_x, params.ray_y));
	return (cast_vertical_ray_loop(&params, player, data));
}
