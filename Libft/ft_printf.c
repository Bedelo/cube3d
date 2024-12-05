/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:53:55 by bsunda            #+#    #+#             */
/*   Updated: 2024/02/02 15:04:22 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	arg_is(va_list p, char t, int *size)
{
	if (t == 'd' || t == 'i')
		*size += ft_len_int(va_arg(p, int));
	else if (t == 'c')
		*size += ft_len_char(va_arg(p, int));
	else if (t == 's')
		*size += ft_len_str(va_arg(p, char *));
	else if (t == 'p')
		*size += ft_len_ptr(va_arg(p, void *));
	else if (t == 'u')
		*size = ft_len_unsign(va_arg(p, unsigned int), size);
	else if (t == 'x' || t == 'X')
		*size = ft_len_hex(t, va_arg(p, unsigned int), size);
	else if (t == '%')
		*size += ft_len_percent('%');
	else
	{
		*size += ft_len_char(t);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		i;
	int		size;

	i = 0;
	size = 0;
	va_start(params, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if ((format[i]) == '%' )
		{
			arg_is(params, format[i + 1], &size);
			i += 1;
		}
		else
		{
			write(1, &format[i], 1);
			size++;
		}
		i++;
	}
	va_end(params);
	return (size);
}

// int	main(void)
// {
// 	char n = 'a';
// 	int	res;
// 	int res2;

// 	res = ft_printf("%c%c %X %p %s", n, n, n, &n, "hello");
// 	ft_printf("%d\n", res);

// 	res2 = printf("%c%c %X %p %s", n, n, n, &n , "hello");
// 	printf("%d\n", res2);
// 	return (0);
// }
