#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char *line;
	int i = 0;
		line = NULL;
	int fd = open(argv[1],O_RDONLY);
//	printf("ok");
	while((i = get_next_line(fd, &line)))
	{
		ft_putendl(line);
		free(line);
	}
//	printf("%d",i);
	char *ine = "lol";
	char *tmp;
	tmp = ine;
	printf("%s\n",tmp);
	close(fd);
	return 0;
}
