/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:10:21 by ppassos           #+#    #+#             */
/*   Updated: 2025/07/09 10:15:27 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

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

	data->map.p_f = 0;
	x = 0;
	y = 0;
	map = data->map.map;
	while (map[y])
	{
		while (map[y][x])
		{
			if (0 == check_map(x, y, map, data))
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
