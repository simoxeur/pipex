/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:36:37 by mtalbi            #+#    #+#             */
/*   Updated: 2024/06/10 11:03:06 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	cmd1exec(char *argv[], char *envp[], int **pipefd)
{
	int		infile;
	char	**cmd;
	char	*path;
	int		sum_cmds;

	sum_cmds = ft_array_len(argv) - 3;
	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
	{
		close_fds(pipefd, sum_cmds - 1);
		ft_error_msg(argv[1]);
	}
	cmd = ft_split(argv[2], ' ');
	path = ft_find_path(cmd[0], envp);
	if (!path)
		free_exit(sum_cmds, cmd, pipefd, "");
	dup2(infile, STDIN_FILENO);
	dup2(pipefd[0][1], STDOUT_FILENO);
	close_fds(pipefd, sum_cmds - 1);
	close(infile);
	execve(path, cmd, envp);
	free_exit(sum_cmds, cmd, pipefd, "execve");
}

void	cmd1exec_doc(char *argv[], char *envp[], int **pipefd, int in_fd[2])
{
	char	**cmd;
	char	*path;
	int		sum_cmds;

	sum_cmds = ft_array_len(argv) - 3;
	cmd = ft_split(argv[2], ' ');
	path = ft_find_path(cmd[0], envp);
	if (!path)
		free_exit(sum_cmds, cmd, pipefd, "");
	dup2(in_fd[0], STDIN_FILENO);
	dup2(pipefd[0][1], STDOUT_FILENO);
	close_fds(pipefd, sum_cmds -1);
	close(in_fd[0]);
	execve(path, cmd, envp);
	free_exit(sum_cmds, cmd, pipefd, "execve");
}

void	cmdsexec(char *argv[], char *envp[], int **pipefd, int cmd_index)
{
	char	**cmd;
	char	*path;
	int		sum_cmds;

	sum_cmds = ft_array_len(argv) - 3;
	cmd = ft_split(argv[cmd_index + 1], ' ');
	path = ft_find_path(cmd[0], envp);
	if (!path)
		free_exit(sum_cmds, cmd, pipefd, "");
	dup2(pipefd[cmd_index - 2][0], STDIN_FILENO);
	dup2(pipefd[cmd_index - 1][1], STDOUT_FILENO);
	close_fds(pipefd, sum_cmds -1);
	execve(path, cmd, envp);
	free_exit(sum_cmds, cmd, pipefd, "execve");
}

void	cmdnexec(char *argv[], char *envp[], int **pipefd)
{
	int		outfile;
	char	**cmd;
	char	*path;
	int		sum_cmds;

	sum_cmds = ft_array_len(argv) - 3;
	outfile = open(argv[sum_cmds + 2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (outfile == -1)
	{
		close_fds(pipefd, sum_cmds - 1);
		ft_error_msg(argv[sum_cmds + 2]);
	}
	cmd = ft_split(argv[sum_cmds + 1], ' ');
	path = ft_find_path(cmd[0], envp);
	if (!path)
		free_exit(sum_cmds, cmd, pipefd, "");
	dup2(pipefd[sum_cmds - 2][0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close_fds(pipefd, sum_cmds -1);
	close(outfile);
	execve(path, cmd, envp);
	free_exit(sum_cmds, cmd, pipefd, "execve");
}

void	cmdnexec_doc(char *argv[], char *envp[], int **pipefd)
{
	int		outfile;
	char	**cmd;
	char	*path;
	int		sum_cmds;

	sum_cmds = ft_array_len(argv) - 3;
	outfile = open(argv[sum_cmds + 2], O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (outfile == -1)
	{
		free_fds(pipefd, sum_cmds);
		ft_error_msg(argv[sum_cmds + 2]);
	}
	cmd = ft_split(argv[sum_cmds + 1], ' ');
	path = ft_find_path(cmd[0], envp);
	if (!path)
		free_exit(sum_cmds, cmd, pipefd, "");
	dup2(pipefd[sum_cmds - 2][0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close_fds(pipefd, sum_cmds -1);
	close(outfile);
	execve(path, cmd, envp);
	free_exit(sum_cmds, cmd, pipefd, "execve");
}
