/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:04:19 by ppassos           #+#    #+#             */
/*   Updated: 2025/07/03 14:09:05 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

void	ft_free_dc(char ***a)
{
	int	i;

	if (!a || !*a)
		return ;
	i = 0;
	while ((*a)[i])
	{
		(*a)[i] = ft_free((*a)[i]);
		(*a)[i] = NULL;
		i++;
	}
	(*a) = ft_free(*a);
	*a = NULL;
}

void	free_data(t_data *data)
{
	int	i;

	if (data->map.map)
	{
		i = 0;
		while (data->map.map[i])
		{
			data->map.map[i] = ft_free(data->map.map[i]);
			i++;
		}
		data->map.map = ft_free(data->map.map);
	}
	if (data->img)
	{
		data->img = ft_free(data->img);
	}
	data->texture.ea = ft_free(data->texture.ea);
	data->texture.no = ft_free(data->texture.no);
	data->texture.so = ft_free(data->texture.so);
	data->texture.we = ft_free(data->texture.we);
}
