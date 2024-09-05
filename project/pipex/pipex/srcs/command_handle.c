/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shachowd <shachowd@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:43:43 by shachowd          #+#    #+#             */
/*   Updated: 2024/09/03 21:06:59 by shachowd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h> // remove when libft added

void execve_init(t_pipex *data, char *cmd)
{
    //int execv_status;
    char *path;
    char **split_cmd;

    split_cmd = ft_split(cmd, ' ');

    //execv_status = 0;
    execve(path, split_cmd, data->envp);

}
