/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec_res.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:36:37 by mtalbi            #+#    #+#             */
/*   Updated: 2024/06/10 11:03:06 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_exit(int sum_cmds, char **cmd, int **pipefd, char *err_msg)
{
	ft_free_arr(cmd);
	free_fds(pipefd, sum_cmds);
	ft_error_msg(err_msg);
}
