#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "libft.h"

int main()
{
    char *newstr = strchr(NULL, 2);
    //char *newstr = ft_strchr(NULL, 2);
    //char *newstr = strchr(NULL, 2);
    return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}