/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:18:48 by shachowd          #+#    #+#             */
/*   Updated: 2024/05/16 16:53:10 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
	{
		return (0);
	}
	while ((s1[count] == s2[count]) && (s1[count] != '\0') && (count < n - 1))
	{
		count++;
	}
	if (s1[count] == s2[count])
	{
		return (0);
	}
	else
	{
		return ((unsigned char)(s1[count]) - (unsigned char)(s2[count]));
	}
}
