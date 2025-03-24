/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:23:19 by yparthen          #+#    #+#             */
/*   Updated: 2025/03/23 14:54:45 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_err(int n, char *s, ...)
{
	va_list	args;
	int		i;
	char	*str;

	i = 0;
	if (n < 1 || !s)
		return ;
	va_start(args, s);
	while (i < n)
	{
		str = va_arg(args, char *);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
	va_end(agrs);
}
