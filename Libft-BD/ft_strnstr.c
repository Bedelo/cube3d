/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:36:12 by bsunda            #+#    #+#             */
/*   Updated: 2023/11/20 10:45:15 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)&big[i]);
	if (big == little)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] && len > i + j && big[i + j] == little[j])
			j++;
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// char	*ft_strnstr(const char *big, const char *little, size_t len)
// {

// 	if (!*little)
// 		return ((char *)big);
// 	while (len > 0 && *big)
// 	{
// 		if (len == (size_t) len)
// 			len = ft_strlen(little);
// 		if (ft_strncmp(big, little, len) == 0)
// 			return ((char *)big);
// 		big++;
// 		len--;
// 	}
// 	return (NULL);
// }

/*int	main(void)
{
	int		n;
	char	*s1;
	char	*s2;

	n = 2;
	s1 = "des phrase, des mots et autres choses";
	s2 = "";
	printf ("%p\n%p\n", ft_strnstr(s1, s2, n), strnstr(s1, s2, n));
	return (0);
}
*/
