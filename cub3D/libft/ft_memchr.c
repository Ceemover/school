/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 03:16:09 by dbolg             #+#    #+#             */
/*   Updated: 2020/05/22 08:27:46 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *dst, int c, size_t len)
{
	unsigned char *d;

	d = (unsigned char*)dst;
	while (len--)
		if (*d != (unsigned char)c)
			d++;
		else
			return (d);
	return (0);
}
