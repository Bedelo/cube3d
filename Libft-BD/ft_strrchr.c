/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:41:24 by bsunda            #+#    #+#             */
/*   Updated: 2023/11/29 13:26:36 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	size_t	len;

	ptr = (char *)s;
	len = ft_strlen(ptr);
	if (c == 0)
		return (ptr + len);
	while (len-- > 0)
	{
		if (ptr[len] == c % 256)
			return (&ptr[len]);
	}
	return (NULL);
}

/*int main(void)
{
	char s[20] = "hello";
	char s2[20] = "hello";
	printf("%p\n\n%p\n\n", strrchr(s, 'c'), ft_strrchr(s2, 'c'));
	printf("%s\n\n%s\n\n", strrchr(s, 'o'), ft_strrchr(s2, 'o'));
	return (1);
}
*/
