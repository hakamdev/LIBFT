/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:10:36 by ehakam            #+#    #+#             */
/*   Updated: 2019/10/24 17:50:04 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_words(char *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == CNULL))
			words++;
		i++;
	}
	return (words);
}

static int	get_chars(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**free_all(char **out, int x)
{
	int		i;

	i = 0;
	while (i < x)
		free(out[i++]);
	free(out);
	return (NULL);
}

static char	**fill_out(char *s, char **out, char c)
{
	int		i;
	int		x;
	int		xx;

	i = 0;
	x = 0;
	xx = 0;
	while (s[i] && x < get_words(s, c))
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
			if (!(out[x] = malloc(sizeof(char) * get_chars(&s[i], c) + 1)))
				return (free_all(out, x));
		while (s[i] != c && s[i])
			out[x][xx++] = s[i++];
		out[x++][xx] = CNULL;
		xx = 0;
	}
	out[x] = NULL;
	return (out);
}

char		**ft_split(const char *ss, char c)
{
	char	**out;
	char	*s;

	s = (char *)ss;
	if (!s || *s == CNULL)
	{
		out = malloc(sizeof(char *));
		*out = NULL;
	}
	else
	{
		if (!(out = malloc((get_words(s, c) + 1) * sizeof(char *))))
			return (NULL);
		out = fill_out(s, out, c);
	}
	return (out);
}
