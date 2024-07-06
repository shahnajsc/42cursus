/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintwst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:03:47 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/06 11:12:33 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft_printf.h"

int main(void)
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