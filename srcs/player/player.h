/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:50:50 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/26 13:51:27 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	angle;
	double	dir_x;
	double	dir_y;
	double	pitch;
}	t_player;

#endif
