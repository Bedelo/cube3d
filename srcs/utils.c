
#include "./../includes/cube3d.h"


int	rgbToHex(int r, int g, int b)
{
    return ((r << 16) | (g << 8) | b);
}

void	ft_freenstr(int n, void *str, ...)
{
	va_list	args;
	int		i;
	void	*ptr;

	va_start(args, str);
	i = 0;
	while (i < n && n != 0)
	{
		if (i == 0)
		{
			if (str)
				free(str);
			str = NULL;
		}
		else
		{
			ptr = va_arg(args, void *);
			if (ptr)
				free(ptr);
			ptr = NULL;
		}
		i++;
	}
}



unsigned int	to_color_rc(char *str)
{
    char			**rgb;
    int				color[3];
    unsigned int	color_hex;

    // printf("\n\n#%s#\n\n", str);
    rgb = ft_split_arg(str, ',');
    if (!rgb)
        return (-1);
    color[0] = ft_atoi(rgb[0]);
    color[1] = ft_atoi(rgb[1]);
    color[2] = ft_atoi(rgb[2]);
    color_hex = (unsigned int) rgbToHex(color[0], color[1], color[2]);
    freetab((void **)rgb, -1);
    return (color_hex);
}
