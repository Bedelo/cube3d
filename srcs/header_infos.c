#include "./../includes/cube3d.h"

int	fill_header(char **split_, int i, int j)
{
	char	*label[7];
	int		l;

	l = -1;
	header_label(label);
	while (label[++l])
	{
		if (ft_strncmp(split_[i], label[l], ft_strlen(split_[i]) + 1) == 0)
			break ;
	}
	if (label[l] == NULL)
		return (err("Label initiation failed"), freetab((void **)split_, -1), KO);
	if (split_[j] != NULL)
		return (OK);
	else
		return (err("Label empty"), freetab((void **)split_, -1), KO);
}

int	label_empty(t_header *header, char *label)
{
	if(ft_strncmp(label, "NO", ft_strlen(label) + 1) == 0 && header->no == NULL)
		return (OK);
	if(ft_strncmp(label, "SO", ft_strlen(label) + 1) == 0 && header->so == NULL)
		return (OK);
	if(ft_strncmp(label, "WE", ft_strlen(label) + 1) == 0 && header->we == NULL)
		return (OK);
	if(ft_strncmp(label, "EA", ft_strlen(label) + 1) == 0 && header->ea == NULL)
		return (OK);
	if(ft_strncmp(label, "F", ft_strlen(label) + 1) == 0 && header->f == NULL)
		return (OK);
	if(ft_strncmp(label, "C", ft_strlen(label) + 1) == 0 && header->c == NULL)
		return (OK);
	return (KO);
}

void	store_label(t_header **h, char **split_line, int i, int j)
{
	t_header	*header;

	header = *h;
	if (ft_strncmp(split_line[i], "NO", ft_strlen(split_line[i]) + 1) == 0)
		(header)->no = ft_strdup(split_line[j]);
	if (ft_strncmp(split_line[i], "SO", ft_strlen(split_line[i]) + 1) == 0)
		(header)->so = ft_strdup(split_line[j]);
	if (ft_strncmp(split_line[i], "WE", ft_strlen(split_line[i]) + 1) == 0)
		(header)->we = ft_strdup(split_line[j]);
	if (ft_strncmp(split_line[i], "EA", ft_strlen(split_line[i]) + 1) == 0)
		(header)->ea = ft_strdup(split_line[j]);
	if (ft_strncmp(split_line[i], "F", ft_strlen(split_line[i]) + 1) == 0)
		(header)->f = ft_strdup(split_line[j]);
	if (ft_strncmp(split_line[i], "C", ft_strlen(split_line[i]) + 1) == 0)
		(header)->c = ft_strdup(split_line[j]);
	free(split_line[i]);
	split_line[i] = NULL;
	free(split_line[j]);
	split_line[j] = NULL;
	free(split_line);
	split_line = NULL;
}

int	header_init(t_header *header, char *line, int *nb_label)
{
	char	**split_line;
	int		size;
	int		i;
	int		j;

	i = -1;
	if (ft_strlen(line) == 1)
		return (free(line), OK);
	split_line = ft_split(line);
	if (ft_len_tab(split_line) != 2 || !split_line)
		return (err("Bad format header\n"), clean_header(header),\
			 free(line), freetab((void **)split_line, -1), KO);
	while (split_line[++i] && ft_isalpha(split_line[i][0]) == 0)
		;
	j = i;
	while (split_line[++j] && ft_strlen(split_line[j]) < 5)
		;
	if (fill_header(split_line, i, j) == OK && label_empty(header, split_line[i]) == OK)
		return ((*nb_label)++, store_label(&header, split_line, i, j), free(line), OK);
	else
		return (err("Double label in header\n"), clean_header(header),\
			 free(line), freetab((void **)split_line, -1), KO);
}

// void	display_header(t_header *header)
// {
// 	printf("NO: %s\n", header->no);
// 	printf("SO: %s\n", header->so);
// 	printf("WE: %s\n", header->we);
// 	printf("EA: %s\n", header->ea);
// 	printf("F: %s\n", header->f);
// 	printf("C: %s\n", header->c);
// }

t_header	*header_creation(char *file)
{
	t_header	*header;
	char		*line;
	int			fd;
	int			nb_label;

	nb_label = 0;
	fd = open(file, O_RDONLY);
	header = malloc(sizeof(t_header));
	if (!header)
		return (NULL);
	*header = (t_header){0};
	while (nb_label < 6)
	{
		line = get_next_line(fd);
		if (!line)
			return (err("Creation header failed!\n"), close(fd), NULL);
		if (header_init(header, line, &nb_label) == KO)
			return (err("Creation header failed!\n"), close(fd), NULL);
	}
	close (fd);
	// display_header(header);    //# to delete
	if(header_format(header) == KO)
		return (err("Creation header failed!\n"), clean_header(header), NULL);
	return (header);
}
