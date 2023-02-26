/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:44:42 by hyecheon          #+#    #+#             */
/*   Updated: 2022/09/09 22:13:53 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	word_cnt(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
	}
	return (cnt);
}

static int	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*is_strdup(const char *s, int size)
{
	int		i;
	char	*dst;

	i = 0;
	dst = (char *)malloc(sizeof(char) * (size + 1));
	if (!dst)
		return (0);
	while (s[i] && i < size)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	**freeall(char **str, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
		free(str[i]);
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		cnt;
	int		i;
	int		len;

	i = 0;
	cnt = word_cnt(s, c);
	dest = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!dest)
		return (0);
	while (i < cnt)
	{
		while (*s && *s == c)
			s++;
		len = word_len(s, c);
		dest[i] = is_strdup(s, len);
		if (!dest[i])
			return (freeall(dest, i));
		s += len;
		i++;
	}
	dest[i] = 0;
	return (dest);
}
