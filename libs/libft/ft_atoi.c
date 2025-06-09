/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:48:20 by rpires-c          #+#    #+#             */
/*   Updated: 2024/05/08 12:33:13 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sum;
	int	sign;
	int	flag;
	int	i;

	i = 0;
	sum = 0;
	sign = 1;
	flag = 1;
	while (((int)nptr[i] >= 9 && (int)nptr[i] <= 13) || (int)nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] != '\0' && flag == 1)
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			sum = sum * 10 + nptr[i] - '0';
		else
			flag = 0;
		i++;
	}
	return (sign * sum);
}

// int main()
// {
//     char str[10] = "  +-12a3";
//     printf("%d", ft_atoi(str));
//     printf("%d", atoi(str));
//     return(0);
// }