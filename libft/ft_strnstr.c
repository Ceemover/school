/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 00:55:12 by dbolg             #+#    #+#             */
/*   Updated: 2020/05/31 09:46:25 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (!*s2)
		return ((char*)s1);
	while (i < len && s1[i])
	{
		while (s1[i + n] == s2[n] && (i + n) < len && s1[i + n])
			n++;
		if (!s2[n])
			return ((char*)(s1 + i));
		else
			n = 0;
		i++;
	}
	return (NULL);
}
