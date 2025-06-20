/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:32:47 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/20 14:17:07 by ppassos          ###   ########.fr       */
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
	float	fcolor[3]; //floor color
	float	ccolor[3]; //Ceiling color ->tem de ser float
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
	int		max_x;
	int		max_y;
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
	void		*mlx_ptr; //mlx handle
	void		*win_ptr; //mlx handle
	t_img_data	*img;
	t_texture	texture; //texture data
	t_colors	colors; //color data
	t_map		map; // map data (can change depending on what will be need)
	int			error; // if something is wrong, and checker if init is done good
}	t_data;

// Window control functions
int		handle_no_event(void);
int		murder_window(t_data *mlx);
int		murder_window_key(int keysym, t_data *mlx);
void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color);

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
void	free_data(t_data *data); //general free on data struct
void	ft_free_dc(char ***a); // free char **

#endif