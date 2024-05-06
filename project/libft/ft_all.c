/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:48:42 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/18 11:41:41 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
	return 1;
	}
	else
	{
	return 0;
	}	
}

int ft_isdigit(int c)
{
	if ( c >= '0' && c <= '9')
	{
	return 1;
	}
	else
	{
	return 0;
	}

}

int ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || ( c >= '0' && c <= '9'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int ft_isascii( int c)
{
	if (c >= 0 && c <= 127)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int ft_isprint(int c)
{
	if( c >= 32 && c <= 126)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int ft_strlen(char *s)
{
	int count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

void *ft_memset(char *str, int c, int len)
{
	int count;

	count = 0;
	while (count < len)
	{
		str[count] = (unsigned char)c;
		count++;

	}
	return (str);
}

void ft_bzero(char *s, int n)
{
	int count;

	count = 0;
	while (count < n)
	{
		s[count] = 0;
		count++;
	}
}



#include <stdio.h>
#include <string.h>

int main(void)
{
	//is alpha
	printf("is alpha: %d\n", ft_isalpha('&'));

	// is digit
	printf("is digit: %d\n", ft_isdigit('0'));

	//is alnum
	printf("is alnum: %d\n", ft_isalnum(030));

	// is ascii
	printf("is ascii: %d\n", ft_isascii(220));

	// is printable
	printf("is printable:%d\n" , ft_isprint(20));

	// strlen
	char s11[] = "243ghjhgu   !!!";
	printf("strlen: %d\n", ft_strlen(s11));

	// memset
	char b[] = "-1233456789";
	int len = 4;
	printf("main string: %s\n", b);
	printf("lib memset: %s\n", memset(b, 'Z', len));
	printf("ft memset: %s\n", ft_memset(b, 'u', len));

	//bzero
	char s[] = "1234567899999999999999";
	int n = 4;
	printf("main string: %s\n", s);
	bzero(s, n);
	printf("after lib bzero: %s\n", s);
	ft_bzero(s, n);	
	printf("after ft bzero: %s\n", s);
}

