/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedelo <bedelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:19:30 by bsunda            #+#    #+#             */
/*   Updated: 2024/12/05 14:45:18 by bedelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;

	s = (char *)dest;
	if (!src && !dest)
		return (NULL);
	if (dest == src || !n)
		return (dest);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		dest += n;
		src += n;
		while (n--)
			ft_memset(--dest, *(char *)(--src), sizeof(char));
	}
	return (s);
}

/*int	main(void)
{
	char	src[50] = "123456789ABCDEF";
	char	*dest = &src[3];
	char	s[50] = "123456789ABCDEF";
	char	*d = &s[3];

	printf("%s\n%s\n", src, (char *)ft_memmove(dest, src, 5));
	puts("\n\n");
	printf("%s\n%s\n", s, (char *)memmove(d, s, 5));
	return (0);
}

*/
