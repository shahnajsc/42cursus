#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../ft_printf/ft_printf.h"

void test_pointer_arithmetic() {
    int array[5] = {10, 20, 30, 40, 50};
    int *ptr = array; // Points to the first element of the array

    // Display original pointer and after some arithmetic operations
    printf("Standard printf (original ptr): %p\n", (void *)ptr);
    ft_printf("ft_printf (original ptr): %p\n", (void *)ptr);

    // Point to the third element
    ptr += 2;
    printf("Standard printf (ptr + 2): %p\n", (void *)ptr);
    ft_printf("ft_printf (ptr + 2): %p\n", (void *)ptr);

    // Point to one past the last element
    ptr = &array[4] + 1;
    printf("Standard printf (end ptr): %p\n", (void *)ptr);
    ft_printf("ft_printf (end ptr): %p\n", (void *)ptr);
}

void test_large_arrays() {
    int *large_array = malloc(sizeof(int) * 1000); // Allocate a large array
    if (large_array == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    // Print address of the first element
    printf("Standard printf (first element): %p\n", (void *)&large_array[0]);
    ft_printf("ft_printf (first element): %p\n", (void *)&large_array[0]);

    // Print address of the middle element
    printf("Standard printf (middle element): %p\n", (void *)&large_array[500]);
    ft_printf("ft_printf (middle element): %p\n", (void *)&large_array[500]);

    // Print address of the last element
    printf("Standard printf (last element): %p\n", (void *)&large_array[999]);
    ft_printf("ft_printf (last element): %p\n", (void *)&large_array[999]);

    free(large_array); // Always remember to free allocated memory
}

int main(void)
{
	// For the % sign
	
	ft_printf("\n------------------------------------------------------------\n");
	ft_printf("For %%: \n");
	ft_printf("Return len when only one percent sign(ft): %d\n", ft_printf("%"));
	printf("Return len when only one percent sign: %d\n", printf("%"));
	ft_printf(". Return len when have two percent sign(ft): %d\n", ft_printf("%%"));
	printf(". Return len when have two percent sign: %d\n", printf("%%"));
	ft_printf(". Return len when have three percent sign(ft): %d\n", ft_printf("%%%"));
	printf(". Return len when have three percent sign: %d\n", printf("%%%"));
	ft_printf(". Return len when have four percent sign(ft): %d\n", ft_printf("%%%%"));
	printf(". Return len when have four percent sign: %d\n", printf("%%%%"));

	/* For some error types  (don't check this as in the project we don't need)
	ft_printf("Return len when only one percent sign(ft): %k\n");
	printf("Return len when only one percent sign: %k\n");
	ft_printf("Return len when only one percent sign(ft): %hjlq\n", ft_printf("%"));
	printf("Return len when only one percent sign: %hjlqtzjjjjj\n", printf("%"));
	*/
	// Will not check printf("c: %c", "") as %c is only charactor but "" is pointer
	ft_printf("\n------------------------------------------------------------\n");
	ft_printf("For %%c: \n");
	ft_printf(". Return len when empty(ft): %d\n", ft_printf("c: %c", '\0'));
	printf(". Return len when empty: %d\n", printf("c: %c", '\0'));
	ft_printf(". Return len when non-visible character(ft): %d\n", ft_printf("c: %c", '\t'));
	printf(". Return len when non-visible character: %d\n", printf("c: %c", '\t'));
	ft_printf(". Return len when string with ''(ft): %d\n", ft_printf("c: %c", 'null'));
	printf(". Return len when string with '': %d\n", printf("c: %c", 'null'));
	ft_printf(". Return len when one charactor(ft): %d\n", ft_printf("c: %c", 48));
	printf(". Return len when one charactor: %d\n", printf("c: %c", 48));
	ft_printf(". Return len when one charactor(ft): %d\n", ft_printf("c: %c", '\\'));
	printf(". Return len when one charactor: %d\n", printf("c: %c", '\\'));

	// Need to mention that, the NULL is not safety enough here. It gives a null pointer
	// but didn't give any valid address. And different system will have different behavious
	// in iMac is fine, just (null), but some other will crash directly
	
	ft_printf("\n------------------------------------------------------------\n");
	char str1[6] = {'H', 'e', 'l', 'l', 'o'};
	char str2[] = {'T', 'e', 's', 't', '\0', 'D', 'a', 't', 'a'};
	char str3[] = "Here is a tab\t finished";
	char str4[5] = {"Hello world."};
	ft_printf("For %%s: \n");
	ft_printf(". Return len when NULL(ft): %d\n", ft_printf("s: %s", NULL));
	printf(". Return len when NULL: %d\n", printf("s: %s", NULL));
	ft_printf(". Return len when null charactor(ft): %d\n", ft_printf("s: %s", ""));
	printf(". Return len when null charactor: %d\n", printf("s: %s", ""));
	ft_printf(". Return len when 1 char(ft): %d\n", ft_printf("s: %s", "a"));
	printf(". Return len when 1 char: %d\n", printf("s: %s", "a"));
	ft_printf(". Return len when string aren't null-terminated(ft): %d\n", ft_printf("s: %s", str1));
	printf(". Return len when string aren't null-terminated: %d\n", printf("s: %s", str1));
	ft_printf(". Return len when string add null inside(ft): %d\n", ft_printf("s: %s", str2));
	printf(". Return len when string add null inside: %d\n", printf("s: %s", str2));
	ft_printf(". Return len when string add tab inside(ft): %d\n", ft_printf("s: %s", str3));
	printf(". Return len when string add tab inside: %d\n", printf("s: %s", str3));
	ft_printf(". Return len when string is too long(ft): %d\n", ft_printf("s: %s", str4));
	printf(". Return len when string is too long: %d\n", printf("s: %s", str4));
	ft_printf(". Return len when string(ft): %d\n", ft_printf("s: %s", "abc%abc"));
	printf(". Return len when string: %d\n", printf("s: %s", "abc%abc"));
	

	ft_printf("\n------------------------------------------------------------\n");
	ft_printf("For %%p: \n");
	int local_point;
	int *heap_var = malloc(sizeof(int));
	void *high_memory_address = (void *)0xFFFFFFFFFFFF;
	ft_printf(". Return len when NULL(ft): %d\n", ft_printf("s: %p", NULL));
	printf(". Return len when NULL: %d\n", printf("s: %p", NULL));
	ft_printf(". Return len when high memory address(ft): %d\n", ft_printf("s: %p", high_memory_address));
	printf(". Return len when high memory address: %d\n", printf("s: %p", high_memory_address));
	ft_printf(". Return len when null charactor(ft): %d\n", ft_printf("s: %p", ""));
	printf(". Return len when null charactor: %d\n", printf("s: %p", ""));
	ft_printf(". Return len when stack variable(ft): %d\n", ft_printf("p: %p", (void *)&local_point));
	printf(". Return len when stack variable: %d\n", printf("p: %p", (void *)&local_point));
	ft_printf(". Return len when heap variable(ft): %d\n", ft_printf("p: %p", (void *)&heap_var));
	printf(". Return len when heap variable: %d\n", printf("p: %p", (void *)&heap_var));
	ft_printf(". Return len when 1 char(ft): %d\n", ft_printf("s: %p", "b"));
	printf(". Return len when 1 char: %d\n", printf("s: %p", "b"));
	printf("\nFor pointer arithmetic and large arrays:\n");
	test_pointer_arithmetic();
	test_large_arrays();
	free(heap_var);
	//ft_printf(". Return len when string(ft): %d\n", ft_printf("s: %p", large_data));
	//printf(". Return len when string: %d\n", printf("s: %p", large_data));

	ft_printf("\n------------------------------------------------------------\n");
	ft_printf("For %%d and %%i: \n");
	ft_printf(". Return len when number is 0(ft): %d\n", ft_printf("d: %d", 0));
	printf(". Return len when number is 0: %d\n", printf("d: %d", 0));
	ft_printf(". Return len when number is 10(ft): %d\n", ft_printf("d: %d", 10));
	printf(". Return len when number is 10: %d\n", printf("d: %d", 10));
	ft_printf(". Return len when number is -10(ft): %d\n", ft_printf("d: %d", -10));
	printf(". Return len when number is -10: %d\n", printf("d: %d", -10));
	ft_printf(". Return len when number is max int(ft): %d\n", ft_printf("d: %d", INT_MAX));
	printf(". Return len when number is max int: %d\n", printf("d: %d", INT_MAX));
	ft_printf(". Return len when number is min int(ft): %d\n", ft_printf("d: %d", INT_MIN));
	printf(". Return len when number is min int: %d\n", printf("d: %d", INT_MIN));
	ft_printf(". Return len when number is max long(ft): %d\n", ft_printf("d: %d", LONG_MAX));
	printf(". Return len when number is max long: %d\n", printf("d: %d", LONG_MAX));
	ft_printf(". Return len when number is min long(ft): %d\n", ft_printf("d: %d", LONG_MIN));
	printf(". Return len when number is min long: %d\n", printf("d: %d", LONG_MIN));

	ft_printf("\n------------------------------------------------------------\n");
	ft_printf("For %%u: \n");
	ft_printf(". Return len when number is 0(ft): %d\n", ft_printf("u: %u", 0));
	printf(". Return len when number is 0: %d\n", printf("u: %u", 0));
	ft_printf(". Return len when number is 10(ft): %d\n", ft_printf("u: %u", 10));
	printf(". Return len when number is 10: %d\n", printf("u: %u", 10));
	ft_printf(". Return len when number is -10(ft): %d\n", ft_printf("u: %u", -10));
	printf(". Return len when number is -10: %d\n", printf("u: %u", -10));
	ft_printf(". Return len when number is max int(ft): %d\n", ft_printf("u: %u", UINT_MAX));
	printf(". Return len when number is max int: %d\n", printf("u: %u", UINT_MAX));
	ft_printf(". Return len when number is min int(ft): %d\n", ft_printf("u: %u", INT_MIN));
	printf(". Return len when number is min int: %d\n", printf("u: %u", INT_MIN));
	ft_printf(". Return len when number is max long(ft): %d\n", ft_printf("u: %u", LONG_MAX));
	printf(". Return len when number is max long: %d\n", printf("u: %u", LONG_MAX));
	ft_printf(". Return len when number is min long(ft): %d\n", ft_printf("u: %u", LONG_MIN));
	printf(". Return len when number is min long: %d\n", printf("u: %u", LONG_MIN));
	ft_printf(". Return len when number is string(ft): %d\n", ft_printf("u: %u", "wow"));
	printf(". Return len when number is string: %d\n", printf("u: %u", "wow"));

	ft_printf("\n------------------------------------------------------------\n");
	ft_printf("For %%x and %%X: \n");
	ft_printf(". Return len when number is 0(ft): %d\n", ft_printf("x: %x", 0));
	printf(". Return len when number is 0: %d\n", printf("x: %x", 0));
	ft_printf(". Return len when number is 10(ft): %d\n", ft_printf("u: %x", 10));
	printf(". Return len when number is 10: %d\n", printf("x: %x", 10));
	ft_printf(". Return len when number is -10(ft): %d\n", ft_printf("x: %x", -10));
	printf(". Return len when number is -10: %d\n", printf("x: %x", -10));
	ft_printf(". Return len when number is 255(ft): %d\n", ft_printf("x: %x", 255));
	printf(". Return len when number is 255: %d\n", printf("x: %x", 255));
	ft_printf(". Return len when number is 256(ft): %d\n", ft_printf("x: %x", 256));
	printf(". Return len when number is 256: %d\n", printf("x: %x", 256));
	ft_printf(". Return len when number is 1024(ft): %d\n", ft_printf("x: %x", 1024));
	printf(". Return len when number is 1024: %d\n", printf("x: %x", 1024));
	ft_printf(". Return len when number is max int(ft): %d\n", ft_printf("x: %x", UINT_MAX));
	printf(". Return len when number is max int: %d\n", printf("x: %x", UINT_MAX));
	ft_printf(". Return len when number is max long(ft): %d\n", ft_printf("x: %x", LONG_MAX));
	printf(". Return len when number is max long: %d\n", printf("x: %x", LONG_MAX));
	ft_printf(". Return len when number is min long(ft): %d\n", ft_printf("x: %x", LONG_MIN));
	printf(". Return len when number is min long: %d\n", printf("x: %x", LONG_MIN));
	ft_printf(". Return len when number is string(ft): %d\n", ft_printf("X: %X", "wow"));
	printf(". Return len when number is string: %d\n", printf("X: %X", "wow"));

	return (0);
}