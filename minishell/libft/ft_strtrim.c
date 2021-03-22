/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 18:20:10 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/13 07:52:02 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*front(char *s1, char *set)
{
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (*s1 == '\0')
		return ("");
	return (s1);
}

int		back(char *s, char *set, int len)
{
	while (len >= 0 && ft_strchr(set, s[len]))
		len--;
	return (len + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	int		offset;
	char	*str;
	char	*s;

	if (!s1 || !set)
		return (0);
	s = front((char*)s1, (char*)set);
	len = ft_strlen(s);
	offset = back((char*)s, (char*)set, (int)len);
	str = ft_substr(s, 0, offset);
	if (!str)
		return (0);
	return (str);
}
