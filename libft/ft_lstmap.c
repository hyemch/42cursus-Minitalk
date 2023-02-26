/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hycheon <hycheon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:05:28 by hyecheon          #+#    #+#             */
/*   Updated: 2022/09/10 23:01:03 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*result;

	if (!lst || !f)
		return (0);
	result = 0;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, temp);
		temp = temp->next;
		lst = lst->next;
	}
	return (result);
}
