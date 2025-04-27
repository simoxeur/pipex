/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:16:49 by mtalbi            #+#    #+#             */
/*   Updated: 2024/03/02 10:18:50 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		pipefd[2];
	pid_t	cmd1;
	pid_t	cmd2;
	int		status;

	if (argc != 5)
	{
		ft_putstr_fd("Error: Bad arguments", 2);
		ft_putstr_fd("\nUsage: ./pipex <infile> <cmd1> <cmd2> <outfile>", 1);
		exit (EXIT_FAILURE);
	}
	if (!envp || !*envp)
		exit (EXIT_FAILURE);
	if (pipe(pipefd) == -1)
		ft_error_msg("pipe");
	cmd1 = ft_fork(argv, envp, pipefd, 1);
	cmd2 = ft_fork(argv, envp, pipefd, 2);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(cmd1, &status, 0);
	waitpid(cmd2, &status, 0);
	return (WEXITSTATUS(status));
}
