/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamaral- <eamaral-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:32:58 by eamaral-          #+#    #+#             */
/*   Updated: 2025/12/13 17:54:00 by eamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	int			bytes_read;
	char		*line;

	line = NULL;
	while (1)
	{
		if (*buffer[fd] == 0)
		{
			bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
			if (bytes_read < 0)
				return (free(line), NULL);
			if (bytes_read == 0)
				break ;
			buffer[fd][bytes_read] = '\0';
		}
		line = gnl_strjoin(line, buffer[fd]);
		if (clear_n_check(buffer[fd]) == 1)
			break ;
	}
	return (line);
}

int main(int ac, char **av)
{
	char *line;
	int i = 0;
	int fd;
	
	while (i++ < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd < 0)
			return 1;
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("%s", line);
			free(line);
		}
		close(fd);
	}
	return 0;
}
