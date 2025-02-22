/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:57:18 by bsunda            #+#    #+#             */
/*   Updated: 2023/11/22 10:11:19 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*c1 != *c2)
			return ((int)(*c1 - *c2));
		c1++;
		c2++;
		n--;
	}
	return (0);
}

/*int	main(void)
{
	int n = 20;
	char	*s1 = "Ma phrase avec des mots";
	char	*s2 = "Ma phrase avec dez mots";
	printf("%d\n%d\n", ft_memcmp(s1, s2, n), memcmp(s1, s2, n));
	return (1);
}
*/
