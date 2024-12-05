/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:58:41 by bsunda            #+#    #+#             */
/*   Updated: 2023/11/14 15:42:44 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	supp_len;

	supp_len = 0;
	src_len = ft_strlen((char *)src);
	while (size > 0 && *dst)
	{
		dst++;
		supp_len++;
		size--;
	}
	while (size-- > 1 && *src)
	{
		*dst++ = *src++;
	}
	if (size == 0 || !*src)
		*dst = '\0';
	return (src_len + supp_len);
}

/*int main(void)
{
	int size = 8;
	char dst[20] = "messag";
	char src[20] = "-ok-";
	printf("%zu\n %s\n", ft_strlcat(dst, src, size), dst);

	char odst[20] = "messag";
	char osrc[20] = "-ok-";
	printf("%zu\n %s\n", strlcat(odst, osrc, size), odst);

	return (0);
}
*/
