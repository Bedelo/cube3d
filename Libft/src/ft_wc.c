/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 14:55:52 by bsunda            #+#    #+#             */
/*   Updated: 2025/03/23 14:55:57 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wc(char *s)
{
	int	state;
	int	out;
	int	in;
	int	wc;

	out = 0;
	wc = 0;
	in = 1;
	state = out;
	while (*s)
	{
		if (*s == ' ' || *s == '\t' || *s == '\n')
			state = out;
		else if (state == out)
		{
			state = in;
			wc++;
		}
		s++;
	}
	return (wc);
}
