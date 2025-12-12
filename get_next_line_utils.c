/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamaral- <eamaral-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:49:30 by eamaral-          #+#    #+#             */
/*   Updated: 2025/12/11 22:11:38 by eamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
char	*ft_strjoin(char *s1, char *s2)
{
	int 	i;
	int		j;
	char	*nstr;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
		if (!s2)
		return (NULL);
	nstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!nstr)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		nstr[i] = s1[i];
	while (s2[++j])
		nstr[i + j] = s2[j];
	free(s1);
	nstr[i + j] = 0;
	return (nstr);
}
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*nstr;
	size_t	s_len;
	
	if (!s || start >= (s_len = ft_strlen(s)))
	{
		nstr = malloc(1);
		if (!nstr)
			return (NULL);
		nstr[0] = 0;
		return (nstr);
	}
	if (len > s_len - start)
		len = s_len - start;
	nstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nstr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		nstr[i] = s[start + i];
		i++;
	}
	nstr[i] = 0; 
	return (nstr);
}
char	*ft_strdup(const char *s)
{
	char	*nstr;
	size_t	len;
	int		i;
	
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	nstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nstr)
		return (NULL);
	i = -1;
	while (s[++i])
		nstr[i] = s[i];
	nstr[i] = 0;
	return (nstr);
}
