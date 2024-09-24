/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:43:43 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/24 17:54:11 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	error_handle_execv(t_pipex *data, char *cmd, char *cmd_path)
{
	// if (cmd)
	// 	free(cmd);
	// if (cmd_path)
	// 	free(cmd_path);
	if (ft_strchr(cmd, '/') && !access(cmd, X_OK))
		error_return(data, cmd, "Is a directory", 126);
	else if (!ft_strchr(cmd, '/') && !access(cmd, X_OK))
		error_return(data, cmd, "command not foundtttt", 127);
	else if (access(cmd, X_OK) == -1 && !ft_strchr(cmd, '/'))
		error_return(data, cmd_path, "", 126);
	else
		error_return(data, cmd, "", 126);
}

void	execve_init(t_pipex *data, char *cmd)
{
	char	*cmd_path;

	split_command(data, cmd);
	if (!data->splitted_cmd)
		error_return(data, cmd, "", 127);
	cmd_path = get_command_path(data);
	if (!cmd_path)
		error_return(data, cmd, "command not found", 127);
	execve(cmd_path, data->splitted_cmd, data->envp);
	error_handle_execv(data, cmd, cmd_path);
}
