/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_getter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:36:34 by ppassos           #+#    #+#             */
/*   Updated: 2025/06/20 14:03:32 by ppassos          ###   ########.fr       */
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

	number = ft_substr(l, b, i);
	a = ft_atof(number);
	if (number)
		free (number);
	return (a);
}

int	ccolor_getter(char *line, int i, t_data *data)
{
	int	a;
	int	b;

	b = 0;
	a = 0;
	while (a < 3)
	{
		if (data->colors.ccolor[a] != -1)
			return (-3);
		a++;
	}
	a = 0;
	while (line[i])
	{
		if (ft_isalnum(line[i]))
		{
			b = i;
			while (line[i] && ft_isalnum(line[i]))
				i++;
			if (!line || (line[i] != ',' && a != 2))
				break ;
			else if (line && line[i] == ',' && a < 2)
			{
				data->colors.ccolor[a] = ft_get_float(b, i, line);
				a++;
			}
			else if (line && a == 2 && i != b)
			{
				data->colors.ccolor[a] = ft_get_float(b, i, line);
				a++;
			}
		}
		while (line[i] && ft_isws(line[i]))
			i++;
		b = 0;
		if (line[i])
			i++;
	}
	if (a != 3)
		return (-2);
	else
		return (1);
}

int	fcolor_getter(char *line, int i, t_data *data)
{
	int	a;
	int	b;

	b = 0;
	a = 0;
	while (a < 3)
	{
		if (data->colors.fcolor[a] != -1)
			return (-3);
		a++;
	}
	a = 0;
	while (line[i])
	{
		if (ft_isalnum(line[i]))
		{
			b = i;
			while (line[i] && ft_isalnum(line[i]))
				i++;
			if (!line || (line[i] != ',' && a != 2))
				break ;
			else if (line && line[i] == ',' && a < 2)
			{
				data->colors.fcolor[a] = ft_get_float(b, i, line);
				a++;
			}
			else if (line && a == 2 && i != b)
			{
				data->colors.fcolor[a] = ft_get_float(b, i, line);
				a++;
			}
		}
		while (line[i] && ft_isws(line[i]))
			i++;
		b = 0;
		if (line[i])
			i++;
	}
	if (a != 3)
		return (-2);
	else
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
