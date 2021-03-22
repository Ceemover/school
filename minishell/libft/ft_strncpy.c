/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:17:14 by dbolg             #+#    #+#             */
/*   Updated: 2020/11/18 14:17:16 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncpy(char **dest, char *src, unsigned int s_len)
{
	unsigned int	i;

	i = 0;
	if (!(*dest = malloc(sizeof(char) * (s_len + 1))))
		return (1);
	while (src[i] != '\0' && i < s_len)
	{
		*(*dest + i) = src[i];
		++i;
	}
	*(*dest + i) = '\0';
	return (0);
}
