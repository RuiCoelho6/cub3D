/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:20:15 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/01 12:25:46 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# define WALL_NORTH 0xFF0000// Red
# define WALL_SOUTH 0x00FF00// Green
# define WALL_EAST 0x0000FF// Blue
# define WALL_WEST 0xFFFF00// Yellow
# define CEILING_COLOR 0x87CEEB// Sky blue
# define FLOOR_COLOR 0x8B4513// Brown

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