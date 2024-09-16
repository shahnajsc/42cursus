
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
char	**split_command(char *command);
char	**ft_split(char const *s, char c);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hcount;
	size_t	ncount;
	size_t	s_len;
	char	*hay;

	hay = (char *)haystack;
	if (!haystack && !len)
		return (NULL);
	if (needle[0] == '\0')
		return (hay);
	s_len = ft_strlen(needle);
	hcount = 0;
	while (hay[hcount] != '\0' && hcount < len)
	{
		ncount = 0;
		while (hay[hcount + ncount] != '\0' && needle[ncount] != '\0'
			&& hay[hcount + ncount] == needle[ncount] && hcount + ncount < len)
		{
			ncount++;
		}
		if (ncount == s_len)
			return (hay + hcount);
		hcount++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = 0;
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			return (str);
		}
		str++;
	}
	if (*str == (char)c)
	{
		return (str);
	}
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	unsigned int	len;
	unsigned int	count;
	char			*ptr;

	count = 0;
	len = ft_strlen(src);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
	{
		return (NULL);
	}
	while (count < len)
	{
		ptr[count] = src[count];
		count++;
	}
	ptr[count] = '\0';
	return (ptr);
}

static char	**find_envp_path(char **envp, char **command)
{
	while (*envp && !ft_strnstr(*envp, "PATH=", 5))
		envp++;
	if (!*envp)
		return NULL;
	return (ft_split(*envp + 5, ':'));
}

static char	*join_command_path(char *envp_path, char *command)
{
	char	*command_dir;
	char	*command_path;

	command_dir = ft_strjoin(envp_path, "/");
	if (!command_dir)
		return (NULL);
	command_path = ft_strjoin(command_dir, command);
	free(command_dir);
	return (command_path);
}

static char	*get_command_path(char **envp_paths, char *command)
{
	char	*command_path;

    printf("from the function: %s\n", command);
	while (*envp_paths)
	{
		command_path = join_command_path(*(envp_paths++), command);
		if (!command_path || access(command_path, F_OK) == 0)
			return (command_path);
		free(command_path);
	}
	return (NULL);
}

char	*find_command_path(char **envp, char **splitted_cmd)
{
	char	**envp_paths;
	char	*command_path;

	if (ft_strchr(*splitted_cmd, '/'))
	{
		if (access(*splitted_cmd, F_OK) == 0)
			return (ft_strdup(*splitted_cmd));
	}
	envp_paths = find_envp_path(envp, splitted_cmd);
	command_path = get_command_path(envp_paths, *splitted_cmd);
	return (command_path);
}


int main(int argc, char **argv, char **envp)
{
    char	**splitted_cmd;
	char	*command_path;

    if (argc == 5)
    {
        int i= 0;
        int j= 0;
        splitted_cmd = split_command(argv[2]);
        while (splitted_cmd[i] != NULL)
        {
            printf("command: %s\n", splitted_cmd[i]);
            i++;
        }
        
	    if (!splitted_cmd)
		exit(1);
	    command_path = find_command_path(envp, splitted_cmd);
	    printf("path %s\n", command_path);
    }
    printf("\n");
}
