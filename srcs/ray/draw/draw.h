/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:20:15 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/26 12:24:11 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

typedef struct s_wall
{
	int	height;
	int	start;
	int	end;
	int	color;
}	t_wall;

int	apply_distance_shading(int base_color, float distance);
int	get_wall_side(float ray_angle, int hit_horizontal);
int	get_wall_color(int wall_side);

#endif