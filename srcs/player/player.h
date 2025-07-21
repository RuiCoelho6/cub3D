/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:50:50 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/21 14:09:08 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	angle;
	int		key_up;
	int		key_down;
	int		key_left;
	int		key_right;
}	t_player;


#endif
