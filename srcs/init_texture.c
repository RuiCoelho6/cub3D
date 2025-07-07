/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:45:50 by ppassos           #+#    #+#             */
/*   Updated: 2025/07/07 16:10:58 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#include "main.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	load_single_texture(t_data *data, char *path, void **img, char **data_ptr)
{
	*img = mlx_xpm_file_to_image(data->mlx_ptr, path, 
		&data->texture.width, &data->texture.height);
	if (!*img)
		return (0);
	*data_ptr = mlx_get_data_addr(*img, &data->texture.bpp, 
		&data->texture.line_len, &data->texture.endian);
	if (!*data_ptr)
		return (0);
	return (1);
}

int	init_texture(t_data *data)
{
	// Load North texture
	if (!load_single_texture(data, data->texture.no, 
		&data->texture.img_no, &data->texture.data_no))
		return (printf("Error: Failed to load North texture\n"), 0);
	
	// Load South texture
	if (!load_single_texture(data, data->texture.so, 
		&data->texture.img_so, &data->texture.data_so))
		return (printf("Error: Failed to load South texture\n"), 0);
	
	// Load West texture
	if (!load_single_texture(data, data->texture.we, 
		&data->texture.img_we, &data->texture.data_we))
		return (printf("Error: Failed to load West texture\n"), 0);
	
	// Load East texture
	if (!load_single_texture(data, data->texture.ea, 
		&data->texture.img_ea, &data->texture.data_ea))
		return (printf("Error: Failed to load East texture\n"), 0);
	return (1);
}

void	free_textures(t_data *data)
{
	if (data->texture.img_no)
		mlx_destroy_image(data->mlx_ptr, data->texture.img_no);
	if (data->texture.img_so)
		mlx_destroy_image(data->mlx_ptr, data->texture.img_so);
	if (data->texture.img_we)
		mlx_destroy_image(data->mlx_ptr, data->texture.img_we);
	if (data->texture.img_ea)
		mlx_destroy_image(data->mlx_ptr, data->texture.img_ea);
}
