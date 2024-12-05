/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:22:14 by bsunda            #+#    #+#             */
/*   Updated: 2023/11/13 13:15:35 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	if (c == 0)
		return (ptr + (int )ft_strlen(ptr));
	while (*ptr)
	{
		if (*ptr == c % 256)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

/*int main(void)
{
	char s[20] = "hello";
	char s2[20] = "hello";
	printf("%p\n\n%p\n\n", strchr(s, 'c'), ft_strchr(s2, 'c'));
	printf("%s\n\n%s\n\n", strchr(s, 'l'), ft_strchr(s2, 'l'));
	return (1);
}
*/