/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:59:25 by mtalbi            #+#    #+#             */
/*   Updated: 2024/02/29 15:55:44 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../utils/utils.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>

void	cmd1exec(char *argv[], char *envp[], int pipefd[2]);
void	cmd2exec(char *argv[], char *envp[], int pipefd[2]);
pid_t	ft_fork(char *argv[], char *envp[], int pipefd[2], int cmd_id);

#endif
