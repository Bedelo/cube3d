#include "./../includes/cube3d.h"

int check_header_cardinal(char *file)
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
		if (!ft_isdigit(color[j]))
			return (KO);
		j++;
	}
	return (OK);
}

int check_header_no_cardinal(char *file)
{
	char	**tab;
	int		i;

	tab = ft_split_arg(file, ',');
	if (!tab)
		return (KO);
	if (ft_len_tab(tab) != 3)
		return (freetab((void **)tab, -1), KO);
	i = 0;
	while( i < 3)
	{
		if (is_color(tab[i]) == KO)
			return (err("Bad value header\n"), freetab((void **)tab, -1), KO);
		if (ft_atoi(tab[i]) < 0 || ft_atoi(tab[i]) > 255)
			return (err("Bad range header\n"), freetab((void **)tab, -1), KO);
		i++;
	}
	return (freetab((void **)tab, -1), OK);
}

int header_format(t_header *header)
{
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
