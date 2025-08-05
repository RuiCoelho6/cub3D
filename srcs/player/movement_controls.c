/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:39:49 by rpires-c          #+#    #+#             */
/*   Updated: 2025/08/05 17:24:47 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	move_forward(t_player *player, t_data *data)
{
	player->pos_x += cos(-(player->angle - PI / 2)) * 2;
	player->pos_y += sin(-(player->angle - PI / 2)) * 2;
	if (!can_move(player->pos_x, player->pos_y, data))
	{
		player->pos_x -= cos(-(player->angle - PI / 2)) * 2;
		player->pos_y -= sin(-(player->angle - PI / 2)) * 2;
	}
}

void	move_backward(t_player *player, t_data *data)
{
	player->pos_x -= cos(-(player->angle - PI / 2)) * 2;
	player->pos_y -= sin(-(player->angle - PI / 2)) * 2;
	if (!can_move(player->pos_x, player->pos_y, data))
	{
		player->pos_x += cos(-(player->angle - PI / 2)) * 2;
		player->pos_y += sin(-(player->angle - PI / 2)) * 2;
	}
}

void	strafe_left(t_player *player, t_data *data)
{
	player->pos_x += cos(-(player->angle - PI / 2) + PI / 2) * 2;
	player->pos_y += sin(-(player->angle - PI / 2) + PI / 2) * 2;
	if (!can_move(player->pos_x, player->pos_y, data))
	{
		player->pos_x -= cos(-(player->angle - PI / 2) + PI / 2) * 2;
		player->pos_y -= sin(-(player->angle - PI / 2) + PI / 2) * 2;
	}
}

void	strafe_right(t_player *player, t_data *data)
{
	player->pos_x += cos(-(player->angle - PI / 2) - PI / 2) * 2;
	player->pos_y += sin(-(player->angle - PI / 2) - PI / 2) * 2;
	if (!can_move(player->pos_x, player->pos_y, data))
	{
		player->pos_x -= cos(-(player->angle - PI / 2) - PI / 2) * 2;
		player->pos_y -= sin(-(player->angle - PI / 2) - PI / 2) * 2;
	}
}
