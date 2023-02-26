/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:00:41 by hyecheon          #+#    #+#             */
/*   Updated: 2022/09/09 19:58:38 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1) - 1;
	if (!s1)
		return (0);
	if (!set || *set == 0 || *s1 == 0)
		return (ft_strdup(s1));
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[len] && ft_strchr(set, s1[len]) && i <= len)
		len--;
	str = (char *)malloc(sizeof(char) * (len - i + 2));
	if (!str)
		return (0);
	ft_strlcpy(str, &s1[i], len - i + 2);
	return (str);
}
