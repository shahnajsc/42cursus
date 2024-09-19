/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:25:12 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/19 14:55:17 by shachowd         ###   ########.fr       */
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
	ptr = NULL;
} 
char *skip_empty_str(char *cmd)
{
	char *cleaned_str;
	char *temp;
	int 	len;

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
	return(cleaned_str);
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
	while (*cmd && *cmd != 34 && *cmd != 39 && *cmd != 32)
	{
		if (*cmd && *cmd != 34 && *cmd != 39 && *cmd == 92 )
			cmd = cmd+2;
		else
			cmd++;
	}
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
char *get_part_cmd(char *start, char *end, int len)
{
	char *part_cmd;
	char value;
	int i;

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

char **get_splitted_command(char *cmd, char **splitted_cmd, int word_count, int index)
{
	char *start;
	char *end;
	int len;
	
	while (++index < word_count)
	{
		while (*cmd && *cmd == 32)
			cmd++;
		start = cmd;
		if (*cmd && (*cmd == 34 || *cmd == 39 ))
			end = cmd = quoted_word(cmd);
		else if (*cmd && *cmd != 32)
			end = cmd = normal_word(cmd);
		len = get_cmd_len(start, end);
		splitted_cmd[index] = get_part_cmd(start, end, len);
		if (!splitted_cmd)
		{
			free_grid(splitted_cmd);
			return (NULL);
		}	
	}
	splitted_cmd[index] = NULL;
	return (splitted_cmd);
}
char **split_command(char *cmd)
{
	char **splitted_cmd;
	int word_count;
	char *cleaned_cmd;
	
	if (!cmd)
		return (NULL);
	cleaned_cmd = skip_empty_str(cmd);
	word_count = count_words(cleaned_cmd);
	printf("from word count %d\n", word_count);
	splitted_cmd = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!splitted_cmd)
		return (NULL); // error msg?
	splitted_cmd = get_splitted_command(cleaned_cmd, splitted_cmd, word_count, -1);
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
	
    if (argc >= 2)
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
	printf("cleaned str: %s \n", skip_empty_str(argv[1]));
	printf("\n");
}