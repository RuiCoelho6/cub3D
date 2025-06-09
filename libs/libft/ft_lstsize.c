/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:05:20 by rpires-c          #+#    #+#             */
/*   Updated: 2024/05/10 17:29:35 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

// int main()
// {
// 	t_list *teste1 = ft_lstnew("teste1");
// 	t_list *teste2 = ft_lstnew("teste2");
// 	ft_lstadd_front(&teste1, teste2);
// 	printf("%d", (ft_lstsize(teste1)));
// 	return (0);
// }