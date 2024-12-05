/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:56:23 by bsunda            #+#    #+#             */
/*   Updated: 2023/11/14 09:54:40 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen((char *)src);
	while (size-- > 1 && *src)
	{
		*dst++ = *src++;
	}
	if (size == 0 || !*src)
		*dst = '\0';
	return (src_len);
}

/*int	main(void)
{
	size_t	size = 3;
	char	dst[7] = "prem";
	char	src[20] = "mier truc";
	printf("%zu\n%s\n", ft_strlcpy(dst, src, size), dst);

	char	odst[7] = "prem";
	char	osrc[20] = "mier truc";
	printf("%zu\n%s\n", strlcpy(odst, osrc, size), dst);
	return (0);
}
*/