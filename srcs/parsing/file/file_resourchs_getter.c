/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_resourchs_getter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:12:28 by ppassos           #+#    #+#             */
/*   Updated: 2025/07/24 14:22:45 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	set_color_neg(t_data *data)
{
	data->colors.ccolor[0] = -1;
	data->colors.ccolor[1] = -1;
	data->colors.ccolor[2] = -1;
	data->colors.fcolor[0] = -1;
	data->colors.fcolor[1] = -1;
	data->colors.fcolor[2] = -1;
}

int	t_ok(t_data *data)
{
	int	fd;

	fd = open(data->texture.so, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	fd = open(data->texture.no, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	fd = open(data->texture.ea, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	fd = open(data->texture.we, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	t_and_c_ok(t_data *data)
{
	int	i;

	i = -1;
	if (!t_ok(data))
		return (printf("Error: Invalid texture path\n"), 0);
	while (data->colors.ccolor[i++])
	{
		if (data->colors.ccolor[i] > 255 || data->colors.ccolor[i] < 0)
			return (printf("Error: Invalid color\n"), 0);
	}
	return (1);
}

int	map_finder(char **d_f, t_data *data)
{
	int	i;

	i = data->map.start_map;
	while (d_f[i] && !is_empty_line(d_f[i]))
		i++;
	if (i == data->map.start_map)
		return (0);
	data->map.map = save_map(d_f, data->map.start_map, i);
	data->map.max_y = i;
	data->map.size = TILE_SIZE;
	if (!data->map.map)
		return (0);
	while (d_f[i])
	{
		if (d_f[i] && !is_empty_line(d_f[i]))
			return (0);
		i++;
	}
	return (1);
}

int	get_resourchs(char **d_f, t_data *data)
{
	set_color_neg(data);
	if (!texture_color_finder(d_f, data))
		return (0);
	if (!t_and_c_ok(data))
		return (0);
	if (!map_finder(d_f, data))
		return (printf("ERROR:Invalid map\n"), 0);
	if (!map_valid(data))
		return (printf("ERROR:Invalid map\n"), 0);
	return (1);
}
