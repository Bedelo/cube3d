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
 * get the length of the longest line x (columns)
 * @param fd
 * @return length of the longest line x
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

/**
 * get the length of the map in y (rows)
 * @param fd
 * @return length of the map in y
 */
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

/**
 * get the dimension x or y of the map respectively if f equal len_x or len_y
 * @param dim x or y pointer of the map from len_x or len_y
 * @param file	 file of the map
 * @param f	 function len_x or len_y
 * @return 0 if success, 1 if fail
*/
int	map_dim(int *dim, char *file, int (*f) (int))
{
	int	fd;

	fd = ft_handle_map(file);
	if (fd == -1)
		return (1);
	else
		*dim = f(fd);
	close(fd);
	return (0);
}
