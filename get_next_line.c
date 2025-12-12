/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamaral- <eamaral-student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:27:09 by eamaral-          #+#    #+#             */
/*   Updated: 2025/12/12 21:37:43 by eamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*line;

	line = NULL;
	while (1)
	{
		if (*buffer == 0)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read < 0)
				return (free(line), NULL);
			if (bytes_read == 0)
				break ;
			buffer[bytes_read] = '\0';
		}
		line = gnl_strjoin(line, buffer);
		if (clear_n_check(buffer) == 1)
			break ;
	}
	return (line);
}
