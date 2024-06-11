#include  "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd;

    fd = open("textfile.txt", O_RDONLY);

    printf("%s -ebd-", get_next_line(fd));
    
}