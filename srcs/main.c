#include "./../includes/cube3d.h"

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;

	int	fd;
	fd = ft_handle_map("maps/maps5.cub");
	if (fd == -1)
		return (-1);
	return (len_y(fd));
}
