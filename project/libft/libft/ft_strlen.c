/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:13:48 by shachowd          #+#    #+#             */
/*   Updated: 2024/04/29 12:13:38 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	// strlen
	char s11[] = "123456789";
	printf("strlen: %d\n", ft_strlen(s11));
}
*/
