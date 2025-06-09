/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:38:01 by rpires-c          #+#    #+#             */
/*   Updated: 2025/06/09 12:48:14 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*memory_eraser(char *array1, char *array2)
{
	free(array1);
	free(array2);
	return (NULL);
}

static void	*update_checkpoint(char *checkpoint, int fd)
{
	int		r;
	char	*tmp;

	tmp = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	while (count_char(checkpoint) <= 0)
	{
		ft_bzero_gnl(tmp, BUFFER_SIZE + 1);
		r = read(fd, tmp, BUFFER_SIZE);
		if (r != 0)
		{
			checkpoint = concatenate_str(checkpoint, tmp);
			if (checkpoint == NULL)
				free(tmp);
		}
		if (ft_strlen_gnl(tmp) == 0 && ft_strlen_gnl(checkpoint) == 0)
			return (memory_eraser(tmp, checkpoint));
		ft_bzero_gnl(tmp, ft_strlen_gnl(tmp) + 1);
		if (r != BUFFER_SIZE)
			break ;
	}
	if (tmp)
		free(tmp);
	return (checkpoint);
}

static char	*get_lines(int fd)
{
	static char	*rest [1024];
	char		*checkpoint [1024];
	int			len_checkpoint;
	int			i;

	i = 0;
	len_checkpoint = 0;
	checkpoint[fd] = rest[fd];
	checkpoint[fd] = update_checkpoint(checkpoint[fd], fd);
	if (checkpoint[fd] == NULL)
		return (NULL);
	if (len_checkpoint == 0)
		len_checkpoint = ft_strlen_gnl(checkpoint[fd]);
	while (checkpoint[fd][i] != '\n' && len_checkpoint > i)
		i++;
	if (i == 0 && checkpoint[fd][i] != '\n')
		return (memory_eraser(rest[fd], checkpoint[fd]));
	rest[fd] = copy(&checkpoint[fd][i + 1], len_checkpoint - i, 0);
	if (rest[fd] == NULL)
	{
		free(checkpoint[fd]);
		return (NULL);
	}
	return (copy(checkpoint[fd], i + 1, 1));
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (get_lines(fd));
}
