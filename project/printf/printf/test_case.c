/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:30:10 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/08 19:45:11 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft_printf.h"


void	test_simple_text(void)
{
	printf("\n*********** TEST: simple text ***********\n\n");
	int	lib_pf;
	int	ft_pf;

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\tHello!\\n\")\n");
	lib_pf += printf(" Lib\t:\tHello!\n");
	ft_pf += ft_printf(" Ft \t:\tHello!\n");
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (NULL)\n");
	lib_pf += printf(NULL);
	ft_pf += ft_printf(NULL);
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);
	printf("\n_________________________________________\n");
}

void test_percent(void)
{
   	printf("\n***********   TEST: percent(%%)  ***********\n\n");
	int	lib_pf;
	int	ft_pf;

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"%%\")\n");
	lib_pf += printf("\n%");
	ft_pf += ft_printf("\n%");
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);
	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%\\n\")\n");
	lib_pf += printf(" Lib\t:\t%\n");
	ft_pf += ft_printf(" Ft \t:\t%\n");
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);
	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%%%\\n\")\n");
	lib_pf += printf(" Lib\t:\t%%\n");
	ft_pf += ft_printf(" Ft \t:\t%%\n");
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);
	printf("\n_________________________________________\n");
}

void	test_c(void)
{
	printf("\n**************   TEST: 'c'  **************\n\n");
	int	lib_pf;
	int	ft_pf;

	lib_pf = 0;
	ft_pf = 0;
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
	printf("\n**************   TEST: 's'  **************\n\n");
	int	lib_pf;
	int	ft_pf;

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%s\\n\", \"string print test!!\")\n");
	lib_pf += printf(" Lib\t:\t%s\n", "string print test!!");
	ft_pf += ft_printf("  Ft\t:\t%s\n", "string print test!!");
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
	lib_pf += printf(" Lib\t:\tNULL %s NULL\n", NULL);
	ft_pf += ft_printf("  Ft\t:\tNULL %s NULL\n", NULL);
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);
	printf("\n_________________________________________\n");
}

void test_d(void)
{
	printf("\n**************   TEST: 'd'  **************\n\n");
	int lib_pf, ft_pf;

	lib_pf = 0;
	ft_pf = 0;
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
	printf("Test case: (\"\\t%%d\\n\", INT_MIN - INT_MIN)\n");
	lib_pf += printf(" Lib\t:\t%d\n", INT_MIN - INT_MIN);
	ft_pf += ft_printf("  Ft\t:\t%d\n", INT_MIN - INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	
	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%d %%d %%d %%d %%d %%d %%d\\n\", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)\n");
	lib_pf += printf(" Lib\t:\t%d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_pf += ft_printf("  Ft\t:\t%d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	printf("\n_________________________________________\n");

}

void test_i(void)
{
	printf("\n**************   TEST: 'i'  **************\n\n");
	int lib_pf, ft_pf;

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%i\\n\", 42)\n");
	lib_pf += printf(" Lib\t:\t%i\n", 42);
	ft_pf += ft_printf("  Ft\t:\t%i\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\tThe number %%i is visible.\\n\", 5671)\n");
	lib_pf += printf(" Lib\t:\tThe number %i is visible.\n", 5671.345);
	ft_pf += ft_printf("  Ft\t:\tThe number %i is visible.\n", 5671.345);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%i\\n\", INT_MAX)\n");
	lib_pf += printf(" Lib\t:\t%i\n", INT_MAX);
	ft_pf += ft_printf("  Ft\t:\t%i\n", INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%i\\n\", INT_MIN)\n");
	lib_pf += printf(" Lib\t:\t%i\n", INT_MIN);
	ft_pf += ft_printf("  Ft\t:\t%i\n", INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%i\\n\", INT_MIN - INT_MIN)\n");
	lib_pf += printf(" Lib\t:\t%i\n", INT_MIN - INT_MIN);
	ft_pf += ft_printf("  Ft\t:\t%i\n", INT_MIN - INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	
	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%i %%i %%i %%i %%i %%ii %%i\\n\", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)\n");
	lib_pf += printf(" Lib\t:\t%i %i %i %i %i %i %i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_pf += ft_printf("  Ft\t:\t%i %i %i %i %i %i %i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	printf("\n_________________________________________\n");

}

int test_p()
{
	printf("\n**************   TEST: 'p'  **************\n\n");
	int lib_pf, ft_pf;

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%p\\n\", NULL)\n");
	lib_pf += printf(" Lib\t:\t%p\n", NULL);
	ft_pf += ft_printf("  Ft\t:\t%p\n", NULL);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%p\\n\", \"\")\n");
	lib_pf += printf(" Lib\t:\t%p\n", "");
	ft_pf += ft_printf("  Ft\t:\t%p\n", "");
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%p\\n\", (void *)-14523)\n");
	lib_pf += printf(" Lib\t:\t%p\n", (void *)-14523);
	ft_pf += ft_printf("  Ft\t:\t%p\n", (void *)-14523);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t0x%%p\\n\", (void *)ULONG_MAX)\n");
	lib_pf += printf(" Lib\t:\t0x%p\n", (void *)ULONG_MAX);
	ft_pf += ft_printf("  Ft\t:\t0x%p\n", (void *)ULONG_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%pp%%p%%p\\n\", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX)\n");
	lib_pf += printf(" Lib\t:\t%pp%p%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	ft_pf += ft_printf("  Ft\t:\t%pp%p%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	
	printf("\n_________________________________________\n");
}

