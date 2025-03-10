#include "./../includes/cube3d.h"

int	check_is_header(char **line, int fd)
{
	int	res;

	*line = get_next_line(fd);
	res = is_header(*line, fd);
	return (res);
}

char	**header_label(char *header[7])
{
	header[0] = "NO";
	header[1] = "SO";
	header[2] = "WE";
	header[3] = "EA";
	header[4] = "F";
	header[5] = "C";
	header[6] = NULL;
	return (header);
}

int	is_header(char *line, int fd)
{
	char	**split_line;
	int		size;
	char	*header[7];
	int		h;

	h = -1;
	size = 0;
	header_label(header);
	if (ft_strlen(line) == 1)
		return (OK);
	split_line = ft_split(line);
	if (!split_line)
		return (KO);
	while (split_line[size])
		size++;
	if (size != 2)
		return (shield_malloc_2(split_line, size), KO);
	while (header[++h])
	{
		if (ft_strncmp(*split_line, header[h], ft_strlen(split_line[0])) == 0)
			return (shield_malloc_2(split_line, size), OK);
	}
	return (shield_malloc_2(split_line, size), KO);
}

