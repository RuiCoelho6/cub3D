/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:32:47 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/11 10:50:30 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <aio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/keysym.h>
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"
# include "window.h"

typedef struct s_colors
{
	int	Fcolor[3]; //floor color
	int	Ccolor[3]; //Ceiling color
} t_colors;

typedef struct s_texture
{
	char 	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
} t_texture;

typedef struct s_map
{
	char	**map;
	char	**map_cheked;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr; //mlx handle
	void	*win_ptr; //mlx handle
	t_texture	texture; //texture data
	t_colors	colors; //color data
	t_map	map; // map data (can change depending on what will be need)
	int error; // if something is wrong, and checcker if init is done good
}	t_data;

int	parsing(char **av);
int	check_file(char	*map_file);

#endif