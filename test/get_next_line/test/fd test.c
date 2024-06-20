#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
    int file1;
    //char *str = "qweqwrwr";

    file1 = fopen("file1.text", "r");
   /* if (file1 == NULL)
    {
        printf("error getting file");
        return 1;
    }
   
    //fprintf(file1, "%s", str);
    if (fprintf(file1, "%s", str) < 0)
    {
        printf("Error writing to file");
        fclose(file1);
        return 1;
    }*/
    printf("%d", *file1);
    fclose(file1);
    return 0;
    
}