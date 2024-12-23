/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dias <dinursul@student.42.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:00:21 by Dias              #+#    #+#             */
/*   Updated: 2024/12/18 10:08:09 by Dias             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_all(char **res, size_t idx)
{
	while (idx > 0)
		free(res[--idx]);
	free(res);
	return (NULL);
}

static size_t	count_words(const char *s, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (cnt);
}

static char	*word_dup(const char *s, size_t start, size_t end)
{
	char	*w;
	size_t	i;

	w = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!w)
		return (NULL);
	i = 0;
	while (start < end)
		w[i++] = s[start++];
	w[i] = '\0';
	return (w);
}

static char	**fill_words(const char *s, char c, char **res, size_t wc)
{
	size_t	i;
	size_t	st;
	size_t	idx;

	i = 0;
	idx = 0;
	while (s[i] && idx < wc)
	{
		while (s[i] && s[i] == c)
			i++;
		st = i;
		while (s[i] && s[i] != c)
			i++;
		res[idx] = word_dup(s, st, i);
		if (!res[idx])
			return (free_all(res, idx));
		idx++;
	}
	res[idx] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	wc;

	if (!s)
		return (NULL);
	wc = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!res)
		return (NULL);
	return (fill_words(s, c, res, wc));
}
