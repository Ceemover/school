/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 01:50:22 by dbolg             #+#    #+#             */
/*   Updated: 2020/05/31 09:00:06 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	l;

	if (s == 0)
		return (0);
	l = ft_strlen(s);
	if (start > l)
		return (ft_strdup(""));
	if (len > l - start)
		len = l - start;
	d = (char*)ft_calloc(len + 1, sizeof(char));
	if (d == 0)
		return (0);
	while (len--)
		d[len] = s[len + start];
	return (d);
}
