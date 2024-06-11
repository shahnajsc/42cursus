#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *read_buffer;
    ssize_t bytes_buffer;
    static char *left_buffer;
    char *line;
    ssize_t i;

    if (fd < 0 )
    {
        return (NULL);
    }
    read_buffer = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
    if (!read_buffer)
    {
        return (NULL);
    }
    bytes_buffer = 1;
    while (bytes_buffer > 0)
    {
    ssize_t bytes_buffer = read(fd, read_buffer, BUFFER_SIZE);
    if (bytes_buffer == -1)
    {
        return (NULL);
    }
    else if (bytes_buffer == 0)
        break;
    read_buffer[bytes_buffer] = '\0';
    i = 0;
    while (read_buffer[i] != '\n' || read_buffer[i] != '\0')
    {
        i++;
    }
    if (read_buffer[i] == '\n')
    {
        line = ft_strdup(read_buffer);
    }
    else if(read_buffer == '\0')
    {
        left_buffer = ft_strjoin(left_buffer, read_buffer);
    }
    
    }
}

/*
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main (void)
{
  int   fd;
  ssize_t   tread;
  char *buffer;
  char *str;
  char  *ptr;
  char  *btr;
  int   buf_size = 9;

  buffer = (char *)malloc(sizeof(char) * buf_size);
  if (!buffer)
  {
    printf("\n buffer memory allocation fail\n");
    return (-1);
  }
  str = (char *)malloc(sizeof(char) * 5);
  if (!str)
  {
    printf("\nstr memory allocation fail\n");
    return (-1);
  }
  ptr = str;
  fd = open("file.txt", O_RDONLY);
  if (fd == -1)
  {
    printf("\nfile open error\n");
    free(buffer);
    free(str);
    return (-1);
  }
  else
  {
     printf("file open success\n");
  }
  tread = read(fd, buffer, 7);
  if (tread == -1)
  {
    printf("file read error\n");
    free(buffer);
    free(str);
    close(fd);
    return (-1);
  }
   else
  { 
    buffer[tread] = '\0';
    btr = buffer;
    while (*btr && *str)
    {
      *ptr++ = *btr++;
    }
    printf("str %s\n", str);
    printf("ptr %s\n", ptr);
    printf("btr %s\n", btr);
    printf("buffer %s\n", buffer);
  }
  close(fd);
  free(buffer);
  free(str);
  return (0);
} 
*/