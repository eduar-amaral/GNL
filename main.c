/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamaral- <eamaral-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:23:38 by eamaral-          #+#    #+#             */
/*   Updated: 2025/12/11 22:04:40 by eamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int		fd;
	char	*line;
	int		i;

	// test1 - Normal file
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error, can't open file.\n");
		return (1);
	}
	i = 1;
	printf("=== Lendo test.txt ===\n");
	while ((line = get_next_line(fd)))
	{
		printf("[%d]:  %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	// Test 2 - Empty file
	fd = open("empty.txt", O_RDONLY);
	if (fd >= 0)
	{
		printf("\n=== Reading empty.txt ===\n");
		line = get_next_line(fd);
		printf("Resultado: %s\n", line ?  line : "NULL (correto!)");
		if (line)
			free(line);
		close(fd);
	}
	// Teste 3: Stdin (teste manual)
	printf("\n=== Write anything (Ctrl+D to finish) ===\n");
	while ((line = get_next_line(0)))
	{
		printf("you wrote: %s", line);
		free(line);
	}
	return (0);
}