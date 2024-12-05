/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:38:43 by bsunda            #+#    #+#             */
/*   Updated: 2023/11/16 08:48:13 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	s1_l;
	size_t	s2_l;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	str = (char *)malloc((s1_l + s2_l + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < s1_l + s2_l)
	{
		if (i < s1_l)
			str[i] = s1[i];
		else
			str[i] = s2[i - s1_l];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*int	main(void)
{
	char	s1[20] = "AAA";
	char	s2[20] = "bb";
	printf("%s\n", ft_strjoin(s1 , s2));
	return (0);
}
*/