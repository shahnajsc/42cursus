/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:30:10 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/01 19:51:13 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>


void	test_simple_text(void)
{
	int	lib_pf;
	int	ft_pf;

	lib_pf = 0;
	ft_pf = 0;
	printf("\n*********** TEST: simple text ***********\n\n");
	printf("Test case: (\"\\tHello!\\n\")\n");
	lib_pf += printf(" Lib\t:\tHello!\n");
	ft_pf += ft_printf(" Ft \t:\tHello!\n");
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);
	printf("\n_________________________________________\n");
}

void test_percent(void)
{
    int	lib_pf;
	int	ft_pf;

	lib_pf = 0;
	ft_pf = 0;
    printf("\n***********   TEST: percent(%%)  ***********\n\n");
	printf("Test case: (\"\\t%%%%\\n\")\n");
	lib_pf += printf(" Lib\t:\t%%\n");
	ft_pf += ft_printf(" Ft \t:\t%%\n");
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);
	printf("\n_________________________________________\n");
}

void	test_c(void)
{
	int	lib_pf;
	int	ft_pf;

	lib_pf = 0;
	ft_pf = 0;
	printf("\n**************   TEST: 'c'  **************\n\n");
	printf("Test case: (\"\\t%%c\\n\", 'a')\n");
	lib_pf += printf(" Lib\t:\t%c\n", 'a');
	ft_pf += ft_printf("  Ft\t:\t%c\n", 'a');
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);
	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\tThe character %%c is visible.\\n\", 'x')\n");
	lib_pf += printf(" Lib\t:\tThe character %c is visible.\n", 'x');
	ft_pf += ft_printf("  Ft\t:\tThe character %c is visible.\n", 'x');
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
    lib_pf = 0;
	ft_pf = 0;
    printf("Test case: (\"\\t%%c %%c %%c \\n\", '0', 0, '1')\n");
	lib_pf += printf(" Lib\t:\t%c %c %c \n", '0', 0, '1');
	ft_pf += ft_printf("  Ft\t:\t%c %c %c \n", '0', 0, '1');
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
     lib_pf = 0;
	ft_pf = 0;
    printf("Test case: (\"\\t%%c %%c %%c \\n\", '1', '2', '3')\n");
	lib_pf += printf(" Lib\t:\t%c %c %c \n", '1', '2', '3');
	ft_pf += ft_printf("  Ft\t:\t%c %c %c \n", '1', '2', '3');
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	 lib_pf = 0;
	ft_pf = 0;
    printf("Test case: (\"\\t%%c %%c %%c \\n\", '2', '1', 0)\n");
	lib_pf += printf(" Lib\t:\t%c %c %c \n", '2', '1', 0);
	ft_pf += ft_printf("  Ft\t:\t%c %c %c \n", '2', '1', 0);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	printf("\n_________________________________________\n");
}

void test_s(void)
{
	int	lib_pf;
	int	ft_pf;

	lib_pf = 0;
	ft_pf = 0;
	printf("\n**************   TEST: 's'  **************\n\n");
	printf("Test case: (\"\\t%%s\\n\", \"coucou, ca va?\")\n");
	lib_pf += printf(" Lib\t:\t%s\n", "coucou, ca va?");
	ft_pf += ft_printf("  Ft\t:\t%s\n", "coucou, ca va?");
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);
	
	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%s\\n\", \"\")\n");
	lib_pf += printf(" Lib\t:\t%s\n", "");
	ft_pf += ft_printf("  Ft\t:\t%s\n", "");
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%s %%s \", \"\", \"-\"\\n\")\n");
	lib_pf += printf(" Lib\t:\t %s %s \n", "", "-");
	ft_pf += ft_printf("  Ft\t:\t %s %s \n", "", "-");
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%s %%s\\n\", \" - \", \"\")\n");
	lib_pf += printf(" Lib\t:\t%s %s \n", " - ", "");
	ft_pf += ft_printf("  Ft\t:\t%s %s \n", " - ", "");
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	char *s2 = "1234567";
	printf("Test case: (\"\\t%%s %%s %%s %%s %%s\\n\", \" - \", \"\", \"4\", \"\", s2)\n");
	lib_pf += printf(" Lib\t:\t%s %s %s %s %s\n", " - ", "", "4", "", s2);
	ft_pf += ft_printf("  Ft\t:\t%s %s %s %s %s\n", " - ", "", "4", "", s2);
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%s %%s %%s %%s %%s \\n\", \" - \", \"\", \"4\", \"\", \"2 \")\n");
	lib_pf += printf(" Lib\t:\t%s %s %s %s %s \n", " - ", "", "4", "", "2 ");
	ft_pf += ft_printf("  Ft\t:\t%s %s %s %s %s \n", " - ", "", "4", "", "2 ");
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\tNULL %%s NULL\", NULL)\n");
	//lib_pf += printf(" Lib\t:\tNULL %s NULL\n", NULL);
	//ft_pf += ft_printf("  Ft\t:\tNULL %s NULL\n", NULL);
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);
	printf("\n_________________________________________\n");
}
/*
void test_d(void)
{
	int lib_pf, ft_pf;
	lib_pf = 0;
	ft_pf = 0;
	printf("\n**************   TEST: 'd'  **************\n\n");
	printf("Test case: (\"\\t%%d\\n\", 42)\n");
	lib_pf += printf(" Lib\t:\t%d\n", 42);
	ft_pf += ft_printf("  Ft\t:\t%d\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\tThe number %%d is visible.\\n\", 5671)\n");
	lib_pf += printf(" Lib\t:\tThe number %d is visible.\n", 5671.345);
	ft_pf += ft_printf("  Ft\t:\tThe number %d is visible.\n", 5671.345);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%d\\n\", INT_MAX)\n");
	lib_pf += printf(" Lib\t:\t%d\n", INT_MAX);
	ft_pf += ft_printf("  Ft\t:\t%d\n", INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%d\\n\", INT_MIN)\n");
	lib_pf += printf(" Lib\t:\t%d\n", INT_MIN);
	ft_pf += ft_printf("  Ft\t:\t%d\n", INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%i\\n\", INT_MIN - INT_MIN)\n");
	lib_pf += printf(" Lib\t:\t%i\n", INT_MIN - INT_MIN);
	ft_pf += ft_printf("  Ft\t:\t%i\n", INT_MIN - INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%d %%d %%d %%d %%d %%d %%d\\n\", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)\n");
	lib_pf += printf(" Lib\t:\t%d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_pf += ft_printf("  Ft\t:\t%d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	printf("\n_________________________________________\n");

}
*/


int main()
{
	int lib_pf, ft_pf;

	lib_pf = 0;
	ft_pf = 0;
	printf("\n**************   TEST: 'x'  **************\n\n");
	printf("Test case: (\"\\t%%x\\n\", 101)\n");
	lib_pf += printf(" Lib\t:\t%x\n", 101);
	ft_pf += ft_printf("  Ft\t:\t%x\n", 101);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%x\\n\", 101)\n");
	lib_pf += printf(" Lib\t:\t%x\n", -9);
	ft_pf += ft_printf("  Ft\t:\t%x\n", -9);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%x\\n\", 101)\n");
	lib_pf += printf(" Lib\t:\t%x\n", -10);
	ft_pf += ft_printf("  Ft\t:\t%x\n", -10);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	lib_pf = 0;
	ft_pf = 0;
	lib_pf += printf("%x%xx%x\n", 1, 2, -3);
	ft_pf += ft_printf("%x%xx%x\n", 1, 2, -3);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	printf("\n_________________________________________\n");


}
