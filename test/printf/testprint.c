/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:33:08 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/21 00:01:46 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{   
    char    *p;

    p = "pointer value";
    printf("%c\n", 'a');
    printf("%s\n", "abcdef123");
    printf("%p\n", p);
    printf("%s\n", p);
    printf("%d\n", 12345);
    printf("%i\n", 12345);
    printf("%u\n", 12345);
    printf("%x\n", 1234567890);
    printf("%X\n", 1234567890);
    printf("%%\n");
    //printf("%c", 'a');


}
