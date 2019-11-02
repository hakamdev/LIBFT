/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:51:56 by ehakam            #+#    #+#             */
/*   Updated: 2019/11/01 20:50:20 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst)
	{
		tmp = lst;
		lst = tmp->next;
		if (tmp->content)
			del(tmp->content);
		free(tmp);
		tmp = NULL;
	}
}
