/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color_finder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:17:20 by ppassos           #+#    #+#             */
/*   Updated: 2025/06/12 17:20:04 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
int	ft_isws(int c)
{
	if (c >= 9 && c <= 13)
		return(1);
	if (c == 32)
		return(1);
	return(0);
}

int ull_t_c(t_data *data)
{
	if (data->texture.EA == NULL)
		return (0);
	if (data->texture.NO == NULL)
		return (0);
	if (data->texture.SO == NULL)
		return (0);
	if (data->texture.WE == NULL)
		return (0);
	if (data->colors.Ccolor[0] = -1)
		return (0);
	if (data->colors.Ccolor[1] = -1)
		return (0);
	if (data->colors.Ccolor[2] = -1)
		return (0);
	if (data->colors.Fcolor[0] = -1)
		return (0);
	if (data->colors.Fcolor[1] = -1)
		return (0);
	if (data->colors.Fcolor[2] = -1)
		return (0);
	return (1);
}
int save_texture(char *line, t_data *data, int info)
{
	
}
int texture(char *line, t_data *data)
{
	int i;
	
	i == 0;
	while (!ft_isalpha(line[i]) && line[i])
	{
		if (!ft_isws(line[i]))
			return(-2);
		i++;
	}
	if (!line[i])
		return(1);
	else
	{
		if (ft_strncmp(line + i, "EA", 3))
			return (save_texture(line + i, &data, 1));
		else if (ft_strncmp(line + i, "NO", 3))
			return (save_texture(line + i, &data, 2));
		else if (ft_strncmp(line + i, "SO", 3))
			return(save_texture(line + i, &data, 3));
		else if (ft_strncmp(line + i, "WE ", 3))
			return (save_texture(line + i, &data, 4));
		else
			return(-2);
	}
} 

int	texture_color_finder(char **d_f, t_data *data)
{
	int j;
	int error;

	j = 0;
	error = 1;
	while (!(full_t_c(&data)) || !d_f[j])
	{
		error = texture(d_f[j], &data);
		if (error = 0)
			return (printf("Error:Texture repeat\n"), 0);
		else if (error = -2)
			return (printf("Error:Invalid character on the file\n"));
		error = color(d_f[j], &data);
		if (error = -1)
			return (printf("Error:Color repeats\n"), 0);
		else if (error = -2)
			return (printf("Error:Invalid character on the file\n"));
		j++;
	}
	if (!full_t_c(&data))
		return(printf("Eror:Missing data"), 0);
	return(1);
}
