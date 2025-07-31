/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:00:09 by ppassos           #+#    #+#             */
/*   Updated: 2025/07/31 16:16:42 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

char	*ft_strjoin_free(char *str1, char *str2)
{
	char	*buffer;

	buffer = ft_strjoin(str1, str2);
	free(str1);
	return (buffer);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (!ft_isws(line[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**open_file(char *filename)
{
	int		fd;
	char	*line;
	char	*file;
	char	**final_file;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (printf("Error: Could not open file\n"), NULL);
	file = get_next_line(fd);
	if (!file)
		return (printf("Error: Empty file\n"), close(fd), NULL);
	line = get_next_line(fd);
	while (line)
	{
		file = ft_strjoin_free(file, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	final_file = split_preserve_c(file, '\n');
	free(file);
	if (final_file == NULL)
		return (printf("Error: Map empty\n"), NULL);
	return (final_file);
}
