
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    // Open a text file
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    // Loop until get_next_line returns NULL (EOF or Error)
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Critical: avoid memory leaks
    }

    close(fd);
    return (0);
}
