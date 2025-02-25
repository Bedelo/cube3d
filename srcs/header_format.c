#include "./../includes/cube3d.h"

int check_header_cardinal(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len > 4)
	{
		if (ft_strncmp(&file[len - 4], ".png", 4) == 0)
			return (OK);
	}
	//# TO DO : CHECK IF FILE EXISTS
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
	// if(check_header_cardianal(header->no) == KO)
	// 	return (KO);
	// if(check_header_cardianal(header->so) == KO)
	// 	return (KO);
	// if(check_header_cardianal(header->we) == KO)
	// 	return (KO);
	// if(check_header_cardianal(header->ea) == KO)
	// 	return (KO);
	if(check_header_no_cardinal(header->f) == KO)
		return (KO);
	if(check_header_no_cardinal(header->c) == KO)
		return (KO);
	return (OK);
}
