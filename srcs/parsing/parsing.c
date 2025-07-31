/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:38:02 by ppassos           #+#    #+#             */
/*   Updated: 2025/07/31 16:19:41 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	check_file(char	*map_file)
{
	int	i;

	i = ft_strlen(map_file);
	if (i > 4 && ft_strnstr(map_file, "cub", i))
	{
		if (ft_strnstr(map_file, ".cub", i) == (map_file + i - 4))
			return (1);
	}
	return (0);
}

int	parsing_and_init(char *file, t_data *data)
{
	char	**data_file;

	data_file = open_file(file);
	if (data_file == NULL)
		return (0);
	if (!get_resourchs(data_file, data))
		return (ft_free_dc(&data_file), 0);
	return (ft_free_dc(&data_file), 1);
}
