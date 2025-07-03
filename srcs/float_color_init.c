/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_color_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:30:34 by ppassos           #+#    #+#             */
/*   Updated: 2025/07/03 08:45:48 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	c_f_color(float *colors)
{
	int color;

	color = ((int)colors[0] << 16) | ((int)colors[1] << 8) | ((int)colors[0]);
	return(color);
}

int	ft_isnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}