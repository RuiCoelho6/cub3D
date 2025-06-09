/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:44:08 by rpires-c          #+#    #+#             */
/*   Updated: 2024/09/17 16:34:30 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c)
{
	int	i;
	int	flag;
	int	n_words;

	i = 0;
	flag = 0;
	n_words = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && flag == 0)
		{
			flag = 1;
			n_words++;
		}
		else if (str[i] == c)
			flag = 0;
		i++;
	}
	return (n_words);
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

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**res;

	i = 0;
	j = 0;
	index = -1;
	res = (char **)ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!s || !res)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			res[j++] = str_length(s, index, i);
			index = -1;
		}
		i++;
	}
	res[j] = 0;
	return (res);
}

/* int	main(void)
{
	char	**res;
	int		i;

	i = 0;
	res = ft_split("lorem ipsum \"dolor sit\" amet", ' ');
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
	return (0);
} */
