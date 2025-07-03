/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_getter_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 08:42:28 by ppassos           #+#    #+#             */
/*   Updated: 2025/07/03 11:35:26 by ppassos          ###   ########.fr       */
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

int fcolor_i(int *i, int *a, t_data *data)
{
	int b;
	
	b = 0;
	while (data->map.line[*i] && ft_isws(data->map.line[*i]))
		(*i)++;
	if (!ft_isnum(data->map.line[*i]))
		return (1);
	b = *i;
	while (data->map.line[*i] && ft_isnum(data->map.line[*i]))
		(*i)++;
	data->colors.fcolor[*a] = ft_get_float(b, *i, data->map.line);
	(*a)++;
	while (data->map.line[*i] && ft_isws(data->map.line[*i]))
		(*i)++;

	if (*a < 3)
	{
		if (data->map.line[*i] != ',')
			return (1);
		(*i)++;
	}
	return (0);
}

int	ccolor_i(int *i, int *a, t_data *data)
{
	int b;
	
	b = 0;
	while (data->map.line[*i] && ft_isws(data->map.line[*i]))
		(*i)++;
	if (!ft_isnum(data->map.line[*i]))
		return (1);
	b = *i;
	while (data->map.line[*i] && ft_isnum(data->map.line[*i]))
		(*i)++;
	data->colors.ccolor[*a] = ft_get_float(b, *i, data->map.line);
	(*a)++;
	while (data->map.line[*i] && ft_isws(data->map.line[*i]))
		(*i)++;
	if (*a < 3)
	{
		if (data->map.line[*i] != ',')
			return (1);
		(*i)++;
	}
	return (0);
}
