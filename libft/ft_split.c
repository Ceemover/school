/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 04:56:21 by dbolg             #+#    #+#             */
/*   Updated: 2020/05/31 13:40:38 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find(char *s, char c)
{
	int i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

static size_t	count_words(char *s, char c)
{
	int		i;
	size_t	count;
	int		delim;

	delim = -1;
	count = 0;
	i = 0;
	if (s == 0 || *s == '\0' || c == 0)
		return (0);
	while (s && s[i])
	{
		if ((s[i] != c && delim == 1)
				|| (s[i] != c && delim == -1))
		{
			count++;
			delim = 0;
		}
		if ((s[i] == c && delim == 0)
				|| (s[i] == c && delim == -1))
			delim = 1;
		i++;
	}
	return (count);
}

static char		**free_all(char **arr, int words)
{
	while (words >= 0)
	{
		free(arr[words]);
		words--;
	}
	free(arr);
	return (NULL);
}

static char		**roll(char **arr, char const *s, char c)
{
	int		i;
	int		words;
	char	*ss;

	ss = (char*)s;
	i = 0;
	words = count_words(ss, c);
	while (words-- && *ss != '\0')
	{
		while (*ss == c && *ss)
			ss++;
		if (find(ss, c) == 0)
		{
			if (!(arr[i] = ft_substr(ss, 0, ft_strlen(ss))))
				return (free_all(arr, i - 1));
		}
		else
		{
			if (!(arr[i] = ft_substr(ss, 0, find(ss, c))))
				return (free_all(arr, i - 1));
			ss += find(ss, c) + 1;
		}
		i++;
	}
	return (arr);
}

char			**ft_split(char const *s, char c)
{
	char	*ss;
	char	**arr;
	int		words;

	if (!s)
		return (ft_split("", c));
	ss = (char*)s;
	words = count_words(ss, c);
	arr = ft_calloc((words + 1), sizeof(char*));
	if (arr == 0)
		free(arr);
	return (!arr ? NULL : (roll(arr, s, c)));
}
