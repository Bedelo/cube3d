/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_unsign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:06:50 by bsunda            #+#    #+#             */
/*   Updated: 2024/02/02 15:05:10 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_unsign(unsigned int n, int *init)
{
	long	nl;

	nl = (long) n;
	if (nl < 0)
		nl = 4294967296 + nl;
	if (nl <= 9)
	{
		*init = *init + 1;
		ft_putchar_fd(nl + '0', 1);
	}
	else if (nl > 9)
	{
		ft_len_unsign(nl / 10, init);
		ft_len_unsign(nl % 10, init);
	}
	return (*init);
}
