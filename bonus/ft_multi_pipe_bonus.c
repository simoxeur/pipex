/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_pipe_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:41:29 by mtalbi            #+#    #+#             */
/*   Updated: 2024/02/29 15:43:01 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	ft_cmd_index(void)
{
	static int	cmd_index;

	cmd_index++;
	return (cmd_index);
}

static void	ft_exec(char *argv[], char *envp[], int **pipefd, int infile_fd[2])
{
	int			sum_cmds;
	int			cmd_index;

	cmd_index = ft_cmd_index() - 1;
	sum_cmds = ft_array_len(argv) - 3;
	if (cmd_index == 1)
	{
		if (ft_strncmp(argv[1], "here_doc", 9) == 0)
			cmd1exec_doc(argv, envp, pipefd, infile_fd);
		else
			cmd1exec(argv, envp, pipefd);
	}
	else if (cmd_index > 1 && cmd_index < sum_cmds)
		cmdsexec(argv, envp, pipefd, cmd_index);
	else if (cmd_index == sum_cmds)
	{
		if (ft_strncmp(argv[1], "here_doc", 9) == 0)
			cmdnexec_doc(argv, envp, pipefd);
		else
			cmdnexec(argv, envp, pipefd);
	}
}

void	ft_multi_pipe(int **pipefd, int sum_cmds)
{
	int	i;

	i = 0;
	while (i < sum_cmds - 1)
	{
		if (pipe(pipefd[i]) == -1)
			ft_error_msg("pipe");
		i++;
	}
}

void	ft_multi_fork(char *argv[], char *envp[], int **pipefd, int in_fd[2])
{
	int	index;
	int	sum_cmds;
	int	proc;

	index = 0;
	sum_cmds = ft_array_len(argv) - 3;
	while (index < sum_cmds)
	{
		ft_cmd_index();
		proc = fork();
		if (proc < 0)
		{
			free_fds(pipefd, sum_cmds);
			ft_error_msg("fork");
		}
		else if (proc == 0)
			ft_exec(argv, envp, pipefd, in_fd);
		index++;
	}
	wait(NULL);
}
