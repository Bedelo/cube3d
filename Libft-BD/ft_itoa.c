/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:07:51 by bsunda            #+#    #+#             */
/*   Updated: 2023/11/22 17:59:31 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_count_digit(int n)
{
	int	i;

	i = 1;
	while (n / 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

void	loop_itoa(char *s, int p, int nb)
{
	int	stop;
	int	digit;

	stop = 0;
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
		stop++;
	}
	while (p - 1 >= stop)
	{
		digit = nb % 10;
		s[p - 1] = (digit + '0');
		nb = nb / 10;
		p = p - 1;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*itoa;
	int		i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	size = ft_count_digit(n);
	if (n < 0)
		size++;
	i = size;
	itoa = malloc((size + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	loop_itoa(itoa, i, n);
	itoa[(size)] = '\0';
	return (itoa);
}

// int	main(void)
// {
// 	int	i;
// 	int	j;
// 	int	k;

// 	i = 123;
// 	puts(ft_itoa(i));
// 	j = 0;
// 	puts(ft_itoa(j));
// 	k = -123;
// 	puts(ft_itoa(k));
// 	return (0);
// }
