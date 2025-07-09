/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:45:20 by ppassos           #+#    #+#             */
/*   Updated: 2025/07/09 10:59:07 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	ea_getter(char *line, int i, t_data *data)
{
	int t;
	
	t = i;
	if (data->texture.ea)
		return (0);
	else if (line[i] == '.')
	{
		while(line[t] && !ft_isws(line[t]))
			t++;
		data->texture.ea = ft_strndup(line + i, t - i);
		while(line[t])
		{
			if (!ft_isws(line[t]))
				return (-2);
			t++;
		}
		return (1);
	}
	else
		return (-2);
}

int	no_getter(char *line, int i, t_data *data)
{
	int t;
	
	t = i;
	if (data->texture.no)
		return (0);
	else if (line[i] == '.')
	{
		while(line[t] && !ft_isws(line[t]))
			t++;
		data->texture.no = ft_strndup(line + i, t - i);
		while(line[t])
		{
			if (!ft_isws(line[t]))
				return(-2);
			t++;
		}
		return (1);
	}
	else
		return (-2);
}

int	so_getter(char *line, int i, t_data *data)
{
	int t;
	
	t = i;
	if (data->texture.so)
		return (0);
	else if (line[i] == '.')
	{
		while(line[t] && !ft_isws(line[t]))
			t++;
		data->texture.so = ft_strndup(line + i, t - i);
		while(line[t])
		{
			if (!ft_isws(line[t]))
				return(-2);
			t++;
		}
		return (1);
	}
	else
		return (-2);
}

int	we_getter(char *line, int i, t_data *data)
{
	int t;
	
	t = i;
	if (data->texture.we)
		return (0);
	else if (line[i] == '.')
	{
		while(line[t] && !ft_isws(line[t]))
			t++;
		data->texture.we = ft_strndup(line + i, t - i);
		while(line[t])
		{
			if (!ft_isws(line[t]))
				return(-2);
			t++;
		}
		return (1);
	}
	else
		return (-2);
}
