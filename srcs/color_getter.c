/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_getter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:36:34 by ppassos           #+#    #+#             */
/*   Updated: 2025/07/03 14:55:46 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

float	ft_atof(char *number)
{
	float	a;

	a = 0;
	if (!number)
		return (-1);
	a = ft_atoi(number);
	return (a);
}

float	ft_get_float(int b, int i, char *l)
{
	char		*number;
	float		a;

	i--;
	number = ft_substr(l, b, i - b + 1);
	a = ft_atof(number);
	if (number)
		free (number);
	return (a);
}

int	ccolor_getter(char *line, int i, t_data *data)
{
	int a;

	a = 0;
	if (color_exist(a, data->colors.ccolor) == -3)
		return (-3);
	data->map.line = line;
	while (line[i])
	{
		while (line[i] && ft_isws(line[i]))
			i++;
		if (!line[i])
			break;
		if (!ft_isnum(line[i]))
			return (-2);
		if (ccolor_i(&i, &a, data))
			return (1);
	}
	if (a != 3)
		return (-2);
	return (1);
}

int fcolor_getter(char *line, int i, t_data *data)
{
	int a;

	a = 0;
	if (color_exist(a, data->colors.fcolor) == -3)
		return (-3);
	data->map.line = line;
	while (line[i])
	{
		while (line[i] && ft_isws(line[i]))
			i++;
		if (!line[i])
			break;
		if (!ft_isnum(line[i]))
			return (-2);
		if (fcolor_i(&i, &a, data))
			return (1);
	}
	if (a != 3)
		return (-2);
	return (1);
}

int	save_color(char *line, int i, t_data *data, int info)
{
	i += 1;
	if (!line[i] || !ft_isws(line[i]))
		return (-2);
	while (line[i] && ft_isws(line[i]))
		i++;
	if (!line[i])
		return (-2);
	if (info == 1)
		return (fcolor_getter(line, i, data));
	if (info == 2)
		return (ccolor_getter(line, i, data));
	return (-2);
}
