/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:54:16 by rpires-c          #+#    #+#             */
/*   Updated: 2024/04/29 13:44:10 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && dst[i] != '\0')
	{
		i++;
	}
	while ((i + 1) < size && src[j] != '\0')
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	if (i != size)
	{
		dst[i] = '\0';
	}
	return ((i - j) + ft_strlen(src));
}

// int main ()
// {
//     char dest[10] = "catch";
//     printf("%zu\n", ft_strlcat(dest, "trjy", 0));
//     printf("%zu", strlcat(dest, "tjry", 0));
//     return (0);
// }