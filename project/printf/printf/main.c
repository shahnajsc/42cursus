/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:30:10 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/26 16:40:00 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	test_simple_text(void)
{
	int	lib_pf;
	int	ft_pf;

	lib_pf = 0;
	ft_pf = 0;
	printf("\n*********** TEST: simple text ***********\n\n");
	printf("Testing: (\"\\tHello!\\n\")\n");
	lib_pf += printf(" Lib\t:\tHello!\n");
	ft_pf += ft_printf(" Ft \t:\tHello!\n");
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);
}

void test_percent(void)
{
    int	lib_pf;
	int	ft_pf;

	lib_pf = 0;
	ft_pf = 0;
    printf("\n***********    TEST: percent%%   ***********\n\n");
	printf("Testing: (\"\\t%%%%\\n\")\n");
	lib_pf += printf(" Lib\t:\t%%\n");
	ft_pf += ft_printf(" Ft \t:\t%%\n");
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);
}

void	test_c(void)
{
	int	lib_pf;
	int	ft_pf;

	lib_pf = 0;
	ft_pf = 0;
	printf("\n**************   TEST: 'C'  **************\n\n");
	printf("Testing: (\"\\t%%c\\n\", 'a')\n");
	lib_pf += printf(" Lib\t:\t%c\n", 'a');
	ft_pf += ft_printf("  Ft\t:\t%c\n", 'a');
	printf("Lib count:  %d, FT count:  %d\n\n", lib_pf, ft_pf);
	lib_pf = 0;
	ft_pf = 0;
	printf("Testing: (\"\\tThe character %%c is visible.\\n\", 'x')\n");
	lib_pf += printf(" Lib\t:\tThe character %c is visible.\n", 'x');
	ft_pf += ft_printf("  Ft\t:\tThe character %c is visible.\n", 'x');
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
    lib_pf = 0;
	ft_pf = 0;
    printf("Testing: (\"\\t%%c %%c %%c \\n\", '0', 0, '1')\n");
	lib_pf += printf(" Lib\t:\t%c %c %c \n", '0', 0, '1');
	ft_pf += ft_printf("  Ft\t:\t%c %c %c \n", '0', 0, '1');
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
     lib_pf = 0;
	ft_pf = 0;
    printf("Testing: (\"\\t%%c %%c %%c \\n\", 1, 'A', '3')\n");
	lib_pf += printf(" Lib\t:\t%c %c %c \n", 1, 'A', '3');
	ft_pf += ft_printf("  Ft\t:\t%c %c %c \n", 1, 'A', '3');
	printf("Printf = %d, ft_printf = %d\n\n", lib_pf, ft_pf);
}

int main()
{
	//test_simple_text();
    //test_percent();
    //test_c();

	printf(" Lib %d\n", "a123456"); // undefined
	ft_printf(" Ft %d\n", "a123456");
}
