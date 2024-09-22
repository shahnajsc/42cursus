/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:58:30 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/22 20:36:03 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/pipex_bonus.h"

char	*skip_empty_str(char *cmd)
{
	char	*cleaned_str;
	char	*temp;
	int		len;

	len = ft_strlen(cmd);
	cleaned_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!cleaned_str)
		return (NULL);
	temp = cleaned_str;
	while (*cmd)
	{
		if ((*cmd == 34 && *(cmd + 1) == 34)
			|| (*cmd == 39 && *(cmd + 1) == 39))
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

char	*quoted_word(char *cmd)
{
	char	value;

	value = *cmd;
	cmd++;
	while (*cmd && *cmd != value)
		cmd++;
	if (*cmd != value || *cmd == '\0')
	{
		error_return(cmd, "", 1);
	}
	else if (*cmd)
		cmd++;
	return (cmd);
}

char	*normal_word(char *cmd)
{
	while (*cmd && *cmd != 34 && *cmd != 39 && *cmd != 32)
	{
		if (*cmd && *cmd != 34 && *cmd != 39 && *cmd == 92)
			cmd = cmd + 2;
		else
			cmd++;
	}
	return (cmd);
}

int	check_white_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != 32 && (str[i] < 9 || str[i] > 13))
			return (0);
		i++;
	}
	return (1);
}