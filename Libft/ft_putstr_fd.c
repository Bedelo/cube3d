/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:30:19 by bsunda            #+#    #+#             */
/*   Updated: 2023/11/17 09:46:46 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

/*int	 main(void)
{
	char	c;
	int	fd = open("coucou", O_RDWR);
	ft_putstr_fd(" mon texte", fd);
	while (read(fd, &c, 1))
	{
		write(1, &c, 1);
	}
	close(fd);
	return (0);
}*/
