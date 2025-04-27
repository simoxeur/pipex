/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:54:42 by mtalbi            #+#    #+#             */
/*   Updated: 2024/03/02 10:29:42 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	check_delim(char const *s, char *c, int n)
{
	if (n == 1)
	{
		if (*c == ' ' || *c == '\t')
		{
			if (!ft_strchr(s, '\t'))
				*c = ' ';
			if (!ft_strchr(s, ' '))
				*c = '\t';
		}
	}
	else if (n == 2)
	{
		s++;
		if (*s == '\'' || *s == '\"')
		{
			*c = *s;
			return (1);
		}
	}
	return (0);
}

static size_t	ft_countword(char const *str, char c)
{
	size_t	count;
	int		r;

	count = 0;
	r = 1;
	if (!str)
		return (0);
	while (*str)
	{
		check_delim(str, &c, 1);
		while (*str && *str == c && str++)
			r = 1;
		if (*str && *str != c && r == 1)
		{
			count++;
			r = 0;
		}
		if (*str)
			str++;
	}
	if (*str-- == c && !*str)
		count--;
	return (count);
}

static size_t	ft_wordlenght(char const *s, char c)
{
	size_t	len;
	char	*str;

	len = 0;
	str = (char *)s;
	if (!str)
		return (0);
	if (!ft_strchr(str, c))
		len = ft_strlen(str);
	else
		len = ft_strchr(str, c) - str;
	return (len);
}

static char	**ft_split_free(char **str, size_t index)
{
	while (index > 0)
	{
		free(str[index - 1]);
		index--;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	char	**result;

	if (!s)
		return (NULL);
	index = 0;
	result = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*s)
	{
		check_delim(s, &c, 1);
		while (*s && *s == c)
			s++;
		if (*s)
		{
			result[index++] = ft_substr(s, 0, ft_wordlenght(s, c));
			if (!result[index - 1])
				return (ft_split_free(result, index - 1));
			s += ft_wordlenght(s, c);
			s += check_delim(s, &c, 2);
		}
	}
	result[index] = NULL;
	return (result);
}
