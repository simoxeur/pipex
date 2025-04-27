/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:07:02 by mtalbi            #+#    #+#             */
/*   Updated: 2024/03/04 14:41:32 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>

size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* I add this function <ft_strncmp_doc> which is the same as the normal one
just here the return if we give an empty string as limiter
in here_doc it will not stop*/
int		ft_strncmp_doc(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putstr_fd(char const *s, int fd);
char	*ft_find_path(char *cmd, char *envp[]);
void	ft_free_arr(char **str);
void	ft_error_msg(const char *msg);
int		ft_array_len(char *argv[]);
void	close_fds(int **fds, int n);

#endif