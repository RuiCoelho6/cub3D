/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_resourchs_getter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:12:28 by ppassos           #+#    #+#             */
/*   Updated: 2025/06/12 16:35:41 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
void set_color_neg(t_data *data)
{
	data->colors.Ccolor[0] = -1;
	data->colors.Ccolor[1] = -1;
	data->colors.Ccolor[2] = -1;
	data->colors.Fcolor[0] = -1;
	data->colors.Fcolor[1] = -1;
	data->colors.Fcolor[2] = -1;
}

int t_ok (t_data *data)
{
	int	fd; 
	
	fd = open(data->texture.EA, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	fd = open(data->texture.NO, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	fd = open(data->texture.SO, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	fd = open(data->texture.WE, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int t_and_c_ok(t_data *data)
{
	int i;

	i = 0;
	if(!t_ok(&data))
		return(printf("Error: Invalid texture path\n"), 0);
	while (data->colors.Ccolor[i])
	{
		if (data->colors.Ccolor[i] > 255 || data->colors.Ccolor[i] < 0)
			return(printf("Error: Invalid color\n"), 0);
	}
	return(1);
}

int	get_resourchs(char **d_f, t_data *data)
{
	int i;
	set_color_neg(&data);
	if (!texture_color_finder(d_f, &data))
		return(0);
	if (!t_and_c_ok(&data))
		return(0);
	
	return(1);
}
