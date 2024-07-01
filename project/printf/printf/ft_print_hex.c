/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:24:35 by shachowd          #+#    #+#             */
/*   Updated: 2024/07/01 12:47:34 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	ft_putchar_fd(char c)
{
	return (write(1, &c, 1));
}

int	ft_error_w(int print_count, int write_return)
{
	if (print_count < 0 || write_return < 0)
		return (-1);
	else
		return (print_count + write_return);
}

int ft_print_hex(unsigned int n, const char format)
{
  
    int print_len;

    print_len = 0;
    if (n >= 16)
    {
        print_len = ft_print_hex(n / 16, format);
        if (print_len == -1)
            return (-1);
        print_len = ft_print_hex(n % 16, format);
        if (print_len == -1)
            return (-1);
        return (print_len);
    }
    else
    {
        if (n < 10)
        {
            print_len = ft_printchar(n + '0');
            return (print_len);
        }
        else
        {
            if (format == 'x')
            {
                print_len = ft_printchar(n - 10 + 'a');
                return (print_len);
            }
            else if (format == 'X')
            {
                print_len  = ft_printchar(n - 10 + 'A');
                return (print_len);
            }
        }
    } 

     /* int	p;

	p = 0;
	if (n >= 16)
	{
		p = ft_error_w(p, ft_print_hex(n / 16, format));
		if (p == -1)
			return (-1);
		p = ft_error_w(p, ft_print_hex(n % 16, format));
		if (p == -1)
			return (-1);
		return (p);
	}
	else
	{
		if (n < 10)
			return (ft_error_w(p, ft_putchar_fd(n + '0')));
		else
		{
			if (format == 'X')
				return (ft_error_w(p, ft_putchar_fd(n - 10 + 'A')));
			else
				return (ft_error_w(p, ft_putchar_fd(n - 10 + 'a')));
		}
	}
   */
}
