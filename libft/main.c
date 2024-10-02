/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:54:35 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/20 15:02:54 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// /////   ft_atoi 

/*
int main(void)
{
	printf("+46: %d - %d\n", ft_atoi("+46"), atoi("+46"));
	printf("a+47: %d - %d\n", ft_atoi("a+47"), atoi("a+47"));
	printf("   +48: %d - %d\n", ft_atoi("   +48"), atoi("   +48"));
	printf("49: %d - %d\n", ft_atoi("\t\n\r\v\f +48"), atoi("\t\n\r\v\f +48"));
	printf("50: %d - %d\n", ft_atoi("\016 50"), atoi("\016 50"));
	printf("empty string: %d - %d\n", ft_atoi(""), atoi(""));
	printf("INT_MAX: %d - %d\n", ft_atoi("2147483647"), atoi("2147483647"));
	printf("INT_MAX + 1: %d - %d\n", ft_atoi("2147483648"), atoi("2147483648"));
	printf("INT_MIN: %d - %d\n", ft_atoi("-2147483648"), atoi("-2147483648"));
	printf("INT_MIN - 1: %d - %d\n", ft_atoi("-2147483649"), atoi("-2147483649"));
	printf("Giant: %d - %d\n", ft_atoi("666666666666"), atoi("666666666666"));
	printf("Giant: %d - %d\n", ft_atoi("666666666666666"), atoi("666666666666666"));
	printf("Giant: %d - %d\n", ft_atoi("666666666666666666"),
			atoi("666666666666666666"));
	printf("Giant: %d - %d\n", ft_atoi("666666666666666666666"),
			atoi("666666666666666666666"));
	printf("-Giant: %d - %d\n", ft_atoi("-6666666666666666666666666666666"),
			atoi("-6666666666666666666666666666666"));
printf("-Giant: %d - %d\n", ft_atoi("-2147483648") + 1,
			atoi("-2147483648") + 1);

if ((ft_atoi("-2147483649")) == 0)
{
	printf(" under flow ");
}
if ((ft_atoi("-2147483649")) == -1)
{
	printf(" overflow ");
}
else
	printf(" no way ");
	// }
}
*/

//////////ft_bzero
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "abcdefghijk";
	int n = 4;
	char s2[] = "abcdefghijk";
	
	printf("main string: %s\n", s);
	bzero(s, n);
	printf("after lib bzero: %s\n", s);
	ft_bzero(s2, n);	
	printf("after ft bzero: %s\n", s);


	//char	miau[] = {"Meowzi"};
	//char	miau2[] = {"Meowzi"};
	//ft_bzero(miau, 1);
	//bzero(miau2, 1);
	//printf("s = Meowzi: %s - %s\n", &miau[1], &miau2[1]);
	//bzero(NULL, 1);
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

	char	xyz[] = {"XYZZY"};
	
	printf("Z: %s - %s\n", ft_memchr(xyz, 'Z', 5), memchr(xyz, 'Z', 5));
	
// segfault condition
	printf("segfault from lib function 1: %s\n", memchr(NULL, 'Z', 1));
	printf("segfault from ft function 1: %s\n",ft_memchr(NULL, 'Z', 1));
	printf("segfault from lib function 0: %s\n", memchr(NULL, 'Z', 0));
	printf("segfault from ft function 0: %s\n",ft_memchr(NULL, 'Z', 0));

	// these tests are not working
	//int memchr_tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	int memchr_tab[7] = {65, 66, 67, 153, 69, 70, 71};
	unsigned char	*memchr_a = (unsigned char *) ft_memchr(memchr_tab, 69, 7);
	unsigned char	*memchr_b = (unsigned char *) memchr(memchr_tab, 69, 7);
	printf("%s - %s\n", (unsigned char *) memchr_a, (unsigned char *) memchr_b);
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


	char	woop[] = {"WoopWoop"};
	char	abc_a[] = {"abcdef"};
	char	abc_b[] = {"abcdef"};
	printf("equal: %i : %i\n", ft_memcmp(abc_a, abc_b, 6), memcmp(abc_a, abc_b, 6));
	printf("unequal %i : %i\n", ft_memcmp(abc_a, woop, 6), memcmp(abc_a, woop, 6));
	printf("unequal %i : %i\n", ft_memcmp(woop, abc_a, 6), memcmp(woop, abc_a, 6));
	printf("NULL: %i : %i\n", ft_memcmp(NULL, abc_b, 0), memcmp(NULL, abc_b, 0));
	printf("NULL: %i : %i\n", ft_memcmp(abc_a, NULL, 0), memcmp(abc_a, NULL, 0));
	printf("NULL: %i : %i\n", ft_memcmp(NULL, NULL, 0), memcmp(NULL, NULL, 0));
// segfault conditions
//	memcmp(abc_a, NULL, 1);
//	memcmp(NULL, abc_a, 1);
//	memcmp(NULL, NULL, 1);
//	ft_memcmp(abc_a, NULL, 1);
//	ft_memcmp(NULL, abc_a, 1);
//	ft_memcmp(NULL, NULL, 1);
}
*/


