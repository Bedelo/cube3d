/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:53:12 by bsunda            #+#    #+#             */
/*   Updated: 2023/11/14 15:31:50 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*sc;

	sc = (char *)s;
	while (n--)
	{
		if (*sc == (c % 256))
			return (sc);
		sc++;
	}
	return (NULL);
}

/*int	main(void)
{
	char str[20] = "un truc a ecrire";
	printf("%p\n%p\n", ft_memchr(str, 'a', 5), memchr(str, 'a', 5));
	return (1);
}
*/