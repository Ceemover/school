/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 10:05:27 by dbolg             #+#    #+#             */
/*   Updated: 2020/05/29 20:08:59 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int len;

	len = (int)ft_strlen(str);
	if (c == '\0')
		return ((char*)str + len);
	while (len >= 0)
	{
		if (str[len] == c)
			return ((char*)str + len);
		len--;
	}
	return (0);
}
