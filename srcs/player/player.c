/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:04:53 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/12 16:10:37 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	init_player(t_player *player)
{
	player->pos_x = 100;
	player->pos_y = 100;
	player->angle = 0;
	player->dir_x = 0;
	player->dir_y = 60;
}