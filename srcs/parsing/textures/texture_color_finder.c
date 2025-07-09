/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color_finder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:17:20 by ppassos           #+#    #+#             */
/*   Updated: 2025/07/09 10:15:13 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	ft_isws(int c)
{
	if (c >= 9 && c <= 13)
		return (1);
	if (c == 32)
		return (1);
	return (0);
}

int	ull_t_c(t_data *data)
{
	if (data->texture.ea == NULL)
		return (0);
	if (data->texture.no == NULL)
		return (0);
	if (data->texture.so == NULL)
		return (0);
	if (data->texture.we == NULL)
		return (0);
	if (data->colors.ccolor[0] == -1)
		return (0);
	if (data->colors.ccolor[1] == -1)
		return (0);
	if (data->colors.ccolor[2] == -1)
		return (0);
	if (data->colors.fcolor[0] == -1)
		return (0);
	if (data->colors.fcolor[1] == -1)
		return (0);
	if (data->colors.fcolor[2] == -1)
		return (0);
	return (1);
}

int	save_texture(char *line, int i, t_data *data, int info)
{
	i += 2;
	if (!line[i] || !ft_isws(line[i]))
		return (-2);
	while (line[i] && ft_isws(line[i]))
		i++;
	if (!line[i])
		return (-2);
	if (info == 1)
		return (ea_getter(line, i, data));
	if (info == 2)
		return (no_getter(line, i, data));
	if (info == 3)
		return (so_getter(line, i, data));
	if (info == 4)
		return (we_getter(line, i, data));
	return (1);
}

int	texture(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (!ft_isalpha(line[i]) && line[i])
	{
		if (!ft_isws(line[i]))
			return (-2);
		i++;
	}
	if (!line[i])
		return (1);
	else if (ft_strncmp(line + i, "EA", 2) == 0)
		return (save_texture(line, i, data, 1));
	else if (ft_strncmp(line + i, "NO", 2) == 0)
		return (save_texture(line, i, data, 2));
	else if (ft_strncmp(line + i, "SO", 2) == 0)
		return (save_texture(line, i, data, 3));
	else if (ft_strncmp(line + i, "WE", 2) == 0)
		return (save_texture(line, i, data, 4));
	else if (ft_strncmp(line + i, "F", 1) == 0)
		return (save_color(line, i, data, 1));
	else if (ft_strncmp(line + i, "C", 1) == 0)
		return (save_color(line, i, data, 2));
	else
		return (-2);
}

int	texture_color_finder(char **d_f, t_data *data)
{
	int	j;
	int	error;

	j = 0;
	error = 1;
	while (!(ull_t_c(data)) && d_f[j])
	{
		error = texture(d_f[j], data);
		if (error == 0)
			return (printf("Error:Texture repeat\n"), 0);
		else if (error == -2)
			return (printf("Error:Invalid character on the file\n"), 0);
		else if (error == -3)
			return (printf("Error:Color repeats\n"), 0);
		j++;
	}
	if (!ull_t_c(data))
		return (printf("Error:Missing data\n"), 0);
	data->map.start_map = j;
	return (1);
}
