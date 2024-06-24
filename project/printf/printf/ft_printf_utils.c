/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:41:26 by shachowd          #+#    #+#             */
/*   Updated: 2024/06/24 15:26:31 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

ft_putchar;
ft_putchar_fd;
ft_putstr;
ft_putnbr;
ft_putnbr_fd;

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}