int test_u()
{
	printf("\n**************   TEST: 'u'  **************\n\n");
	int lib_pf, ft_pf;

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%u\\n\", 0)\n");
	lib_pf += printf(" Lib\t:\t%%u\n", 0);
	ft_pf += ft_printf("  Ft\t:\t%%u\n", 0);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%u\\n\", -10)\n");
	lib_pf += printf(" Lib\t:\t%%u\n", -10);
	ft_pf += ft_printf("  Ft\t:\t%%u\n", -10);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%u\\n\", -200000)\n");
	lib_pf += printf(" Lib\t:\t%%u\n", -200000);
	ft_pf += ft_printf("  Ft\t:\t%%u\n", -200000);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%u\\n\", 10)\n");
	lib_pf += printf(" Lib\t:\t%%u\n", 10);
	ft_pf += ft_printf("  Ft\t:\t%%u\n", 10);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%u\\n\", 10000)\n");
	lib_pf += printf(" Lib\t:\t%%u\n", 10000);
	ft_pf += ft_printf("  Ft\t:\t%%u\n", 10000);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%u %%u %%u %%u %%u %%u %%u\\n\", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)\n");
	lib_pf += printf(" Lib\t:\t%u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_pf += ft_printf("  Ft\t:\t%u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%u%%uu%%u\", 1, 2, -3)\n");
	lib_pf += printf(" Lib\t:\t%u%uu%u", 1, 2, -3);
	ft_pf += ft_printf("  Ft\t:\t%u%uu%u", 1, 2, -3);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
}

int test_x()
{
	printf("\n**************   TEST: 'x'  **************\n\n");
	int lib_pf, ft_pf;

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%x\\n\", 101)\n");
	lib_pf += printf(" Lib\t:\t%x\n", 101);
	ft_pf += ft_printf("  Ft\t:\t%x\n", 101);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%x\\n\", -9)\n");
	lib_pf += printf(" Lib\t:\t%x\n", -9);
	ft_pf += ft_printf("  Ft\t:\t%x\n", -9);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%x\\n\", -10)\n");
	lib_pf += printf(" Lib\t:\t%x\n", -10);
	ft_pf += ft_printf("  Ft\t:\t%x\n", -10);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%x%%xx%%x\\n\", 1, 2, -3)\n");
	lib_pf += printf(" Lib\t:\t%x%xx%x\n", 1, 2, -3);
	ft_pf += ft_printf("  Ft\t:\t%x%xx%x\n", 1, 2, -3);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%x %%x %%x %%x %%x %%x %%x\\n\", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)\n");
	lib_pf += printf(" Lib\t:\t%x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_pf += ft_printf("  Ft\t:\t%x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	
	printf("\n_________________________________________\n");
}

int test_X()
{
	printf("\n**************   TEST: 'X'  **************\n\n");
	int lib_pf, ft_pf;

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%X\\n\", 101)\n");
	lib_pf += printf(" Lib\t:\t%X\n", 101);
	ft_pf += ft_printf("  Ft\t:\t%X\n", 101);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%X\\n\", -9)\n");
	lib_pf += printf(" Lib\t:\t%X\n", -9);
	ft_pf += ft_printf("  Ft\t:\t%X\n", -9);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%X\\n\", -10)\n");
	lib_pf += printf(" Lib\t:\t%X\n", -10);
	ft_pf += ft_printf("  Ft\t:\t%X\n", -10);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	
	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%X%%XX%%X\\n\", 1, 2, -3)\n");
	lib_pf += printf(" Lib\t:\t%X%XX%X\n", 1, 2, -3);
	ft_pf += ft_printf("  Ft\t:\t%X%XX%X\n", 1, 2, -3);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	
	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%X %%X %%X %%X %%X %%X %%X\\n\", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)\n");
	lib_pf += printf(" Lib\t:\t%X %X %X %X %X %X %X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_pf += ft_printf("  Ft\t:\t%X %X %X %X %X %X %X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	
	printf("\n_________________________________________\n");
}

int test_random()
{
	printf("\n**************   TEST: 'random'  **************\n\n");
	int lib_pf, ft_pf;

	lib_pf = 0;
	ft_pf = 0;
	printf("Test case: (\"\\t%%%%%%c%%%%%%s%%%%%%d%%%%%%i%%%%%%u%%%%%%x%%%%%%X%%%%%%%% %%%%%%c%%%%%%s%%%%%%d%%%%%%i%%%%%%u%%%%%%x%%%%%%X%%%%%%%% %%%%%%c%%%%%%s%%%%%%d%%%%%%i%%%%%%u%%%%%%x%%%%%%X%%%% %%c%%%%\", 'A', \"42\", 42, 42 ,42 , 42, 42, 'B', \"-42\", -42, -42 ,-42 ,-42, 42, 'C', \"0\", 0, 0 ,0 ,0, 42, 0)\n");
	lib_pf += printf(" Lib\t:\t%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	ft_pf += ft_printf("  Ft\t:\t%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
	
}

int main()
{
	test_simple_text();
	test_percent();
	test_c();
	test_s();
	test_p();
	test_i();
	test_d();
	test_x();
	test_X();
	test_random();
	
	
}
