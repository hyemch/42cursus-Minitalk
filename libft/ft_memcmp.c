/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:27:21 by hyecheon          #+#    #+#             */
/*   Updated: 2022/08/22 02:32:43 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sptr1;
	const unsigned char	*sptr2;

	sptr1 = (const unsigned char *)s1;
	sptr2 = (const unsigned char *)s2;
	while (n)
	{
		if (*sptr1 != *sptr2)
			return (*sptr1 - *sptr2);
		sptr1++;
		sptr2++;
		n--;
	}
	return (0);
}
