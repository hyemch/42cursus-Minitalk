/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:23:56 by hyecheon          #+#    #+#             */
/*   Updated: 2022/09/07 22:12:46 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sptr;

	sptr = (unsigned char *)s;
	while (n > 0)
	{
		if (*sptr == (unsigned char)c)
			return (sptr);
		sptr++;
		n--;
	}
	return (0);
}
