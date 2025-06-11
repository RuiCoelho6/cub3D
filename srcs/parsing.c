/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:38:02 by ppassos           #+#    #+#             */
/*   Updated: 2025/06/11 10:50:13 by ppassos          ###   ########.fr       */
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

int	parsing(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
	return(1);
}