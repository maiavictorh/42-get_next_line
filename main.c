#include "get_next_line.h"

int main()
{
    int fd;
	char buffer[1024];

    fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (write (1, "Cannot read file!\n", 19));
	printf("Fd return: %d\n", fd);
	while (read(fd, buffer, sizeof(buffer)));
		write (1, fd, buffer, sizeof(buffer));
}
