/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:45:20 by ppassos           #+#    #+#             */
/*   Updated: 2025/07/03 14:03:37 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ea_getter(char *line, int i, t_data *data)
{
	if (data->texture.ea)
		return (0);
	else if (line[i] == '.')
	{
		data->texture.ea = ft_strdup(line + i);
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
		data->texture.no = ft_strdup(line + i);
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
		data->texture.so = ft_strdup(line + i);
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
		data->texture.we = ft_strdup(line + i);
		return (1);
	}
	else
		return (-2);
}
