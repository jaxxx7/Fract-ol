/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhachem <mhachem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:53:15 by mhachem           #+#    #+#             */
/*   Updated: 2025/07/03 15:53:29 by mhachem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_get_rows(char const *s, char c)
{
	int	rows;
	int	i;
	if (!s)
		return (0);
	rows = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			rows++;
		while (s[i] && s[i] != c)
				i++;
	}
	return (rows);
}

char	**ft_free(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	char	*wordstart;
	int		i;

	new = (char **)malloc(sizeof(char *) * (ft_get_rows(s, c) + 1));
	if (!new)
		return (NULL);
	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			wordstart = (char *)s;
			while (*s != c && *s)
				s++;
			new[i] = ft_substr(wordstart, 0, s - wordstart);
			if (!new[i])
				return (ft_free(new));
			i++;
		}
		else
			s++;
	}
	new[i] = NULL;
	return (new);
}
