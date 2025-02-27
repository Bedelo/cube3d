
#include "./../includes/cube3d.h"

int	rgbToHex(int r, int g, int b, char *hex)
{
	const char hexDigits[] = "0123456789ABCDEF";

	hex[0] = '#';
	hex[1] = hexDigits[r / 16];
	hex[2] = hexDigits[r % 16];
	hex[3] = hexDigits[g / 16];
	hex[4] = hexDigits[g % 16];
	hex[5] = hexDigits[b / 16];
	hex[6] = hexDigits[b % 16];
	hex[7] = '\0';
	return (ft_htoi(hex));
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
