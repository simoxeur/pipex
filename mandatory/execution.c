/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:36:37 by mtalbi            #+#    #+#             */
/*   Updated: 2024/06/11 22:01:41 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd1exec(char *argv[], char *envp[], int pipefd[2])
{
	int		infile;
	char	**cmd;
	char	*path;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		ft_error_msg(argv[1]);
	}
	cmd = ft_split(argv[2], ' ');
	path = ft_find_path(cmd[0], envp);
	if (!path)
	{
		ft_free_arr(cmd);
		exit (EXIT_FAILURE);
	}
	close(pipefd[0]);
	dup2(infile, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	execve(path, cmd, envp);
	ft_free_arr(cmd);
	ft_error_msg("execve");
}

void	cmd2exec(char *argv[], char *envp[], int pipefd[2])
{
	int		outfile;
	char	**cmd;
	char	*path;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (outfile == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		ft_error_msg(argv[4]);
	}
	cmd = ft_split(argv[3], ' ');
	path = ft_find_path(cmd[0], envp);
	if (!path)
	{
		ft_free_arr(cmd);
		exit (EXIT_FAILURE);
	}
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipefd[0]);
	execve(path, cmd, envp);
	ft_free_arr(cmd);
	ft_error_msg("execve");
}
