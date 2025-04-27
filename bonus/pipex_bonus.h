/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:59:25 by mtalbi            #+#    #+#             */
/*   Updated: 2024/03/04 14:17:55 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../utils/utils.h"
# include "gnl/get_next_line_bonus.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>

// # define malloc(x) NULL

void	cmd1exec(char *argv[], char *envp[], int **pipefd);
void	cmd1exec_doc(char *argv[], char *envp[], int **pipefd, int in_fd[2]);
void	cmdsexec(char *argv[], char *envp[], int **pipefd, int cmd_index);
void	cmdnexec(char *argv[], char *envp[], int **pipefd);
void	cmdnexec_doc(char *argv[], char *envp[], int **pipefd);
void	ft_multi_fork(char *argv[], char *envp[], int **pipefd, int in_fd[2]);
void	ft_multi_pipe(int **pipefd, int sum_cmds);
void	close_fds(int **fds, int n);
void	her_doc_checker(char *argv[], int *argc, int doc[2]);
void	free_fds(int **fds, int sum);
void	free_exit(int sum_cmds, char **cmd, int **pipefd, char *err_msg);

#endif
