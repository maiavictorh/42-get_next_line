#include "get_next_line.h"

int main()
{
    int fd;
	char buffer[1024];

    fd = open("test.txt", O_RDONLY);
	printf("%d\n", fd);
	while (read(fd, buffer, sizeof(buffer)))
		write (1, &buffer, sizeof(buffer));
}
