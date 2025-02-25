/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:43:54 by yparthen          #+#    #+#             */
/*   Updated: 2025/02/25 14:14:01 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*freetab(void **s, int size_s)
{
	int	k;

	if (s)
	{
		k = 0;
		if (size_s < 0)
		{
			while (s[k])
			{
				ft_free(s[k]);
				k++;
			}
		}
		else
		{
			while (k < size_s)
			{
				ft_free(s[k]);
				k++;
			}
		}
		ft_free(s);
	}
	return (NULL);
}

void	ft_free(void *data)
{
	if (data)
		free(data);
	data = NULL;
}
