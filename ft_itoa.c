/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 21:11:51 by ehakam            #+#    #+#             */
/*   Updated: 2019/10/23 22:49:30 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(long n)
{
	int		i;
	int		minus;

	i = 0;
	minus = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		minus = 1;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i + minus);
}

static char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	c;

	i = 0;
	length = ft_strlen(str) - 1;
	if (str[i] == '-')
		i++;
	while (i < length)
	{
		c = str[i];
		str[i] = str[length];
		str[length] = c;
		length--;
		i++;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	long	ln;
	char	*nb;
	int		i;
	int		len;

	i = 0;
	ln = n;
	len = length(ln);
	if (!(nb = (char *)malloc(len + 1)))
		return (NULL);
	if (ln < 0)
	{
		nb[0] = '-';
		i = 1;
		ln = -ln;
	}
	if (ln == 0)
		nb[i++] = '0';
	while (i < len)
	{
		nb[i++] = (ln % 10) + 48;
		ln /= 10;
	}
	nb[i] = CNULL;
	return (ft_strrev(nb));
}
