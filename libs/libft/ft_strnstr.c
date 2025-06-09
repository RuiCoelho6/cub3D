/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:49:04 by rpires-c          #+#    #+#             */
/*   Updated: 2024/05/10 17:43:19 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_little;
	char	*big_str;

	i = 0;
	big_str = (char *)big;
	len_little = ft_strlen(little);
	if (len_little == 0 || big == little)
		return (big_str);
	while (big_str[i] != '\0' && i < len)
	{
		j = 0;
		while (big_str[i + j] != '\0' && little[j] != '\0' && big_str[i
				+ j] == little[j] && i + j < len)
			j++;
		if (j == len_little)
			return (big_str + i);
		i++;
	}
	return (0);
}

// int main()
// {
//     char little[] = "";
//     char big[] = "";

//     printf("%s", ft_strnstr(big, little, 10));
//     return(0);
// }