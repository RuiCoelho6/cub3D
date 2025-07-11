/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:22:26 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/09 17:26:32 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef struct s_ray_params
{
	float	ray_x;
	float	ray_y;
	float	x_offset;
	float	y_offset;
}	t_ray_params;

typedef struct s_ray_hit
{
	float	distance;
	float	hit_x;
	float	hit_y;
}	t_ray_hit;

typedef struct s_ray_result
{
	float	distance;
	int		wall_type;
	int		wall_side;
	float	hit_x;
	float	hit_y;
}	t_ray_result;

void		get_horizontal_step(float ra, float *xo, float *yo);
float		dist(float ax, float ay, float bx, float by);
float		normalize_angle(float angle);
float		fix_fisheye(float distance, float player_angle, float ray_angle);
void		get_vertical_step(float ra, float *xo, float *yo);
t_ray_hit	create_ray_hit(float distance, float hit_x, float hit_y);

#endif