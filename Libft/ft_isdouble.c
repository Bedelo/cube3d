/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:59:25 by bsunda            #+#    #+#             */
/*   Updated: 2024/02/23 10:29:46 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdouble(char *s)
{
	if (*s == '-')
		s++;
	while (*s && *s != '.')
	{
		if (ft_isdigit(*s))
			s++;
		else
			return (0);
	}
	if (*s == '.')
		s++;
	while (*s)
	{
		if (ft_isdigit(*s))
			s++;
		else
			return (0);
	}
	return (1);
}
