/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamaral- <eamaral-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:49:27 by eamaral-          #+#    #+#             */
/*   Updated: 2025/12/11 21:20:57 by eamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*into_buffer(int fd, char *buffer);
static char	*get_line(char *buffer);
static char	*update_buffer(char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = ft_strdup("");
		if (!buffer)
			return (NULL);
	}
	buffer = into_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}
static char	*into_buffer(int fd, char *buffer)
{
	char	*tmp_buf;
	int		ret_read;

	tmp_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp_buf)
		return (NULL);
	ret_read = 1;
	while (ret_read > 0 && !ft_strchr(buffer, 10))
	{
		ret_read = read(fd, tmp_buf, BUFFER_SIZE);
		if (ret_read < 0)
		{
			free(tmp_buf);
			return (NULL);
		}
		tmp_buf[ret_read] = 0;
		buffer = ft_strjoin(buffer, tmp_buf);
	}
	free(tmp_buf);
	return (buffer);
}
static char	*get_line(char *buffer)
{
	char	*line;
	char	*nl_pos;
	size_t	len;

	if (!buffer || !buffer[0])
		return (NULL);
	nl_pos = ft_strchr(buffer, 10);
	if (nl_pos)
	{
		len = (nl_pos - buffer) + 1;
		line = ft_substr(buffer, 0, len);
	}
	else
		line = ft_strdup(buffer);
	return (line);
}
static char	*update_buffer(char *buffer)
{
	char	*new_buf;
	char	*nl_pos;
	size_t	start;
	size_t	len;

	nl_pos = ft_strchr(buffer, 10);
	if (!nl_pos)
	{
		free(buffer);
		return (NULL);
	}
	start = (nl_pos - buffer) + 1;
	len = (ft_strlen(nl_pos + 1));
	new_buf = ft_substr(buffer, start, len);
	free(buffer);
	return (new_buf);
}