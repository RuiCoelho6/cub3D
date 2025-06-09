/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:23:35 by rpires-c          #+#    #+#             */
/*   Updated: 2024/05/10 15:43:54 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1 && (ft_strchr(set, s1[i]) != NULL))
		i++;
	if (i > j)
		return (ft_calloc(1, sizeof(char)));
	while (j >= 0 && (ft_strchr(set, s1[j]) != NULL))
		j--;
	str = ft_calloc(j - i + 2, sizeof(char));
	if (!(str))
		return (NULL);
	ft_strlcpy(str, &s1[i], j - i + 2);
	return (str);
}

// int main(int argc, char **argv)
// {
// 	printf("%s", ft_strtrim("     ", " "));
// 	return (0);
// }