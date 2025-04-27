/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:16:49 by mtalbi            #+#    #+#             */
/*   Updated: 2024/07/12 10:00:57 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	**ft_fds_alocate(int sum_cmds)
{
	int	i;
	int	**pipefd;

	i = 0;
	pipefd = (int **)malloc((sum_cmds - 1) * sizeof(int *));
	if (!pipefd)
		return (0);
	while (i < sum_cmds - 1)
	{
		pipefd[i] = malloc(2 * sizeof(int));
		if (!pipefd[i])
			return (0);
		i++;
	}
	return (pipefd);
}

void	free_fds(int **fds, int sum)
{
	int	i;

	i = -1;
	while (++i < sum - 1)
		free(fds[i]);
	free(fds);
}

void	ft_piping(int **pipefd, int sum_cmds)
{
	int	i;

	i = 0;
	while (i < sum_cmds - 1)
	{
		if (pipe(pipefd[i]) == -1)
		{
			free_fds(pipefd, sum_cmds);
			ft_error_msg("pipe");
		}
		i++;
	}
}

// correct the behavior to wait all proccesses until their end

static void	ft_wait_all(int *status)
{
	pid_t	pid;

	pid = 0;
	while (pid != -1)
		pid = wait(status);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	**pipefd;
	int	sum_cmds;
	int	status;
	int	i;
	int	infile_fd[2];

	if (argc < 5 || (argc < 6 && !ft_strncmp(argv[1], "here_doc", 9)))
	{
		ft_putstr_fd("Error: Bad arguments \nUsage: ./pipex f1 cmd1 cmd2 cmd3\
 ... cmdn f2\n   or: ./pipex here_doc LIMITER cmd1 cmd2 file\n", 2);
		exit (EXIT_FAILURE);
	}
	if (!ft_strncmp(argv[1], "here_doc", 9))
		her_doc_checker(argv, &argc, infile_fd);
	i = 0;
	pipefd = NULL;
	sum_cmds = argc - 3;
	pipefd = ft_fds_alocate(sum_cmds);
	if (!pipefd)
		exit (EXIT_FAILURE);
	ft_piping(pipefd, sum_cmds);
	ft_multi_fork(argv, envp, pipefd, infile_fd);
	close_fds(pipefd, sum_cmds -1);
	ft_wait_all(&status);
	free_fds(pipefd, sum_cmds);
	return (WEXITSTATUS(status));
}
