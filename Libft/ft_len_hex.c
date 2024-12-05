/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:04:20 by bsunda            #+#    #+#             */
/*   Updated: 2024/02/02 15:05:30 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*up_or_lowhex(char type)
{
	char	*upperhex;
	char	*lowerhex;

	upperhex = "0123456789ABCDEF";
	lowerhex = "0123456789abcdef";
	if (type == 'x')
		return (lowerhex);
	else
		return (upperhex);
}

int	ft_len_hex(char type, unsigned int value, int *init)
{
	char	*hex;

	hex = up_or_lowhex(type);
	if (value < 0)
		value = 4294967296 + value;
	if (value < 16)
	{
		ft_putchar_fd(hex[value], 1);
		*init = *init + 1;
	}
	else if (value >= 16)
	{
		ft_len_hex(type, value / 16, init);
		ft_len_hex(type, value % 16, init);
	}
	return (*init);
}
