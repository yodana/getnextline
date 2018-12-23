#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char *line;
	int i = 0;
		line = NULL;
	int fd = open(argv[1],O_RDONLY);
	int fd2 = open(argv[2],O_RDONLY);
	get_next_line(fd,&line);
		ft_putendl(line);
	get_next_line(fd2,&line);
	ft_putendl(line);
	get_next_line(fd,&line);
	ft_putendl(line);
	get_next_line(fd2,&line);
	ft_putendl(line);
	close(fd);
	return 0;
}
