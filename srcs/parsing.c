#include "./../includes/cube3d.h"



static int	valid_file(char *file, char *extension)
{
	int	len;

	len = ft_strlen(file);
	if (len > 4)
	{
		if (ft_strncmp(&file[len - 4], extension, 4) == 0)
			return (1);
	}
	return (0);
}

/**
 * open  file of map as input, fd is returned
 * @param file
 * @return fd of the file
 * fd must be closed after use
 */
int	ft_handle_map(char *file, char *extension)
{
	int		fd;
	if (valid_file(file, extension) == 0)
	{
		err(ERROR);
		err("Error opening file: \n");
		err("Extension error \n");
		err(file);
		err("\n");
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("\nError opening file: \n", 2);
		ft_putstr_fd(file, 2);
		if (errno == ENOENT)
			ft_putstr_fd("\nFile not found\n", 2);
		if (errno == EACCES)
			ft_putstr_fd("\nAcces not granted\n", 2);
		return (-1);
	}
	return (fd);
}



/**
 * get the length of the longest line x (columns)
 * @param fd
 * @param header_len
 * @return length of the longest line x
 */
int	len_x(int fd, int *header_len)
{
	char	*line;
	int		len_x;
	int		ret;

	len_x = 0;
	if (fd == -1)
		return (-1);
	while (check_is_header(&line, fd) == OK)
		free(line);
	while (1)
	{
		if (!line)
			break ;
		if (ft_strlen(line) > len_x)
			len_x = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	return (len_x);
}

/**
 * get the length of the map in y (rows)
 * @param fd
  * @param header_len
 * @return length of the map in y
 */
int	len_y(int fd, int *header_len)
{
	char	*line;
	int		len_y;
	int		ret;

	ret = 0;
	len_y = 0;
	if (fd == -1)
		return (-1);
	while (check_is_header(&line, fd) == OK)
		free(line);
	while (1)
	{
		if (!line)
			break ;
		len_y++;
		free(line);
		line = get_next_line(fd);
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
int	map_dim(int *dim, char *file, int (*f) (int, int*), int *header_len)
{
	int	fd;

	fd = ft_handle_map(file, ".cub");
	if (fd < 0)
		return (KO);
	else
		*dim = f(fd, header_len);
	close(fd);
	return (OK);
}
