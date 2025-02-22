/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:06:22 by bsunda            #+#    #+#             */
/*   Updated: 2024/02/02 15:05:18 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_puthex(uintptr_t n, int *i)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 0)
	{
		if (n < 16)
		{
			ft_putchar_fd(hex[n], 1);
			(*i)++;
		}
		else if (n >= 16)
		{
			ft_puthex(n / 0x10, i);
			ft_puthex(n % 0x10, i);
		}
	}
}

int	ft_len_ptr(void *p)
{
	char		*hex;
	int			i;
	uintptr_t	ptr;

	ptr = (uintptr_t) p;
	hex = "0123456789ABCDEF";
	i = 2;
	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		ft_puthex(ptr, &i);
	}
	return (i);
}

// #include <stdio.h>
// int main()
// {
// 	int c = 356;
// 	int *ptr_c = &c;
// 	uintptr_t p = (uintptr_t) ptr_c;

// 	char *hex = "0123456789abcdef";
// 	printf("%p", ptr_c);
// 	puts("\n");
// 	ft_len_ptr(ptr_c);

// 	return(0);
// }
