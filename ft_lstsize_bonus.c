/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:11:56 by ehakam            #+#    #+#             */
/*   Updated: 2019/11/01 18:16:29 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*cur;
	int		size;

	size = 0;
	cur = lst;
	while (cur != NULL)
	{
		size++;
		cur = cur->next;
	}
	return (size);
}
