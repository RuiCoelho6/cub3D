/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:48:41 by rpires-c          #+#    #+#             */
/*   Updated: 2024/04/16 09:48:41 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	i = 0;
	str1 = (const unsigned char *)b1;
	str2 = (const unsigned char *)b2;
	while (i < len)
	{
		if (str1[i] < str2[i])
		{
			return (-1);
		}
		if (str1[i] > str2[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
    char str1[10] = "may";
    char str2[10] = "macaco";
    printf("%d\n", ft_memcmp(str1, str2, 2));
    printf("%d", memcmp(str1, str2, 2));
    return(0);
}*/