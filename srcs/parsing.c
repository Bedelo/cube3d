#include "./../includes/cube3d.h"

/**
 * open  file of map as input, fd is returned
 * @param file
 * @return fd of the file
 * fd must be closed after use
 */
int	ft_handle_map(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Cannot read file.\n", 2);
		return (-1);
	}
	return (fd);
}

/**
 * get the length of the longest line in the map
 * @param fd
 * @return length of the longest line
 */
int	len_x(int fd)
{
	char	*line;
	int		len_x;

	len_x = 0;
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(line) > len_x)
			len_x = ft_strlen(line);
		free(line);
	}
	return (len_x);
}

int	len_y(int fd)
{
	char	*line;
	int		len_y;

	len_y = 0;
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len_y++;
		free(line);
	}
	return (len_y);
}

