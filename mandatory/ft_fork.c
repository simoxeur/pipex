/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:26:13 by mtalbi            #+#    #+#             */
/*   Updated: 2024/02/29 15:43:59 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	ft_fork(char *argv[], char *envp[], int pipefd[2], int cmd_id)
{
	pid_t	proc;

	proc = fork();
	if (proc < 0)
		ft_error_msg("fork");
	else if (proc == 0)
	{
		if (cmd_id == 1)
			cmd1exec(argv, envp, pipefd);
		else
			cmd2exec(argv, envp, pipefd);
	}
	else
		return (proc);
	return (proc);
}
