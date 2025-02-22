/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:40:07 by bsunda            #+#    #+#             */
/*   Updated: 2024/01/15 14:48:22 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != '\0' && *s != c)
				s++;
			words++;
		}
		else
			s++;
	}
	return (words);
}

static size_t	ln_wds(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*ft_strallc(const char *s, size_t in_buff)
{
	char	*buffer0;
	size_t	t;

	if (!s)
		return (NULL);
	buffer0 = (char *)malloc((in_buff + 1) * sizeof(char));
	if (!buffer0)
		return (NULL);
	t = 0;
	while (*s && t < in_buff)
	{
		buffer0[t++] = *s++;
	}
	buffer0[t] = '\0';
	return (buffer0);
}

static void	*ft_free_tab(char **s, size_t i)
{
	size_t	k;

	k = 0;
	while (k < i)
	{
		free(s[k]);
		k++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	size_t	i;

	if (!s)
		return (NULL);
	i = count_words(s, c);
	strs = (char **)malloc((i + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	strs[i] = NULL;
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			strs[i++] = ft_strallc(s, ln_wds(s, c));
			if (!strs[i - 1])
				return (ft_free_tab(strs, i - 1));
			s += ln_wds(s, c);
		}
	}
	return (strs);
}
