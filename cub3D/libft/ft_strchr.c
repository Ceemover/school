/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 06:49:33 by dbolg             #+#    #+#             */
/*   Updated: 2020/05/29 20:16:10 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	const char	*s;

	if (str)
	{
		s = (char*)str;
		if (c == '\0')
			return ((char*)&s[ft_strlen(s)]);
		while (*s)
			if (*s != '\0' && *s != c)
				s++;
			else if (*s == c)
				return ((char*)s);
	}
	return (NULL);
}
