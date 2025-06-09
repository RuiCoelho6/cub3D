/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:42:42 by rpires-c          #+#    #+#             */
/*   Updated: 2024/05/07 15:46:39 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		if (n < 10)
		{
			ft_putchar_fd((n + '0'), fd);
		}
		else if (n >= 10)
		{
			ft_putnbr_fd((n / 10), fd);
			ft_putchar_fd((n % 10 + '0'), fd);
		}
	}
}

// int main()
// {
// 	ft_putnbr_fd(-2147483648, 1);
// 	return (0);
// }