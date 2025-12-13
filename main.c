/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamaral- <eamaral-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:23:38 by eamaral-          #+#    #+#             */
/*   Updated: 2025/12/13 02:46:01 by eamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static void	wait_for_enter(void)
{
	printf("\n[Press ENTER to continue...]");
	fflush(stdout);
	while (getchar() != '\n')
		;
}

static void	test_normal_file(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error: can't open test.txt (skipped)\n");
		return ;
	}
	i = 1;
	printf("\n+---------------------------+\n");
	printf("| Reading test.txt          |\n");
	printf("+---------------------------+\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("\n[%d]:  %s\n", i, line);
		free(line);
		i++;
	}
	close(fd);
}

static void	test_empty_file(void)
{
	int		fd;
	char	*line;

	fd = open("empty.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Can't open empty.txt (skipped)\n");
		return ;
	}
	printf("\n+---------------------------+\n");
	printf("| Reading empty.txt         |\n");
	printf("+---------------------------+\n");
	line = get_next_line(fd);
	if (!line)
		printf("\nResult: File is empty (correct!)\n");
	else
	{
		printf("Result: File should be empty but got: %s", line);
		free(line);
	}
	close(fd);
}

static void	test_stdin(void)
{
	char	*line;
	int		i;

	printf("\n+----------------------------------------+\n");
	printf("| Reading stdin (Ctrl+D to exit)         |\n");
	printf("+--------------------------------------- +\n");
	i = 1;
	while (1)
	{
		printf("\n> ");
		fflush(stdout);
		line = get_next_line(0);
		if (!line)
		{
			printf("\r\033[K");
			break ;
		}
		printf("\n[%d]: %s", i, line);
		i++;
		free(line);
	}
}

int	main(void)
{
	printf("+=====================================+\n");
	printf("|     GET_NEXT_LINE TEST              |\n");
	printf("+=====================================+\n");
	wait_for_enter();
	test_normal_file();
	wait_for_enter();
	test_empty_file();
	wait_for_enter();
	test_stdin();
	printf("\nThank you for testing it!\n");
	return (0);
}
