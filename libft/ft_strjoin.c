/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 04:03:55 by dbolg             #+#    #+#             */
/*   Updated: 2020/05/27 07:43:11 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	ls1;
	size_t	ls2;
	size_t	ls3;

	if (s1 == 0 && s2 == 0)
		return (0);
	if (s1 == 0)
		return (ft_strjoin("", s2));
	if (s2 == 0)
		return (ft_strjoin(s1, ""));
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	ls3 = ls1 + ls2;
	s3 = (char*)ft_calloc(ls3 + 1, sizeof(char));
	if (s3 == 0)
		return (0);
	while (ls1--)
		s3[ls1] = s1[ls1];
	while (ls2--)
		s3[ft_strlen(s1) + ls2] = s2[ls2];
	return (s3);
}
