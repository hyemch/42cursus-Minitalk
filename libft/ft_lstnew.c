/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hycheon <hycheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:28:40 by hyecheon          #+#    #+#             */
/*   Updated: 2022/09/10 22:59:47 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*link;

	link = (t_list *)malloc(sizeof(t_list));
	if (!link)
		return (0);
	link->content = content;
	link->next = 0;
	return (link);
}
