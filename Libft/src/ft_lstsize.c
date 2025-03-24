/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:42:33 by yparthen          #+#    #+#             */
/*   Updated: 2025/03/23 14:58:43 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Returns the length of a list	*/
int	ft_lstsize(t_list *lst)
{
	int	k;

	k = 0;
	while (lst != NULL)
	{
		k++;
		lst = lst->next;
	}
	return (k);
}
