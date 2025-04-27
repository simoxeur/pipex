/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 04:12:04 by mtalbi            #+#    #+#             */
/*   Updated: 2024/03/04 14:30:54 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (((unsigned char)(*s1) - (unsigned char)(*s2)));
}

int	ft_strncmp_doc(const char *line, const char *limiter, size_t n)
{
	if (n == 0 && limiter[0] == '\0')
		return (0);
	while (*line && *limiter && *line == *limiter && n > 1)
	{
		line++;
		limiter++;
		n--;
	}
	if (!*limiter)
		return (1);
	return (((unsigned char)(*line) - (unsigned char)(*limiter)));
}
