/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 04:02:21 by dbolg             #+#    #+#             */
/*   Updated: 2020/05/28 11:20:36 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char *ss1;
	unsigned char *ss2;

	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	while (len--)
	{
		if (*ss1 == *ss2)
		{
			ss1++;
			ss2++;
		}
		else
			return (*ss1 - *ss2);
	}
	return (0);
}
