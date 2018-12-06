
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char **line;
	int i = 0;
	line = malloc(sizeof(char) * 100);
	int fd = open(argv[1],O_RDONLY);
//	printf("ok");
	get_next_line(fd, line);
	printf("line %d : %s",i,line[0]);
		i++;
		return 0;
}
