/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:43:43 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/18 22:20:03 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	execve_init(t_pipex *data, char *cmd)
{
	char	*cmd_path;

	split_command(data, cmd);
	cmd_path = get_command_path(data);
	if (!cmd_path)
		error_return(cmd, "command not found", 127); //data->splitted_cmd[0]
	execve(cmd_path, data->splitted_cmd, data->envp);
	error_return(cmd_path, "", 127); // before 126
}
