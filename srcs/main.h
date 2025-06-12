/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:32:47 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/12 17:24:13 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define PI 3.1415926535
# define PI2 PI/2
# define PI3 3*PI/2

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
# include "../libs/misc_headers/window.h"

typedef struct s_colors
{
	int	Fcolor[3]; //floor color
	int	Ccolor[3]; //Ceiling color
} t_colors;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	angle;
	double	dir_x;
	double	dir_y;
} t_player;


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
	char	**map_checked;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
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

int	parsing(char **av);
int	check_file(char	*map_file);

#endif