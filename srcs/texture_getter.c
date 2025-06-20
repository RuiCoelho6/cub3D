/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:45:20 by ppassos           #+#    #+#             */
/*   Updated: 2025/06/20 14:26:45 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ea_getter(char *line, int i, t_data *data)
{
	if (data->texture.ea)
		return (0);
	else if (line[i] == '.')
	{
		data->texture.ea = line + i;
		return (1);
	}
	else
		return (-2);
}

int	no_getter(char *line, int i, t_data *data)
{
	if (data->texture.no)
		return (0);
	else if (line[i] == '.')
	{
		data->texture.no = line + i;
		return (1);
	}
	else
		return (-2);
}

int	so_getter(char *line, int i, t_data *data)
{
	if (data->texture.so)
		return (0);
	else if (line[i] == '.')
	{
		data->texture.so = line + i;
		return (1);
	}
	else
		return (-2);
}

int	we_getter(char *line, int i, t_data *data)
{
	if (data->texture.we)
		return (0);
	else if (line[i] == '.')
	{
		data->texture.we = line + i;
		return (1);
	}
	else
		return (-2);
}
