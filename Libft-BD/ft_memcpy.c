/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:40:50 by bsunda            #+#    #+#             */
/*   Updated: 2023/11/14 15:24:09 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s;

	s = (char *)dest;
	if (!src && !dest)
		return (NULL);
	if (dest == src || !n)
		return (dest);
	while (n--)
		ft_memset(dest++, *(char *)src++, sizeof(char));
	return (s);
}

/*int	main(void)
{
	char	src[50] = "Un tres grande phrase bin longue";
	char	dest[50] = "un phrase";
	char	*dest_ol = &src[5];
	printf("%s\n", ft_memcpy(dest, src, 3));
	return (0);
}
*/