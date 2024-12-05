/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:09:20 by bsunda            #+#    #+#             */
/*   Updated: 2024/02/22 09:51:45 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_sline(char *line)
{
	int		c;
	char	*substash;

	c = 0;
	while (line[c] != '\0' && line[c] != '\n')
		c++;
	if (line[c] == 0)
		return (0);
	substash = ft_substr(line, c + 1, ft_strlen(line));
	if (*substash == 0)
	{
		free(substash);
		substash = NULL;
	}
	line[c + 1] = 0;
	return (substash);
}

static char	*reading(int fd, char *stash, char *buffer)
{
	int		rbytes;
	char	*tmp;

	rbytes = 1;
	while (rbytes > 0)
	{
		rbytes = read(fd, buffer, BUFFER_SIZE);
		if (rbytes == -1)
		{
			(free(buffer));
			return (NULL);
		}
		else if (rbytes == 0)
			return (stash);
		buffer[rbytes] = 0;
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(stash, '\n'))
			return (stash);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	char		*buffer;

	if (fd >= 1024)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = reading(fd, stash[fd], buffer);
	free(buffer);
	if (!line)
		return (NULL);
	stash[fd] = get_sline(line);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*buffer;

// 	fd = open("../var_env.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		write(1, "Cannot read file.\n", 18);
// 		return (1);
// 	}
// 	printf("%s\n\n", get_next_line(fd));
// 	printf("%s\n\n", get_next_line(fd));
// 	printf("%s\n\n", get_next_line(fd));
// 	printf("%s\n\n", get_next_line(fd));
// 	printf("%s\n\n", get_next_line(fd));
// 	printf("%s\n\n", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
