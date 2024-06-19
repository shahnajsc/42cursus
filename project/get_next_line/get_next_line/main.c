/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:18:15 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/19 00:27:28 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


#include <stdio.h>

int main()
{
    int  fd;
    char *line;
    int  count;

    count = 0;
    fd = open("textfile.txt", O_RDONLY);
   /*if (fd == -1)
    {
        printf("Error opening file");
        return (1);
    } */
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
        break ;
        count++;
        printf("[%d]:%s\n", count, line);
        line = NULL;
    }
    close(fd);
    return (0);
    
}


/*

#include <string.h>
#include <stdio.h>
int	main(void)
{
		
	printf("\n\n%s\n", "=== strlen ===");
	printf("c == Hello: %zu - %zu\n", ft_strlen("Hello\nrr"), strlen("Hello\nrr"));	
	printf("c == Hello: %zu - %zu\n", ft_strlen_newline("Hello\nrr"), strlen("Hello\nrr"));	
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
*/