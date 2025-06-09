/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:57:37 by rpires-c          #+#    #+#             */
/*   Updated: 2024/05/10 15:41:04 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*result(const char *s, char *sub, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (start > ft_strlen(s))
	{
		len = 0;
		start = 0;
	}
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!(sub))
		return (NULL);
	return (result(s, sub, start, len));
}

// int main(){
//     printf("%s", ft_substr("hola", 0, 18446744073709551615));
//     return(0);
// }