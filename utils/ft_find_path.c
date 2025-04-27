/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:07:09 by mtalbi            #+#    #+#             */
/*   Updated: 2024/03/02 11:24:03 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*ft_check_ifexist(char *cmd, int *checker)
{
	char	*path;

	path = NULL;
	if (access(cmd, X_OK) == 0)
		path = cmd;
	else
		ft_error_msg(cmd);
	*checker = 0;
	return (path);
}

static char	*ft_test_path(char *paths[], char *cmd)
{
	int		i;
	char	*our_path;
	char	*path;

	i = 0;
	while (paths[i])
	{
		our_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(our_path, cmd);
		free(our_path);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	return (NULL);
}

char	*ft_find_path(char *cmd, char *envp[])
{
	char	*path_line;
	char	**paths;
	char	*path;
	int		i;
	int		checker;

	if (!cmd || !*cmd)
		ft_error_msg(cmd);
	checker = 1;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path_line = envp[i] + 5;
		i++;
	}
	paths = ft_split(path_line, ':');
	if (ft_strchr(cmd, '/') != NULL)
		path = ft_check_ifexist(cmd, &checker);
	if (checker == 1)
		path = ft_test_path(paths, cmd);
	ft_free_arr(paths);
	return (path);
}
