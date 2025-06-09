/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:37:30 by rpires-c          #+#    #+#             */
/*   Updated: 2024/06/26 10:58:12 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_bzero_gnl(void *tmp, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)tmp;
	while (i < n)
		str[i++] = '\0';
}

int	count_char(char *str)
{
	int	a;

	a = 0;
	if (str == NULL)
	{
		return (0);
	}
	while (str[a] != '\0')
	{
		if (str[a] == '\n')
			return (1);
		a++;
	}
	return (0);
}

char	*concatenate_str(char *checkpoint, char *tmp)
{
	int		len;
	int		i;
	char	*ret;
	int		len_checkpoint;

	len_checkpoint = ft_strlen_gnl(checkpoint);
	i = -1;
	len = len_checkpoint + ft_strlen_gnl(tmp) + 1;
	ret = (char *)malloc(len * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_bzero_gnl(ret, len);
	if (checkpoint != NULL)
	{
		while (checkpoint[++i] != '\0')
			ret[i] = checkpoint[i];
		free(checkpoint);
	}
	i = -1;
	while (tmp[++i] != '\0')
		ret[len_checkpoint + i] = tmp[i];
	ret[len_checkpoint + i] = '\0';
	return (ret);
}

char	*copy(char *checkpoint, int len_checkpoint, int frees)
{
	char	*ret;
	int		i;

	i = -1;
	ret = (char *)malloc(len_checkpoint + 1 * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_bzero_gnl(ret, len_checkpoint + 1);
	while (++i < len_checkpoint)
		ret[i] = checkpoint[i];
	ret[i] = '\0';
	if (frees == 1)
		free(checkpoint);
	return (ret);
}
