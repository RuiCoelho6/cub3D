/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stf2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:45:43 by ppassos           #+#    #+#             */
/*   Updated: 2025/07/09 10:15:24 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	check_map(int x, int y, char **map, t_data *data)
{
	if (map[y][x] == '0')
	{
		if (!v_p(map, y, x))
			return (0);
	}
	else if (is_player(map[y][x]))
	{
		if (data->map.p_f)
			return (0);
		else
		{
			data->map.p_f = 1;
			data->map.playerx = x;
			data->map.playery = y;
			data->map.player_dir = map[y][x];
			if (!v_p(map, y, x))
				return (0);
		}
	}
	else if (!ft_isws(map[y][x]) && map[y][x] != '1')
		return (0);
	return (1);
}
