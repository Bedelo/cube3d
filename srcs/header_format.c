/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:50:39 by bsunda            #+#    #+#             */
/*   Updated: 2025/03/28 14:57:04 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

int	check_header_cardinal(char *file)
{
	int	fd;

	fd = ft_handle_map(file, ".xpm");
	if (fd > 0)
	{
		close(fd);
		return (OK);
	}
	return (KO);
}

static int	is_color(char *color)
{
	int	j;

	j = 0;
	while (color[j])
	{
		if (!ft_isdigit(color[j]) || j > 3)
			return (KO);
		j++;
	}
	return (OK);
}

static int	count_commas(char *line)
{
	int	k;
	int	commas;

	k = 0;
	commas = 0;
	if (!line)
		return (0);
	while (line[k])
	{
		if (line[k] == ',')
			commas++;
		k++;
	}
	return (commas);
}

int	check_header_no_cardinal(char *file)
{
	char	**tab;
	int		i;

	if (count_commas(file) != 2)
		return (err("Bad color format\n"), KO);
	tab = ft_split_arg(file, ',');
	if (!tab)
		return (KO);
	if (ft_len_tab(tab) != 3)
		return (freetab((void **)tab, -1), KO);
	i = 0;
	while (i < 3)
	{
		if (is_color(tab[i]) == KO)
			return (err("Bad value header\n"), freetab((void **)tab, -1), KO);
		if (ft_atoi(tab[i]) < 0 || ft_atoi(tab[i]) > 255)
			return (err("Bad range header\n"), freetab((void **)tab, -1), KO);
		i++;
	}
	return (freetab((void **)tab, -1), OK);
}
