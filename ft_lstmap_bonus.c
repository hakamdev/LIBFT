/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:50:18 by ehakam            #+#    #+#             */
/*   Updated: 2019/11/02 17:56:54 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;
	t_list	*cur;

	cur = lst;
	if (cur && f)
	{
		newlst = ft_lstnew(f(cur->content));
		if (!newlst)
			return (NULL);
		if (del)
			ft_lstdelone(cur, del);
		else
			cur = cur->next;
		tmp = newlst;
	}
	while (cur && f)
	{
		tmp->next = ft_lstnew(f(cur->content));
		if (!(tmp->next))
			return (NULL);
		if (del)
			ft_lstdelone(cur, del);
		else
			cur = cur->next;
		tmp = tmp->next;
	}
	return (newlst);
}
