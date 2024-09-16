/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:25:12 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/10 17:40:15 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "pipex.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void free_grid(char **ptr)
{
    int i;

    i = 0;
    while (ptr[i] != NULL)
    {
        free(ptr[i]);
        i++;
    }
    free(ptr);
} 

char *quoted_word(char *cmd)
{
	char value;

	value = *cmd;
	cmd++;
	while (*cmd && *cmd != value)
		cmd++;
	if (*cmd != value || *cmd == '\0') // ((cmd[i] && cmd[i] != value) || cmd[i] == '\0')
	{
		//error_return("cmd_split", "cmd", 1);
		printf("\nquootes missing\n");
		exit(1);
	}
	else
		cmd++;
	return (cmd);
}

char *normal_word(char *cmd)
{
	if (*cmd && *cmd != 34 && *cmd != 39 && *cmd == 92 )
		cmd = cmd+2;
	while (*cmd && *cmd != 34 && *cmd != 39 && *cmd != 32)
		cmd++;
	return (cmd);
}

static int count_words(char *cmd)
{
	int count;

	count = 0;
	while (*cmd != '\0')
	{
		while (*cmd && *cmd == 32)
			cmd++;
		if (*cmd && (*cmd == 34 || *cmd == 39 ))
		{
			if (*cmd && *(cmd + 1) && *(cmd + 1) == *cmd)
				cmd = cmd + 2;
			else if (*cmd && *(cmd + 1) && *(cmd + 1) != *cmd)
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
int get_cmd_len(char *start, char *end)
{
	int len;
	char value;

	len = 0;
	value = *start;
	while (start < end)
	{
		if (*start == 34 || *start == 39)// && *start == value)
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
char *get_part_cmd(char *start, char *end)
{
	char *part_cmd;
	int len;
	char value;
	char *temp;

	len = get_cmd_len(start, end);
	part_cmd = (char *)malloc(sizeof(char) * len + 1);
	if (!part_cmd)
		return (NULL);
	temp = part_cmd;
	value = *start;
	while (start < end)
	{
		if (*start == 34 || *start == 39) //&& *start == value)
		{
			start++;
		}
		else if (value != 39 && value != 34 && *start == 32)
			start++;
		else
		{
			if (value != 39 && value != 34 && *start == '\\')
				start++;
			*temp = *start;
			temp++;
			start++;
		}
	}
	*temp = '\0';
	return (part_cmd);	
}

char **get_splitted_command(char *cmd, char **splitted_cmd, int word_count, int index)
{
	char *start;
	char *end;
	
	while (++index < word_count)
	{
		while (*cmd && *cmd == 32)
			cmd++;
		start = cmd;
		while (*cmd && (*cmd == 34 || *cmd == 39 ))
		{
			if (*cmd && *(cmd + 1) && *(cmd + 1) == *cmd)
			{
				cmd = cmd + 2;
			}
			if (*cmd && *(cmd + 1) && *(cmd + 1) != *cmd)
			{
				end = cmd = quoted_word(cmd);
			}
		}
		if (*cmd && *cmd != 32)
		{
			end = cmd = normal_word(cmd);
		}
		splitted_cmd[index] = get_part_cmd(start, end);
		if (!splitted_cmd)
		{
			free_grid(splitted_cmd);
			return (NULL);
		}	
	}
	return (splitted_cmd);
}
char **split_command(char *cmd)
{
	char **splitted_cmd;
	int word_count;
	
	if (!cmd)
		return (NULL);
	word_count = count_words(cmd);
	splitted_cmd = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!splitted_cmd)
		return (NULL); // error msg?
	splitted_cmd = get_splitted_command(cmd, splitted_cmd, word_count, -1);
	if (!splitted_cmd)
	{
		free(splitted_cmd);
		return (NULL); // error msg?
	}
	return (splitted_cmd);
	
}

int main(int argc, char **argv)
{
    char	**splitted_cmd;
	
    if (argc == 2)
    {
        printf("\nfrom main argv1: %s\n", argv[1]);
		printf("counts from main: %d\n\n",  count_words(argv[1]));
		int i= 0;
        splitted_cmd = split_command(argv[1]);
        while (splitted_cmd[i] != NULL)
        {
            printf("command: %s\n", splitted_cmd[i]);
            i++;
        }
    }
	else
    	printf("\nmore arguments\n");
	printf("\n");
}
// static int count_words(char *cmd)
// {
// 	int count;
// 	int i;

// 	count = 0;
// 	i = 0;
// 	while (cmd[i] != '\0')
// 	{
// 		while (cmd[i] && cmd[i] == 32)
// 			i++;
// 		if (cmd[i] && (cmd[i] == 34 || cmd[i] == 39 ))
// 		{
// 			if (cmd[i] && (cmd[i + 1] == cmd[i]))
// 				i = i+2;
// 			else if ((cmd[i + 1] == 34 || cmd[i - 1] == 39) && (cmd[i] != cmd[i - 1]))
// 			{
// 				count++;
// 				i = quoted_word(cmd, i);			
// 			}
// 		}
// 		else if (cmd[i] && cmd[i] != 32)
// 		{
// 			 count++;
// 			 i = normal_word(cmd, i);		
// 		}		
// 	}
// 	return (count);
// } 