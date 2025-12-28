/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamaral- <eamaral-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:33:40 by eamaral-          #+#    #+#             */
/*   Updated: 2025/12/13 15:33:54 by eamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			break ;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	l1;
	size_t	l2;

	l1 = gnl_strlen(s1);
	l2 = gnl_strlen(s2);
	str = malloc(l1 + l2 + 1);
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	gnl_memcpy(str, s1, l1);
	gnl_memcpy(str + l1, s2, l2);
	str[l1 + l2] = '\0';
	free(s1);
	return (str);
}

void	*gnl_memcpy(void *dst, void *src, size_t len)
{
	char	*tmp_dst;
	char	*tmp_src;
	size_t	i;

	if (!dst || !src)
		return (NULL);
	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	i = 0;
	while (i < len)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	return (tmp_dst);
}

int	clear_n_check(char *buffer)
{
	int	i;
	int	j;
	int	newline;

	newline = 0;
	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (newline == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			newline = 1;
		buffer[i++] = 0;
	}
	return (newline);
}
