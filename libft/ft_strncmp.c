/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:08:38 by hyecheon          #+#    #+#             */
/*   Updated: 2022/09/07 22:12:09 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		*sptr1;
	unsigned char		*sptr2;

	sptr1 = (unsigned char *)s1;
	sptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (sptr1[i] != '\0' || sptr2[i] != '\0'))
	{	
		if (sptr1[i] != sptr2[i])
			return (sptr1[i] - sptr2[i]);
		i++;
	}
	return (0);
}
