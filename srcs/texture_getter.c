/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:45:20 by ppassos           #+#    #+#             */
/*   Updated: 2025/06/18 16:46:22 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int ea_getter(char *line, int i, t_data *data)
{
	if (data->texture.EA)
		return (0);
	else if (line[i] == '.')
	{
		data->texture.EA = line + i;
		return(1);
	}
	else
		return(-2);
}

int no_getter(char *line, int i, t_data *data)
{
	if (data->texture.NO)
		return (0);
	else if (line[i] == '.')
	{
		data->texture.NO = line + i;
		return(1);
	}
	else
		return(-2);	
}

int so_getter(char *line, int i, t_data *data)
{
	if (data->texture.SO)
		return (0);
	else if (line[i] == '.')
	{
		data->texture.SO = line + i;
		return(1);
	}
	else
		return(-2);
}

int we_getter(char *line, int i, t_data *data)
{
	if (data->texture.WE)
		return (0);
	else if (line[i] == '.')
	{
		data->texture.WE = line + i;
		return(1);
	}
	else
		return(-2);
}
