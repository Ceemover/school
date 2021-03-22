/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 21:25:00 by dbolg             #+#    #+#             */
/*   Updated: 2020/05/28 12:24:04 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t max)
{
	size_t s;

	s = ft_strlen(src);
	if (s + 1 < max)
	{
		ft_memcpy(dst, src, s + 1);
	}
	else if (max != 0)
	{
		ft_memcpy(dst, src, max - 1);
		dst[max - 1] = '\0';
	}
	return (s);
}
