/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahinog <nsahinog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 08:13:51 by nsahinog          #+#    #+#             */
/*   Updated: 2024/03/18 08:13:53 by nsahinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**free_malloc(char **tab, size_t i)
{
	while (tab[i])
		free(tab[i++]);
	return (free(tab), NULL);
}

int	word_count(char const *s, char c, int status)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (status && *s == c && *(s + 1) == c)
			return (-1);
		if (*s == c)
			s++;
		else
		{
			while (*s && *s != c)
				s++;
			i++;
		}
	}
	return (i);
}

static int	wlen(char const *s, char c)
{
	int	len;

	len = 0;
	if (!*s)
		return (0);
	while (*s && *s++ != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		a;
	int		i;

	a = -1;
	i = 0;
	res = (char **)malloc(sizeof(char *) * (word_count(s, c, 0) + 1));
	if (!s || !res)
		return (NULL);
	while (++a < word_count(s, c, 0))
	{
		while (s[i] && s[i] == c)
			i++;
		res[a] = ft_substr(s, i, wlen(&s[i], c));
		if (!res[a])
			return (free_malloc(res, 0));
		i += wlen(&s[i], c);
	}
	return (res[a] = NULL, res);
}
