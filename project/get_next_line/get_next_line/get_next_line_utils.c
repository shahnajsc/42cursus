/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:07:12 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/06 13:14:27 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
    int count;

    count = 0;
    if (!str)
    {
        return (0);
    }
    while (str[count] != '\0')
    {
        count++;
    }
    return (count);
}

char *ft_strdup(const char *str)
{
    int     len;
    char    *ptr;
    int     count;

    if (!str)
    {
        return (0);
    }
    count = 0;
    len = ft_strlen(str);
    ptr = (char *)malloc(sizeof(char) * (len + 1));
    if (!ptr)
    {
        return (NULL);
    }
    while (str[count] != '\0' && count < len)
    {
        ptr[count] = str[count];
        count++;
    }
    ptr[count] = '\0';
    return (ptr);
}

char *ft_strchr(const char *s, int c)
{
    char *str;

    str = (char *)s;
    while (*str != '\0')
    {
        if (*str == (char)c)
        {
            return (str);
        }
        str++;
    }
    if (*str == (char)c)
    {
        return (str);
    }
    return (NULL);
}

char *ft_strjoin(const char *s1, const char *s2)
{
    char    *ptr;
    char    *ptrjoin;

    if (!s1 || !s2)
    {
        return (NULL);
    }
    ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!ptr)
    {
        return (NULL);
    }
    ptrjoin = ptr;
    while (*s1 != '\0')
    {
        *ptr++ = *s1++;
    }
    while (*s2 != '\0')
    {
        *ptr++ = *s2++;
    }
    *ptr++ = '\0';
    return (ptrjoin);

}

char *ft_substr(const char *str, unsigned int start, size_t len)
{
    char            *ptr;
    unsigned int    count;
    unsigned int    i;
    
    count = 0;
    if (!str)
        return (NULL);
    if (start > ft_strlen(str))
		len = 0;
	else if (len > (ft_strlen(str) - start))
		len = ft_strlen(str) - start;
    ptr = (char *)malloc(sizeof(char) * (len + 1));
    if (!ptr)
        return (NULL);
    while (str[count] != '\0' && count < start)
        count++;
    i = 0;
    while ((count < ft_strlen(str)) && i < len)
    {
        ptr[i] = str[count];
        i++;
        count++;
    }
    ptr[i] = '\0';
    return (ptr); 
}


#include <string.h>
#include <stdio.h>
int	main(void)
{
		
	printf("\n\n%s\n", "=== strlen ===");
	printf("c == Hello: %zu - %zu\n", ft_strlen("Hello\0rr"), strlen("Hello\0rr"));	
	printf("c == "": %zu - %zu\n\n", ft_strlen(" "), strlen(" "));
//	printf("null pointer: %zu - %zu\n", ft_strlen(NULL), strlen(NULL));

    printf("\n\n%s\n", "=== strdup ===");
	char	*str_ft_strdup = ft_strdup("..12www");
	char	*str_strdup = strdup("..12www");
	printf("Hello: %s - %s\n", str_ft_strdup, str_strdup);
	free(str_ft_strdup);
	free(str_strdup);

    printf("\n\n%s\n", "=== strchr ===");
    char	xyz[] = {""};
	
	printf("Z: %s - %s\n", ft_strchr(xyz, 'Z' ), strchr(xyz, 'Z'));


    printf("\n\n%s\n", "=== strjoi ===");
	printf("%s\n", ft_strjoin("Good ", "Day"));


    printf("\n\n%s\n", "=== substr ===");
	printf("%s\n", ft_substr("Hello", 1, 3));
	printf("%s\n", ft_substr("Hello", 3, 3));
	printf("%s\n", ft_substr("Hello", 6, 3));
	printf("%s\n", ft_substr("Hello", 1, 0));
	printf("return empty string: %s\n", ft_substr("", 0, 0));
	printf("return empty string: %s\n", ft_substr("", 0, 1));
	printf("return empty string: %s\n", ft_substr("", 1, 1));
	printf("return empty string: %s\n", ft_substr("ARGH", 4, 0));
	printf("return empty string: %s\n", ft_substr("ARGH", 4, 20));
	printf("return empty string: %s\n", ft_substr("ARGH", 5, 20));

}