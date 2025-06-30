/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:22:26 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/26 12:27:04 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef struct s_ray_result
{
	float	distance;
	int		wall_type;
	int		wall_side;
	float	wall_x;
}	t_ray_result;

void	get_horizontal_step(float ra, float *xo, float *yo);
float	dist(float ax, float ay, float bx, float by);
float	normalize_angle(float angle);
float	fix_fisheye(float distance, float player_angle, float ray_angle);
void	get_vertical_step(float ra, float *xo, float *yo);

#endif