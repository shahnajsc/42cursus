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