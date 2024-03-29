/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:57:26 by ehakam            #+#    #+#             */
/*   Updated: 2019/10/23 22:40:32 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		n;
	long	r;
	char	*s;

	i = 0;
	r = 0;
	n = 1;
	s = (char *)str;
	while (*s > 0 && *s <= ' ')
	{
		if (*s == 27)
			return (INULL);
		s++;
	}
	if (*s == '-')
	{
		n = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (s[i] >= '0' && s[i] <= '9')
		r = r * 10 + (s[i++] - '0');
	return (r * n);
}
