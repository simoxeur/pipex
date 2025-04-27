/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:41:45 by mtalbi            #+#    #+#             */
/*   Updated: 2024/03/04 14:32:22 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_argv_update(char *argv[], int argc)
{
	int	i;

	i = 2;
	while (i < argc)
	{
		argv[i] = NULL;
		if (argv[i + 1])
			argv[i] = argv[i + 1];
		else
			break ;
		i++;
	}
}

static char	*read_file_in(char *limiter)
{
	char	*line;
	char	*infile;
	char	*tmp;

	infile = ft_strdup("");
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		tmp = infile;
		if (ft_strncmp_doc(line, limiter, ft_strlen(line) - 1))
			infile = ft_strjoin(infile, line);
		else
		{
			free(line);
			break ;
		}
		free(tmp);
		free(line);
	}
	return (infile);
}

void	her_doc_checker(char *argv[], int *argc, int doc[2])
{
	char	*limiter;
	char	*infile;

	limiter = argv[2];
	infile = read_file_in(limiter);
	if (pipe(doc) == -1)
	{
		free(infile);
		ft_error_msg("pipe");
	}
	write(doc[1], infile, ft_strlen(infile));
	free(infile);
	close(doc[1]);
	ft_argv_update(argv, *argc);
	*argc = *argc - 1;
}

// static void	ft_free_ifexist(char *str)
// {
// 	if (str && *str)
// 		free(str);
// 	return ;
// }

// void	her_doc_checker(char *argv[], int *argc, int doc[2])
// {
// 	char	*limiter;
// 	char	*line;
// 	char	*infile;
// 	char	*tmp;

// 	limiter = argv[2];
// 	infile = ft_strdup("");
// 	while (1)
// 	{
// 		line = get_next_line(0);
// 		if (!line)
// 			break ;
// 		tmp = infile;
// 		if (ft_strncmp_doc(line, limiter, ft_strlen(line) - 1))
// 			infile = ft_strjoin(infile, line);
// 		else
// 		{
// 			free(line);
// 			break;
// 		}
// 		free(tmp);
// 		free(line);
// 	}
// 	if (pipe(doc) == -1)
// 	{
// 		free(infile);
// 		ft_error_msg("pipe");
// 	}
// 	write(doc[1], infile, ft_strlen(infile));
// 	free(infile);
// 	close(doc[1]);
// 	ft_argv_update(argv, *argc);
// 	*argc = *argc - 1;
// }
