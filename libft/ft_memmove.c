/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:50:31 by hyecheon          #+#    #+#             */
/*   Updated: 2022/09/09 20:35:38 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst == src || len == 0)
		return (dst);
	if (s > d)
	{
		while (len--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		while (len--)
		{
			*(d + len) = *(s + len);
		}
	}
	return (dst);
}
