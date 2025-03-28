/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:05:01 by bsunda            #+#    #+#             */
/*   Updated: 2025/03/28 19:41:30 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

static int	f(int fd)
{
	char	*line;
	int		i;
	int		fin;

	i = 0;
	line = 0;
	fin = 0;
	while (!fin)
	{
		line = get_next_line(fd);
		if (!line)
			return (KO);
		if (ft_strlen(line) > 0 && ft_wc(line) > 0)
			fin = 1;
		else
			shield_malloc (line);
	}
	while (line[i] == ' ')
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (shield_malloc(line), OK);
	return (shield_malloc(line), KO);
}

int	header_format(t_header *header, int fd)
{
	if (f(fd) == KO)
		return (KO);
	if (check_header_cardinal(header->no) == KO)
		return (KO);
	if (check_header_cardinal(header->so) == KO)
		return (KO);
	if (check_header_cardinal(header->we) == KO)
		return (KO);
	if (check_header_cardinal(header->ea) == KO)
		return (KO);
	if (check_header_no_cardinal(header->f) == KO)
		return (KO);
	if (check_header_no_cardinal(header->c) == KO)
		return (KO);
	return (OK);
}
