#include "./../includes/cube3d.h"



int	check_is_header(char **line, int fd)
{
	int	res;

	*line = get_next_line(fd);
	res = is_header(*line, fd);
	return (res);
}

int	is_header(char *line, int fd)
{
	char	**split_line;
	int		size;
	char	*header[7] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	int		h;

	h = -1;
	size = 0;
	if (ft_strlen(line) == 1)
		return (OK);
	split_line = ft_split(line, ' ');
	while (split_line[size])
		size++;
	if (size != 2)
	{
		shield_malloc_2(split_line, size);
		return (KO);
	}
	while (header[++h])
	{
		if (ft_strncmp(*split_line, header[h], ft_strlen(split_line[0])) == 0)
		{
			shield_malloc_2(split_line, size);
			return (OK);
		}
	}
	shield_malloc_2(split_line, size);
	return (KO);
}

int	check_is_map(char *file, int *header_len)
{
	int		fd;
	char	*line;

	*header_len = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error: fd: check is map fails\n", 30);
		return (KO);
	}
	line = get_next_line(fd);
	while (is_header(line, fd) == OK)
	{
		*header_len += 1;
		free(line);
		line = get_next_line(fd);
		printf("vide ? %ld\n", ft_strlen(line));
		printf("######################### IS HEADER ###############################\n");
	}
	close(fd);
	return (OK);
}
