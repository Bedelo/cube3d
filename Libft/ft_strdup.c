/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:40:27 by bsunda            #+#    #+#             */
/*   Updated: 2023/11/15 13:29:28 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		l;
	char	*cpy;

	l = ft_strlen(s);
	if (!s)
		return (NULL);
	i = 0;
	cpy = (char *)malloc(sizeof(char) * l + 1);
	if (!cpy)
		return (NULL);
	while (i < l)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
