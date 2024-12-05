/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:48:02 by bsunda            #+#    #+#             */
/*   Updated: 2023/11/22 11:12:05 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	head = ft_lstnew((*f)(lst->content));
	if (!head)
		return (NULL);
	newlst = head;
	lst = lst->next;
	while (lst)
	{
		newlst->next = ft_lstnew((*f)(lst->content));
		if (!newlst->next)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		lst = lst->next;
		newlst = newlst->next;
	}
	newlst->next = NULL;
	return (head);
}
