/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:54:35 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/16 16:44:32 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// /////   ft_atoi 

/*
int main(void)
{
	char *str;

	str = "++--+-+-54321ad656";
	printf("from the ft function: %d\n", ft_atoi("   ---47a"));
	printf("from the lib function: %d\n", atoi("   ---47a")); 
		// while (str[count])
	// {
	// 	if (str[count] < 48 || str[count] > 57)
	// 		break ;
	// 	else
	// 		number = (number * 10) + str[count] - 48;
	// 	count++;
	// }
}
*/

//////////ft_bzero
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
		//bzero
	char s[] = "123456789";
	int n = 4;
	printf("main string: %s\n", s);
	bzero(s, n);
	printf("after lib bzero: %s\n", s);
	ft_bzero(s, n);	
	printf("after ft bzero: %s\n", s);
}
*/

//////////ft_isalnum
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	//is alnum
	printf("is alnum: %d\n", ft_isalnum(67));

}
*/


//////////ft_isalpha
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	//is alpha
	printf("is alpha: %d\n", ft_isalpha('&'));
}
*/



////////////// ft_isascii
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	// is ascii
	printf("is ascii: %d\n", ft_isascii(220));
}
*/


///////   ft_isdigit
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	// is digit
	printf("is digit: %d\n", ft_isdigit('0'));
}
*/


///////   ft_isprint
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	// is printable
	printf("is printable:%d\n" , ft_isprint(20));

}
*/

///////   ft_itoa
/*
int main(void)
{
    char *res = ft_itoa(9); 
	
    ft_print_result(res);
    free(res);
}
*/
/* check for :0, 9, -9, 10, -10,
	  8124, -9874, 543000, -2147483648LL, 2147483647
	  */


//////    ft_lstadd_back

/* 
    begin = NULL;
    (&begin, elem);
    ft_lstadd_back(&begin, elem2);
    ft_lstadd_back(&begin, elem3);
    ft_lstadd_back(&begin, elem4);
    while (begin)
    {
        ft_print_result(begin);
        begin = begin->next;
    }

*/

//////    ft_lstadd_front

/*
int main(void)
{
	t_list *addl =ft_lstnew("world");
    t_list *lst_1 = ft_lstnew("Hello");
    printf("lst_1 content: %s\n", (char *)lst_1->content);

    t_list *new_1 = ft_lstnew("world !");
    printf("new_1 content: %s\n", (char *)new_1->content);

    ft_lstadd_front(&lst_1, new_1);
    printf("after adding new, lst_1 content: %s\n", (char *)lst_1->content);
	int count =0;
	ft_lstadd_front(&addl, lst_1);
	while (addl != NULL)
    {
        addl = addl->next;
		printf("with loop: %s\n", (char *)addl->content);
        count++;
    }
} */


/////////    ft_lstclear
/*
static void	ft_del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;

	list1 = ft_lstnew(ft_strdup("abcde"));
	list2 = ft_lstnew(ft_strdup("12345"));
	list3 = ft_lstnew(ft_strdup("!@#$"));
	list1->next = list2;
	list2->next = list3;

	ft_lstclear(&list1, &ft_del);
}
*/

///////  ft_lstdelone
/*
static void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*list;

	list = ft_lstnew(ft_strdup("abcde"));
	ft_lstdelone(list, &del);
}
*/

////////  ft_lstnew
/*
#include <stdio.h>

int main(void)
{
    t_list *new_1 = ft_lstnew("Hello, World!");
    printf("%s\n", (char *)new_1->content);

    t_list *new_2 = ft_lstnew(NULL);
    printf("%s\n", (char *)new_2->content);

    t_list *new_3 = ft_lstnew("123478");
    printf("%s\n", (char *)new_3->content);
}
*/


/////   ft_lstsize
/*
#include <stdio.h>

int main(void)
{
    t_list *lst_1 = ft_lstnew("Hello");
    t_list *lst_2 = ft_lstnew("world");
    printf("list length: %d\n", ft_lstsize(lst_1));
    ft_lstadd_front(&lst_2, lst_1);
    printf("list length: %d\n", ft_lstsize(lst_2));
    
}*/


