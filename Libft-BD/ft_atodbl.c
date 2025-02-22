/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:01:34 by bsunda            #+#    #+#             */
/*   Updated: 2024/02/22 09:50:32 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atodbl(const char *str)
{
	int			sign;
	double		decimal;
	double		pow;
	long		integer;

	pow = 1;
	sign = 1;
	decimal = 0;
	integer = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		if ('-' == *str++)
			sign = sign * (-1);
	while (*str >= '0' && *str <= '9')
		integer = (integer * 10) + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str)
	{
		pow /= 10;
		decimal = decimal + (*str++ - '0') * pow;
	}
	return ((integer + decimal) * sign);
}
