
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char **line;

	line = malloc(sizeof(char) * 100);
	int fd = open(argv[1],O_RDONLY);
//	printf("ok");
	while(get_next_line(fd, line));
	printf("%s",line[0]);
	return 0;
}
