/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:26:50 by rpires-c          #+#    #+#             */
/*   Updated: 2024/05/10 17:46:06 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*clone_list;
	t_list	*first_node;

	if (!lst)
		return (NULL);
	clone_list = ft_lstnew(f(lst -> content));
	if (!(clone_list))
		return (NULL);
	first_node = clone_list;
	lst = lst -> next;
	while (lst)
	{
		clone_list -> next = ft_lstnew(f(lst -> content));
		if (clone_list -> next == NULL)
		{
			ft_lstclear(&first_node, del);
			return (NULL);
		}
		clone_list = clone_list -> next;
		lst = lst -> next;
	}
	clone_list -> next = NULL;
	return (first_node);
}
