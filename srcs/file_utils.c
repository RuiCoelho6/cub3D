/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:00:09 by ppassos           #+#    #+#             */
/*   Updated: 2025/06/12 12:05:00 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*ft_strjoin_free(char *str1, char *str2)
{
	char	*buffer;

	buffer = ft_strjoin(str1, str2);
	free(str1);
	return (buffer);
}

char	**open_map(char *filename)
{
	int		fd;
	char	*line;
	char	*map;
	char	**final_map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (printf("Error: Could not open file\n"), NULL);
	map = get_next_line(fd);
	if (!map)
		return (printf("Error: Empty file\n"), close(fd), NULL);
	line = get_next_line(fd);
	while (line)
	{
		map = ft_strjoin_free(map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	final_map = ft_split(map, '\n');
	free(map);
	if (final_map == NULL)
		return (printf("Error: Map empty\n"), NULL);
	return (final_map);
}