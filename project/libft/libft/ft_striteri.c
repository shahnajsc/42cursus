/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:36:30 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/15 12:31:51 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char			*str;
	unsigned int	count;

	str = (char *)s;
	if (str && f)
	{
		count = 0;
		while (str[count])
		{
			(*f)(count, &str[count]);
			count++;
		}
	}
}
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
/*	-Usees external function 'f' as argument to iterate string 's'.
	-Applies 'f' on each character of 's' passed as 
		argument (index & character).
	-Each character is passed by address to 'f', to be
		modified if necessary. 
	-External function: none.
	-Return: None.
*/