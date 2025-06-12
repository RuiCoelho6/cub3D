/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:38:02 by ppassos           #+#    #+#             */
/*   Updated: 2025/06/12 13:18:08 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	// verificar se todas as predefinicoes das texturas e cores estao presentes
	char **data_file;
	int i = 0;

	data = NULL;
	data_file = open_map(file);
	if (data_file == NULL)
		return (0);
	while (data_file[i])
	{
		printf("%d:%s\n", i, data_file[i]);
		i++;
	}
	if (!get_resourchs(data_file, data)) //verificar se tudo esta presente e bem
		return (free(data_file), 0); // provalvelmente vou precisar de dar free a !lista!
	/*if (!map_valid(data->map.map))// ver se o mapa e valido
		return(free(data_file), 0); // criar funcao para dar free na lista tb*/
	return(1);
}
