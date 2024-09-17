/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:25:12 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/17 11:39:42 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static int	count_words(char *cmd)
{
	int	count;

	count = 0;
	while (*cmd != '\0')
	{
		while (*cmd && *cmd == 32)
			cmd++;
		if (*cmd && (*cmd == 34 || *cmd == 39))
		{
			if (*cmd && *(cmd + 1) && *(cmd + 1) == *cmd)
				cmd = cmd + 2;
			else if (*cmd && *(cmd + 1) != *cmd)
			{
				count++;
				cmd = quoted_word(cmd);
			}
		}
		else if (*cmd && *cmd != 32)
		{
			count++;
			cmd = normal_word(cmd);
		}
	}
	return (count);
}

static int	get_cmd_len(char *start, char *end)
{
	int		len;
	char	value;

	len = 0;
	value = *start;
	while (start < end)
	{
		if (*start == 34 || *start == 39) // && *start == value)
			start++;
		else if (value != 39 && value != 34 && *start == 32)
			start++;
		else
		{
			if (value != 39 && value != 34 && *start == '\\')
				start++;
			len++;
			start++;
		}
	}
	return (len);
}

static char	*get_part_cmd(char *start, char *end, int len)
{
	char	*part_cmd;
	char	value;
	int		i;

	part_cmd = (char *)malloc(sizeof(char) * len + 1);
	if (!part_cmd)
		return (NULL);
	value = *start;
	i = 0;
	while (start < end)
	{
		if (*start == 34 || *start == 39) //&& *start == value)
			start++;
		else if (value != 39 && value != 34 && *start == 32)
			start++;
		else
		{
			if (value != 39 && value != 34 && *start == '\\')
				start++;
			part_cmd[i++] = *start;
			start++;
		}
	}
	part_cmd[i] = '\0';
	return (part_cmd);
}

static char	**get_splitted_command(char *cmd, char **splitted_cmd, int word_count, int index)
{
	char	*start;
	char	*end;
	int		len;

	while (++index < word_count)
	{
		while (*cmd && *cmd == 32)
			cmd++;
		start = cmd;
		if (*cmd && (*cmd == 34 || *cmd == 39))
			end = cmd = quoted_word(cmd);
		else if (*cmd && *cmd != 32)
			end = cmd = normal_word(cmd);
		len = get_cmd_len(start, end);
		splitted_cmd[index] = get_part_cmd(start, end, len);
		if (!splitted_cmd[index])
		{
			free_grid(splitted_cmd);
			return (NULL);
		}	
	}
	splitted_cmd[index] = NULL;
	return (splitted_cmd);
}

void	split_command(t_pipex *data, char *cmd)
{
	int		word_count;
	char	*cleaned_cmd;

	if (!cmd || cmd[0] == '\0' || check_white_spaces(cmd))
		error_return(cmd, 127);
	cleaned_cmd = skip_empty_str(cmd);
	word_count = count_words(cleaned_cmd);
	data->splitted_cmd = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!data->splitted_cmd)
		error_return("malloc()", 1); // malloc or  split_command()?
	data->splitted_cmd = get_splitted_command(cleaned_cmd, data->splitted_cmd, word_count, -1);
	if (!data->splitted_cmd)
		error_return("split_command()", 1);
	//return (data->splitted_cmd);	
}
