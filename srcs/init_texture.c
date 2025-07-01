/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:45:50 by ppassos           #+#    #+#             */
/*   Updated: 2025/07/01 17:36:03 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*void init_texture(t_data *data)
{
	int i;

	i = 64;
	data->texture.texture[0] = mlx_xpm_file_to_image(data->mlx_ptr, data->texture.ea, &i, &i);
	data->texture.texture[1] = mlx_xpm_file_to_image(data->mlx_ptr, data->texture.no, &i, &i);
	data->texture.texture[2] = mlx_xpm_file_to_image(data->mlx_ptr, data->texture.so, &i, &i);
	data->texture.texture[3] = mlx_xpm_file_to_image(data->mlx_ptr, data->texture.we, &i, &i);
}
void	put_image(int y, int x, void *a, t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, a, x, y);
}

void	fill_map(t_data *data)
{
	int		j;
	int		i;
	char	**map;

	j = -1;
	map = data->map.map;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == '0')
				put_image(j * 32, i * 32, data->textures.texture[0], data);
			if (map[j][i] == '1')
				put_image(j * 32, i * 32, data->textures[1], data);
		}
	}
}*/