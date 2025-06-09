/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:51:48 by rpires-c          #+#    #+#             */
/*   Updated: 2024/05/10 17:48:31 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(1 * (sizeof(t_list)));
	if (!(new_node))
		return (NULL);
	new_node -> content = content;
	new_node -> next = NULL;
	return (new_node);
}

// int main()
// {
// 	t_list *test = ft_lstnew("teste");
// 	ft_putstr_fd(teste -> content,1);
// }