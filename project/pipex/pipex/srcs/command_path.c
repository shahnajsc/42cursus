/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:31:59 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/05 10:56:11 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "pipex.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	**ft_split(char const *s, char c);

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

typedef struct s_pipex
{
    int argc;
    char **argv;
    char **envp;
    int fd[2];
}   t_pipex;

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char )c)
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *s);
// {
// 	size_t	count;

// 	count = 0;
// 	while (s[count] != '\0')
// 	{
// 		count++;
// 	}
// 	return (count);
// }

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	count;

	count = 0;
	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	while (src[count] != '\0' && count < (dstsize -1))
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (ft_strlen(src));
}

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

char **get_envp_paths(t_pipex *data)
{
    char **envp_path;
    int i;

    if (!data->envp)
        return NULL;
    i = 0;
    while (data->envp[i] != NULL)
    {
        if (ft_strncmp(data->envp[i], "PATH=", 5) == 0)
        {
            envp_path = ft_split(data->envp[i] + 5, ':');
            if (!envp_path)
                return (NULL);
            return (envp_path);
        }
        i++;
    } 
    return (NULL);
}
char *combine_path_cmd(char *envp_path, char *cmd)
{
    char *combined_path;
    int len_envp;
    int len_cmd;

    len_envp = ft_strlen(envp_path);
    len_cmd = ft_strlen(cmd);
    combined_path = (char *)malloc(sizeof(char) * (len_envp + len_cmd + 2));
    if (!combined_path)
        return (NULL);
    ft_strlcpy(combined_path, envp_path, len_envp + 1);
    ft_strlcpy(combined_path + len_envp, "/", 2);
    ft_strlcpy(combined_path + len_envp + 1, cmd, len_cmd + 1);
    return (combined_path);    
}

char *get_path_cmd(char **envp_paths, char *cmd)
{
    char *final_path;
    int i;

    i = 0;
    while (envp_paths[i] != NULL)
    {
        final_path = combine_path_cmd(envp_paths[i], cmd);
        if (!final_path)
            return (NULL); //also error check
        if (access(final_path, F_OK) == 0)
            return (final_path);
        i++;
    }
    return(NULL);
}

char *get_command(t_pipex *data, char *cmd)
{
    char **envp_paths;
    char *final_command;

    if (ft_strchr(cmd, '/'))
    {
        if (access(cmd, F_OK) == 0)
        {
            printf("print ffrom get_command cmd: %s\n", cmd);
            return(cmd);
        }
        else
            return (0); // error return 1 end error msg
    }
    envp_paths = get_envp_paths(data);
    final_command = get_path_cmd(envp_paths, cmd);
    free_grid(envp_paths);
    // for (int i = 0; envp_paths[i] != NULL; i++)
    //     free(envp_paths[i]);
    // free(envp_paths); //2d array free???
    printf("print ffrom get_command cinal_command: %s\n", final_command);
    return (final_command);

}

void data_init(t_pipex *data, int argc, char **argv, char **envp)
{
    data->argc = argc;
    data->argv = argv;
    data->envp = envp;
}

int main(int argc, char **argv, char **envp)
{
	t_pipex data;
    (void)argv;
    char *finalpath;

    if (argc != 5)
	{
		printf("Invalid command format\nCorrect format: \"infile cmd1 cmd2 outfile\"\n"); // use ft_printf ***
		return (1);
	}
    data_init(&data, argc, argv, envp);
    // int i= 0;
    // envpath = get_envp_paths(&data);
    // while (envpath[i] != NULL)
    // {
    //     printf("command: %s\n", envpath[i]);
    //     free(envpath[i]);
    //     i++;
    // }
    // free(envpath);
    char *cmd = "grep";
    finalpath = get_command(&data, cmd);
    printf("\nprint ffrom main function final_pathd: %s\n", finalpath);
    //free(finalpath);
    //fd or pipe close?? ***
    return(0);
}
