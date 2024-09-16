/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:43:43 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/16 19:07:23 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h> // remove when libft added

void execve_init(t_pipex *data, char *cmd)
{
    char *cmd_path;
    
    split_command(data, cmd);
    cmd_path = get_command_path(data);
    if (!cmd_path)
        error_return(data->splitted_cmd[0], 1);
    execve(cmd_path, data->splitted_cmd, data->envp);  
    error_return(cmd_path, 126);
}
