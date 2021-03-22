/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 20:22:22 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/13 01:54:44 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t maxlen)
{
	size_t	di;
	size_t	n;
	size_t	di2;
	size_t	si;

	n = 0;
	di = ft_strlen(d);
	di2 = di;
	si = ft_strlen(s);
	if (maxlen <= di)
		return (si + maxlen);
	while (di < maxlen - 1 && s[n])
	{
		d[di] = s[n];
		di++;
		n++;
	}
	if (di < maxlen)
		d[di] = '\0';
	else
		d[maxlen - 1] = '\0';
	return (si + di2);
}
