/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:56:28 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/11 11:32:01 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# define WIDTH 666
# define HEIGHT 420
# define REF_WIDTH 333
# define REF_HEIGHT 210

typedef struct s_img_data
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*window_ptr;
	char		*name;
	t_img_data	*img;
}	t_mlx_data;

int		handle_no_event(void);
int		murder_window(t_mlx_data *mlx);
int		murder_window_key(int keysym, t_mlx_data *mlx);
void	my_mlx_pixel_put(t_img_data *img_data, int x, int y, int color);

#endif