//////   ft_memchr
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str = "1294567r";
	int c = 114;
	
	printf("from lib function: %s\n", memchr(str, c, 15));
	printf("from ft function: %s\n", ft_memchr(str, c, 15));
}
*/


////////   ft_memcmp
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
    char *dst = "18123458";
	char *src = "18\\23448";
	int n = 9;
	printf("dst: %s\n", dst);
	printf("src: %s\n", src);
    printf("after ft strncmp: %d\n", ft_memcmp(dst, src, n));
	printf("after lib strncmp: %d\n", memcmp(dst, src, n));
}
*/


///////  ft_memcpy
/*
#include <stdio.h>
#include <string.h>

int main (void)
{
	// memcpy
	char dst[] = "123456789";
	char src[] = "abcd";
	int n = 3;
	printf("dst: %s\n", dst);
	printf("src: %s\n", src);
	printf("after ft memcpy: %s\n", ft_memcpy(dst, src, n));
	printf("after lib memcpy: %s\n", memcpy(dst, src, n));
}
*/


/////////  ft_memmove
/*
#include <stdio.h>
#include <string.h>

int main (void)
{
	// memcpy
	char dst[] = "1234";
	char src[] = "abcd";
	int n = 2;
	printf("dst: %s\n", dst);
	printf("src: %s\n", src);
	printf("after ft memmove: %s\n", ft_memmove(dst, src, n));
	printf("after lib memmove: %s\n", memmove(dst, src, n));
} */


////////  ft_memset
/*
 *
#include <stdio.h>
#include <string.h>
int main(void)
{
	// memset
	char b[] = "-1233456789";
	int len = 4;
	printf("main string: %s\n", b);
	printf("lib memset: %s\n", memset(b, 'Z', len));
	printf("ft memset: %s\n", ft_memset(b, 'u', len));
}
*/

///////  ft_putchar_fd
/*
#include <fcntl.h>
int main(void)
{
	char c;
	int file;

	c = 'R';
	file = open("putchar_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putchar_fd(c, file);
	close(file);
    
    c = 'D';
    ft_putchar_fd(c, 1);

    return (0);
}
*/


/////////  ft_putendl_fd
/*

#include <fcntl.h>
int main(void)
{
	char *s = "abcDEF";
	int file;

	file = open("putendl_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd(s, file);
	close(file);
    
    s = "12345ERT";
    ft_putendl_fd(s, 1);

    return (0);
}
*/

////////  ft_putnbr_fd
/*
//ft_putnbr(-2147483648);

#include <fcntl.h>
int main(void)
{
	int	n = 1232423;
	int file;

	file = open("putnbr_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putnbr_fd(n, file);
	close(file);
    
    n = 0253411;
    ft_putnbr_fd(n, 2);

    return (0);
}

*/

/////////  ft_putstr_fd
/*

#include <fcntl.h>
int main(void)
{
	char *s = "abcDEF";
	int file;

	file = open("putstr_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd(s, file);
	close(file);
    
    s = "12345ERT";
    ft_putstr_fd(s, 1);

    return (0);
}
*/


////////////  ft_split
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char **array = ft_split("a123a456a789a012a12a", '1');
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", array[i]);
	}

	//printf("%ld\n", get_word_len("a123a456a7894a012a12a", 'x'));
}
*/

/////////  ft_strchr
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	//char s[] = "teste";

	printf("from lib function: %s\n", strchr("", '\0'));
	printf("from ft function: %s\n", ft_strchr("", '\0'));
}
*/


/////////  ft_strdup
/*

#include <stdio.h>

int main(void)
{
	char *s1 = "eretert";

	printf("%s\n", ft_strdup(s1));
}
*/


////////  ft_striteri
/*
#include <ctype.h>
#include <stdio.h>
void ftuplow(unsigned int index, char *ch)
{
    if (index % 2 != 0)
	{
        *ch = toupper(*ch);
	}
	else
    	*ch = tolower(*ch);		
}

int main(void)
{
char str[] = "ABCDEFGHIJKL";
ft_striteri(str, ftuplow);
printf("%s\n", str);

char str1[] = "lmnopqrstuv";
ft_striteri(str1, ftuplow);
printf("%s\n", str1);

} 
*/



