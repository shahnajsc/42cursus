/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:07:12 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/05 17:18:48 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *str)
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

char *ft_strdup(char *str)
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
#include <string.h>
#include <stdio.h>
int	main(void)
{
		
	printf("%s\n", "=== strlen ===");
	printf("c == Hello: %zu - %zu\n", ft_strlen("Hello\0rr"), strlen("Hello\0rr"));	
	printf("c == "": %zu - %zu\n", ft_strlen(" "), strlen(" "));
//	printf("null pointer: %zu - %zu\n", ft_strlen(NULL), strlen(NULL));

    printf("%s\n", "=== strdup ===");
	char	*str_ft_strdup = ft_strdup("");
	char	*str_strdup = strdup("");
	printf("Hello: %s - %s\n", str_ft_strdup, str_strdup);
	free(str_ft_strdup);
	free(str_strdup);

}