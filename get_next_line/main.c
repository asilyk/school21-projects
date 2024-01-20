#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <stdio.h>
#include <fcntl.h>
#define BUFFER_SIZE 16
int	main()
{
	int		fd;
	char	*s;
	//int i = 0;

	fd = open("gnl-war-machine-v2019/tests/baudelaire.txt", O_RDONLY);
	s = "\0";
	while (s != NULL)
	{
		s = get_next_line(fd);
		printf("%s\n", s);
		//i++;
	}
	// int		fd;
	// char	*line;

	// fd = open("gnl-war-machine-v2019/tests/baudelaire.txt", O_RDONLY);
	// if (fd == -1)
	// 	return (1);
	// while (1)
	// {
	// 	line = get_next_line(fd);
	// 	if (!line)
	// 		break ;
	// 	printf("%s\n", line);
	// 	free(line);
	// }
	// line = get_next_line(fd);
	// if (line)
	// {
	// 	printf("%s\n", line);
	// 	free(line);
	// }
	// close(fd);
	return (0);
}
