/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:10:21 by ppassos           #+#    #+#             */
/*   Updated: 2025/06/20 14:22:07 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**save_map(char **file, int start, int end)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (end - start + 1));
	if (map == NULL)
		return (NULL);
	while (start != end)
	{
		map[i] = ft_strdup(file[start]);
		if (map[i] == NULL)
			return (NULL);
		i++;
		start++;
	}
	map[i] = NULL;
	return (map);
}

int	not_v_l(char a)
{
	if (a == 'N' || a == 'S')
		return (0);
	else if (a == 'E' || a == 'W')
		return (0);
	else if (a == '1' || a == '0')
		return (0);
	else
		return (1);
}

int	v_p(char **map, int y, int x)
{
	if ((y - 1) < 0)
		return (0);
	if (not_v_l(map[y - 1][x]))
		return (0);
	if ((x - 1) < 0)
		return (0);
	if (not_v_l(map[y][x - 1]))
		return (0);
	if (map[y + 1] == NULL)
		return (0);
	if (not_v_l(map[y + 1][x]))
		return (0);
	if (map[y][x + 1] == '\0')
		return (0);
	if (not_v_l(map[y][x + 1]))
		return (0);
	return (1);
}

int	is_player(char letter)
{
	if (letter == 'N' || letter == 'S')
		return (1);
	else if (letter == 'E' || letter == 'W')
		return (1);
	else
		return (0);
}

int	map_valid(t_data *data)
{
	char	**map;
	int		x;
	int		y;
	int		player_found;

	player_found = 0;
	x = 0;
	y = 0;
	map = data->map.map;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == '0')
			{
				if (!v_p(map, y, x))
					return (0);
			}
			else if (is_player(map[y][x]))
			{
				if (player_found)
					return (0);
				else
				{
					player_found = 1;
					data->map.playerx = x;
					data->map.playery = y;
					data->map.player_dir = map[y][x];
					if (!v_p(map, y, x))
						return (0);
				}
			}
			else if (!ft_isws(map[y][x]) && map[y][x] != '1')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
