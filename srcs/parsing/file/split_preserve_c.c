/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_preserve_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:04:45 by ppassos           #+#    #+#             */
/*   Updated: 2025/07/31 16:49:10 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

static int	word_count(const char *str, char c)
{
	int	i;
	int	count;

	if (!str || !*str)
		return (1);
	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

static char	*str_length(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)ft_calloc((end - start + 1), sizeof(char));
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**split_preserve_c(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**res;

	i = 0;
	j = 0;
	index = 0;
	res = (char **)ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!s || !res)
		return (NULL);
	while (1)
	{
		if (s[i] == c || s[i] == '\0')
		{
			res[j++] = str_length(s, index, i);
			index = i + 1;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	res[j] = NULL;
	return (res);
}