///////  ft_memcpy
/*
#include <stdio.h>
#include <string.h>

int main (void)
{
	char dst[] = "123456789";
	char dst2[] = "123456789";
	char src[] = "abcd";
	int n = 3;
	printf("dst: %s\n", dst);
	printf("src: %s\n", src);
	//printf("after lib memcpy: %s\n", memcpy(dst2, src, n));
	printf("after ft memcpy: %s\n", ft_memcpy(dst, src, n));
	printf("after lib memcpy: %s\n", memcpy(dst2, src, n));


	char	woop[] = {"WoopWoop"};
	char	abc_a[] = {"abcdef"};
	char	abc_b[] = {"abcdef"};
	
	ft_memcpy(abc_a, woop, 3);
	memcpy(abc_b, woop, 3);
	printf("Woop->abc: %s - %s\n", abc_a, abc_b);
}
*/


/////////  ft_memmove
/*
#include <stdio.h>
#include <string.h>

int main (void)
{
	char dst[] = "12345678";
	char dst2[] = "12345678";
	char src[] = "ab";
	int n = 2;
	printf("dst: %s\n", dst);
	printf("src: %s\n", src);
	printf("after lib memmove: %s\n", memmove(dst, src, n));
	printf("after ft memmove: %s\n", ft_memmove(dst2, src, n));
	


	char	abc_a[] = {"abcdef"};
	char	abc_b[] = {"abcdef"};
	char	xyz[] = {"XYZZY"};

	ft_memmove(abc_a, xyz, 3);
	memmove(abc_b, xyz, 3);
//	memmove(NULL, xyz, 3);   
	printf("Xyz->abc: %s - %s\n", abc_a, abc_b);
	ft_memmove(&abc_a[2], abc_a, 4);
	memmove(&abc_b[2], abc_b, 4);
	printf("abc->abc: %s - %s\n", abc_a, abc_b);
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

	char	woop[] = {""};
	//char	woop2[] = {"WoopNoop"};

	//printf("b = WoopWoop: %s - %s\n", ft_memset(woop, 90, 3), memset(woop, 90, 3));
	//printf("b = WoopWoop: %s - %s\n", ft_memset(woop2, 92, 4), memset(woop2, 92, 4));
	printf("null pointer ft : %s\n", ft_memset(woop, 90, 3));
	printf("null pointer lib: %s\n", memset(woop, 90, 3));
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
	//char s[] = "abcdefgh123456e";

	printf("from lib function: %s\n", strrchr("npe y ceparlos", 'n'));
	printf("from ft function: %s\n", ft_strrchr("npe y ceparlos", 'n'));

	char	xyz[] = {"XYZZY"};
	printf("Z: %s - %s\n", ft_strrchr(xyz, 'Z'), strrchr(xyz, 'Z'));
	
	// segfault on null pointer
	printf("segfault %s\n", strrchr("", 'Z'));
	printf("segfault %s\n", ft_strrchr("", 'Z'));
	//strrchr(NULL, 4);
	//ft_strrchr(NULL, 4);
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
	char src[] = "";
	
	size_t liblen= strlcat(dst, src, 4);
	
	printf("lib length copied: %zu\n", liblen);
	printf("lib copied string: %s\n\n", dst);

	char dst1[] = "";
	char src1[] = "";

	int ftlen = ft_strlcat(dst1, src1, 4);
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
	char dst[20] = "12345";
	char dst2[20] = "12345";
	char src[] = "";
	char src2[] = "";

	int liblen= strlcpy(dst, src, 0);
	int ftlen = ft_strlcpy(dst2, src2, 0);
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



	char	woop[] = {"WoopWoop"};
	char	abc_a[] = {"abcdef"};
	char	abc_b[] = {"abcdef"};
	//char	xyz[] = {"XYZZY"};
	
	printf("equal: %i : %i\n", ft_strncmp(abc_a, abc_b, 6), strncmp(abc_a, abc_b, 6));
	printf("unequal %i : %i\n", ft_strncmp(abc_a, woop, 6), strncmp(abc_a, woop, 6));
	printf("unequal %i : %i\n", ft_strncmp(woop, abc_a, 6), strncmp(woop, abc_a, 6));
	printf("unsigned char: %i : %i\n", ft_strncmp("test\200", "test\0", 6), 
			strncmp("test\200", "test\0", 6));
	printf("s1==NULL, size==0: %i : %i\n", ft_strncmp(NULL, "lol", 0), 
			strncmp(NULL, "lol", 0));
	printf("s2==NULL, size==0: %i : %i\n", ft_strncmp("lol", NULL,  0), 
			strncmp("lol", NULL, 0));
	printf("both==NULL, size==0: %i : %i\n", ft_strncmp(NULL, NULL, 0), 
			strncmp(NULL, NULL, 0));
}
*/


////////// ft_strnstr
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("%s\n", strnstr(NULL, "lo", 0));
	printf("%s\n", ft_strnstr(NULL, "lo", 0));

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