/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:50:05 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/18 14:31:11 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>

char	*skip_empty_str(char *cmd)
{
	char	*cleaned_str;
	char	*temp;
	int		len;

	len = strlen(cmd); //ft_strlen(cmd);
	cleaned_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!cleaned_str)
		return (NULL);
	temp = cleaned_str;
	while (*cmd)
	{
		if ((*cmd == 34 && *(cmd + 1) == 34) || (*cmd == 39 && *(cmd + 1) == 39))
		{
			cmd = cmd + 2;
		}
		else
		{
			*temp = *cmd;
			temp++;
			cmd++;
		}
	}
	*temp = '\0';
	return (cleaned_str);
}

int	main(int argc, char **argv)
{
	int i;
	
	i = 1;
	while (i < argc)
	{
		printf("argv[%d]: %s\n", i, skip_empty_str(argv[i]));
		i++;
	}
	return (0);
}