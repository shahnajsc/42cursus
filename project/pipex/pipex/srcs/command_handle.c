/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:43:43 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/22 17:51:06 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	error_handle_execv(char *cmd, char *cmd_path)
{
	if (ft_strchr(cmd, '/') && !access(cmd, X_OK))
		error_return(cmd, "Is a directory", 126);
	else if (!ft_strchr(cmd, '/') && !access(cmd, X_OK))
		error_return(cmd, "command not found", 127);
	else if (access(cmd, X_OK) == -1 && !ft_strchr(cmd, '/'))
		error_return(cmd_path, "", 126);
	else
		error_return(cmd, "", 126);
}

void	execve_init(t_pipex *data, char *cmd)
{
	char	*cmd_path;

	split_command(data, cmd);
	if (!data->splitted_cmd)
		error_return(cmd, "", 127);
	cmd_path = get_command_path(data);
	if (!cmd_path)
		error_return(cmd, "command not found", 127);
	execve(cmd_path, data->splitted_cmd, data->envp);
	error_handle_execv(cmd, cmd_path);
}
