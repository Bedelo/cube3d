/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:44:46 by bsunda            #+#    #+#             */
/*   Updated: 2023/11/20 16:23:42 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	t_list	*interlist;

	interlist = lst;
	i = 0;
	if (interlist == NULL)
		return (NULL);
	while (interlist->next)
	{
		interlist = interlist->next;
	}
	return (interlist);
}
