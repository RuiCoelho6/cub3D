/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:38:27 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/09 12:48:00 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# include "../../srcs/main.h"

char	*get_next_line(int fd);
int		ft_strlen_gnl(char *str);
char	*concatenate_str(char *checkpoint, char *tmp);
void	ft_bzero_gnl(void *s, size_t n);
int		count_char(char *str);
char	*copy(char *str, int a, int frees);

#endif