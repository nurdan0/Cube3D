/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahinog <nsahinog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 08:14:37 by nsahinog          #+#    #+#             */
/*   Updated: 2024/03/18 08:14:39 by nsahinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_trim(char const *str, char const *set)
{
	char	*trimmed;
	size_t	i;
	size_t	str_len;
	size_t	tindex;

	if (!str || !set)
		return (NULL);
	i = 0;
	str_len = ft_strlen(str);
	while (str[i] && ft_strchr(set, str[i]))
		i++;
	while (str_len > i && ft_strchr(set, str[str_len - 1]))
		str_len--;
	trimmed = (char *)malloc(sizeof(char) * (str_len - i + 1));
	if (!trimmed)
		return (NULL);
	tindex = 0;
	while (i < str_len)
		trimmed[tindex++] = str[i++];
	trimmed[tindex] = '\0';
	return (trimmed);
}
