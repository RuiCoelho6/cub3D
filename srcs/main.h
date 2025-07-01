/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:32:47 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/01 16:09:55 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define PI 3.1415926535
# define DR 0.0174533// one degree in radians
# define MAP_SIZE 32
# define WIN_WIDTH 1024
# define WIN_HEIGHT 512

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
# include "ray/draw/draw.h"
# include "ray/ray.h"
# include "player/player.h"

typedef struct s_colors
{
	float	fcolor[3]; //floor color
	float	ccolor[3]; //Ceiling color
}	t_colors;

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
	char	player_direction;
	int		start_map;
	char	player_dir;
	int		playerx;
	int		playery;
	int		p_f;
	int		max_x;
	int		max_y;
	int		size;
	char	*line;

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
	t_player	*player;
	t_texture	texture;// texture data
	t_colors	colors;// color data
	t_map		map;// map data (can change depending on what will be need)
	int			error;// if something is wrong, and checker if init is done good
}	t_data;

// Window control functions
void			init_window(t_data *data);
int				handle_no_event(void);
int				murder_window(t_data *mlx);
int				murder_window_key(int keysym, t_data *mlx);
void			my_mlx_pixel_put(t_img_data *img, int x, int y, int color);

// Raycasting functions
t_ray_result	ray_caster(float ra, t_player *player, t_data *data);
float			calculate_wall_height(float distance, t_map map);

// Casting horizontal rays
void			init_horizontal_ray(float ra, t_player *player,
					float *rx, float *ry);
int				check_horizontal_wall(float rx, float ry, t_data *data);
float			cast_horizontal_ray(float ra, t_player *player, t_data *data);

// Casting horizontal rays
void			init_vertical_ray(float ra, t_player *player,
					float *rx, float *ry);
int				check_vertical_wall(float rx, float ry, t_data *data);
float			cast_vertical_ray(float ra, t_player *player, t_data *data);

// Drawing functions
void			draw_ray_column(t_data *data, int x, t_ray_result ray_result);
void			render_scene(t_player *player, t_data *data);

// Parsing functions
int				parsing(char **av);
int				check_file(char	*map_file);

//parsing and init
int		parsing_and_init(char *file, t_data *data);
int		check_file(char	*map_file);
char	**open_map(char *filename);
char	*get_next_line(int fd);
int		get_resourchs(char **d_f, t_data *data);
int		texture_color_finder(char **d_f, t_data *data);
int		ft_isws(int c);
int		ea_getter(char *line, int i, t_data *data);
int		no_getter(char *line, int i, t_data *data);
int		so_getter(char *line, int i, t_data *data);
int		we_getter(char *line, int i, t_data *data);
int		save_color(char *line, int i, t_data *data, int info);
int		is_empty_line(char *line);
int		map_valid(t_data *data);
char	**save_map(char **file, int start, int end);
void	free_data(t_data *data);
void	ft_free_dc(char ***a);
int		is_player(char letter);
int		v_p(char **map, int y, int x);
int		not_v_l(char a);
char	**save_map(char **file, int start, int end);
int		check_map(int x, int y, char **map, t_data *data);
int		color_exist(int a, float *color);
int		ccolor_i(int i, int *a, int b, t_data *data);
int		fcolor_i(int i, int *a, int b, t_data *data);
int		increment(int *i, char *line);
float	ft_get_float(int b, int i, char *l);
// Player functions
void			init_player(t_player *player, t_data *data);
int				key_hook(int keycode, t_data *data);
void			move_forward(t_player *player, t_data *data,
					int tile_x, int tile_y);
void			move_backward(t_player *player, t_data *data,
					int tile_x, int tile_y);
void			strafe_left(t_player *player, t_data *data,
					int tile_x, int tile_y);
void			strafe_right(t_player *player, t_data *data,
					int tile_x, int tile_y);

#endif
