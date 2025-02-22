/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:38:33 by bsunda            #+#    #+#             */
/*   Updated: 2023/11/20 11:39:57 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
			write(fd, "2147483648", 10);
		n = -n;
	}
	if (n >= 0)
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', fd);
		else if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}

/*int	main(void)
{
	ft_putnbr_fd(0, 1);
	puts("\n\n");
	ft_putnbr_fd(-1, 1);
	puts("\n\n");
	ft_putnbr_fd(2, 1);
	puts("\n\n");
	ft_putnbr_fd(-2147483648, 1);
	puts("\n\n");
	return (0);
}
*/
