/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:25:09 by rpires-c          #+#    #+#             */
/*   Updated: 2024/04/29 11:37:25 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (!dest && !src)
		return (0);
	if (s < d)
	{
		while (n > 0)
		{
			n--;
			*(d + n) = *(s + n);
		}
	}
	else
	{
		while (n > 0)
		{
			*d++ = *s++;
			n--;
		}
	}
	return (dest);
}

// int main(int argc, char **argv)
// {
// 	char dest[8] = "catch";
// 	printf("%s", (char *)ft_memmove(dest, argv[1], 3));
// 	return (0);
// }