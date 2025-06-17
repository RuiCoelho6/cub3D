/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:32:47 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/17 15:25:04 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define PI 3.1415926535
# define DR 0.0174533// one degree in radians

# include <aio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>
# include <X11/keysym.h>
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"
# include "../libs/misc_headers/window.h"

typedef struct s_colors
{
	int	fcolor[3]; //floor color
	int	ccolor[3]; //Ceiling color
}	t_colors;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	angle;
	double	dir_x;
	double	dir_y;
}	t_player;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_texture;

typedef struct s_map
{
	char	**map;
	char	**map_checked;
	int		height;
	int		width;
	int		size;
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
	void		*mlx_ptr;// mlx handle
	void		*win_ptr;// mlx handle
	t_img_data	*img;
	t_texture	texture;// texture data
	t_colors	colors;// color data
	t_map		map;// map data (can change depending on what will be need)
	int			error;// if something is wrong, and checker if init is done good
}	t_data;

// Window control functions
int		handle_no_event(void);
int		murder_window(t_data *mlx);
int		murder_window_key(int keysym, t_data *mlx);
void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color);

// Raycasting functions
void	ray_caster(t_player *player, t_data *data, t_map map);
float	dist(float ax, float ay, float bx, float by);

// Casting horizontal rays
void	init_horizontal_ray(float ra, t_player *player, float *rx, float *ry);
void	get_horizontal_step(float ra, float *xo, float *yo);
int		check_horizontal_wall(float rx, float ry, t_data *data);
float	cast_horizontal_ray(float ra, t_player *player, t_data *data);

// Casting horizontal rays
void	init_vertical_ray(float ra, t_player *player, float *rx, float *ry);
void	get_vertical_step(float ra, float *xo, float *yo);
int		check_vertical_wall(float rx, float ry, t_data *data);
float	cast_vertical_ray(float ra, t_player *player, t_data *data);

// Parsing functions
int		parsing(char **av);
int		check_file(char	*map_file);

#endif
