/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_getter_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 08:42:28 by ppassos           #+#    #+#             */
/*   Updated: 2025/06/30 16:00:46 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	color_exist(int a, float *color)
{
	while (a < 3)
	{
		if (color[a] != -1)
			return (-3);
		a++;
	}
	return (0);
}

int	increment(int *i, char *line)
{
	while (line[*i] && ft_isws(line[*i]))
		(*i)++;
	if (line[*i])
		(*i)++;
	return (0);
}

int	fcolor_i(int i, int *a, int b, t_data *data)
{
	if (ft_isalnum(data->map.line[i]))
	{
		b = i;
		while (data->map.line[i] && ft_isalnum(data->map.line[i]))
			i++;
		if (!data->map.line || (data->map.line[i] != ',' && (*a) != 2))
			return (1);
		else if (data->map.line && data->map.line[i] == ',' && (*a) < 2)
		{
			data->colors.fcolor[*a] = ft_get_float(b, i, data->map.line);
			(*a)++;
		}
		else if (data->map.line && (*a) == 2 && i != b)
		{
			data->colors.fcolor[*a] = ft_get_float(b, i, data->map.line);
			(*a)++;
		}
	}
	return (0);
}

int	ccolor_i(int i, int *a, int b, t_data *data)
{
	if (ft_isalnum(data->map.line[i]))
	{
		b = i;
		while (data->map.line[i] && ft_isalnum(data->map.line[i]))
			i++;
		if (!data->map.line || (data->map.line[i] != ',' && (*a) != 2))
			return (1);
		else if (data->map.line && data->map.line[i] == ',' && (*a) < 2)
		{
			data->colors.ccolor[*a] = ft_get_float(b, i, data->map.line);
			(*a)++;
		}
		else if (data->map.line && (*a) == 2 && i != b)
		{
			data->colors.ccolor[*a] = ft_get_float(b, i, data->map.line);
			(*a)++;
		}
	}
	return (0);
}