//////  ft_strjoin
/*
#include<stdio.h>
int main()
{
	char	s1[] = "abcdef";
	char s2[] = "ghigklm";

	printf("%s\n", ft_strjoin(s1, s2));
}
*/


/////////   ft_strlcat
/*

#include <string.h>
#include <stdio.h>

int	main(void)
{
	char dst[] = "";
	char src[] = "abcd";

	size_t liblen= strlcat(dst, src, sizeof(dst));
	
	printf("lib length copied: %zu\n", liblen);
	printf("lib copied string: %s\n\n", dst);

	char dst1[] = "";
	char src1[] = "abcd";

	int ftlen = ft_strlcat(dst1, src1, sizeof(dst1));
	printf("ft length: %d\n", ftlen);
	printf("ft copied string: %s\n", dst1);
}
*/



/////////   ft_strlcpy
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char dst[20];
	char src[] = "abcdefghi";

	int liblen= strlcpy(dst, src, sizeof(dst));
	int ftlen = ft_strlcpy(dst, src, sizeof(dst));
	printf("lib length copied: %d\n", liblen);
	printf("lib copied string: %s\n\n", dst);

	printf("ft length: %d\n", ftlen);
	printf("ft copied string: %s\n", dst);
}
*/

///////  ft_strlen
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	// strlen
	char s11[] = "123456789";
	printf("strlen: %d\n", ft_strlen(s11));
}
*/



////////// ft_strmapi
/*
#include <stdio.h>
#include <ctype.h>
char ftcheck(unsigned int i, char c)
{
   if (i == 0 || i == 4)
    //printf("My inner function: index = %d and %c\n", i, str);
    return c - 32;
   else
    return '\t';
}

char ftupper(unsigned int i, char c)
{
    if (i % 2 == 0)
        return toupper(c);
    else
        return tolower(c);
}

int main()
{
char str[10] = "hello";
printf("The result is %s\n", str);
char *result = ft_strmapi(str, ftcheck);
printf("The result is %s\n", result);

char str1[10] = "cat.";
printf("The result is %s\n", str1);
char *result1 = ft_strmapi(str1, ftupper);
printf("The result is %s\n", result1);
return 0;
}
*/


//////// ft_strncmp
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
    char *dst = "18123458";
	char *src = "18123448";
	int n = 9;
	printf("dst: %s\n", dst);
	printf("src: %s\n", src);
    printf("after ft strncmp: %d\n", ft_strncmp(dst, src, n));
	printf("after lib strncmp: %d\n", strncmp(dst, src, n));
}
*/


////////// ft_strnstr
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *haystack = "abcdefghijkl";
	char *needle = "def";
	//size_t c = 0;

	printf("from lib function : %s\n", strnstr(haystack, needle, 5));
	printf("from ft function: %s", ft_strnstr(haystack, needle, 5));
	
}
*/



////////  ft_strrchr
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	//char s[] = "abcdefgh123456e";

	printf("from lib function: %s\n", strrchr("npe y ceparlos", 'n'));
	printf("from ft function: %s\n", ft_strrchr("npe y ceparlos", 'n'));

	//if (*str == (char)c)
	//{
	//	return (str);
	//}
}
*/


////////  ft_strtrim
/*
#include <stdio.h>

int main(void)
{
	char	*s = "abcdefaeghaeb";
	char	*set = "aeb";
	
	printf("trimmed string: %s", ft_strtrim(s, set));
}
*/


//////// ft_substr
/*
#include<stdio.h>
int main()
{
	char	s1[] = "hola";

	printf("%s\n", ft_substr(s1, 0, 18446744073709551615));
}
*/

///////   ft_tolower
/* 
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	printf("from ft: %d\n", ft_tolower('$'));
	printf("from lib: %d\n", tolower('$'));
}
*/


//////  ft_toupper
/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	printf("from ft: %d\n", ft_toupper('$'));
	printf("from lib: %d\n", toupper('$'));
}
*/