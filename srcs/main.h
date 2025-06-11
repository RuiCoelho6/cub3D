/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:32:47 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/11 15:32:56 by rpires-c         ###   ########.fr       */
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
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
} t_texture;

typedef struct s_map
{
	char	**map;
	char	player_direction;
}	t_map;

typedef struct s_img_data
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_data
{
	void	*mlx_ptr; //mlx handle
	void	*win_ptr; //mlx handle
	t_img_data	*img;
	t_texture	texture; //texture data
	t_colors	colors; //color data
	t_map	map; // map data (can change depending on what will be need)
	int error; // if something is wrong, and checker if init is done good
}	t_data;

// Window control functions
int		handle_no_event(void);
int		murder_window(t_data *mlx);
int		murder_window_key(int keysym, t_data *mlx);
void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color);
void	init(t_data *data);
t_img_data	*init_image(t_data *data);
int	parsing(char **av);
int	check_file(char	*map_file);

#endif