/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 00:16:41 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/13 07:49:55 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*dst;
	size_t	strl;

	strl = ft_strlen(str);
	dst = (char*)ft_calloc((strl + 1), sizeof(char));
	if (dst == 0)
		return (0);
	while (strl--)
	{
		dst[strl] = str[strl];
	}
	return (dst);
}
