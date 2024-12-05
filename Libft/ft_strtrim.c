/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:15:56 by bsunda            #+#    #+#             */
/*   Updated: 2023/11/16 13:27:36 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sx(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_sx(s1[start], set))
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	while (end > start && ft_sx(s1[end - 1], set))
		end--;
	len = end - start;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_memcpy(result, &s1[start], len);
	result[len] = '\0';
	return (result);
}

/*int	main(void)
{
	char	set[20] = "1a222";
	char	s1[50] = "000aa111aa222aa333aa444aa555aa666aa777";

	printf("%s\n", ft_strtrim(s1, set));
	// printf("%s\n", ft_strtrim(s0, set));
	return (0);
}
*/