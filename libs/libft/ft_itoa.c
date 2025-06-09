/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:54:19 by rpires-c          #+#    #+#             */
/*   Updated: 2024/05/13 12:34:32 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*result(char *str, int digits, int num, int flag)
{
	if (flag == 1)
	{
		while (digits > 0)
		{
			str[digits] = (num % 10) + '0';
			num /= 10;
			digits--;
		}
		str[0] = '-';
	}
	else
	{
		while (digits >= 0)
		{
			str[digits] = (num % 10) + '0';
			num /= 10;
			digits--;
		}
	}
	return (str);
}

static void	check_negative(int *flag, int *num, int *digits, int n)
{
	*flag = 0;
	if (n < 0)
	{
		*flag = 1;
		*num *= -1;
		*digits += 1;
	}
}

static int	divide(int n, int digits)
{
	while ((n / 10) != 0)
	{
		n /= 10;
		digits ++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		flag;
	int		digits;
	int		num;

	num = n;
	digits = 1;
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		if (!(str))
			return (NULL);
		return (str);
	}
	check_negative(&flag, &num, &digits, n);
	digits = divide(n, digits);
	str = malloc((digits + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	str[digits--] = '\0';
	result(str, digits, num, flag);
	return (str);
}

// int main()
// {
// 	printf("%s\n", ft_itoa(-5042));
// 	printf("%s", ft_itoa(5042));
//     return(0);
// }
