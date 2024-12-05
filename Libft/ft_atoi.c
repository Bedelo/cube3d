/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:01:34 by bsunda            #+#    #+#             */
/*   Updated: 2023/11/14 09:45:47 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	a;
	int	sign;
	int	res;

	a = 0;
	sign = 1;
	res = 0;
	while (str[a] == ' ' || (str[a] >= '\t' && str[a] <= '\r'))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			sign = sign * (-1);
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		res = (res * 10) + (str[a] - '0');
		a++;
	}
	return (res * sign);
}
