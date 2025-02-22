/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:08:30 by bsunda            #+#    #+#             */
/*   Updated: 2024/02/02 15:05:27 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_int(int value)
{
	int	i;
	int	sign;

	sign = 0;
	i = 1;
	if (value < 0)
		sign++;
	ft_putnbr_fd(value, 1);
	while (value / 10)
	{
		i++;
		value /= 10;
	}
	return (i + sign);
}
