/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 19:12:15 by dbolg             #+#    #+#             */
/*   Updated: 2020/05/31 12:08:06 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen((char*)s);
	if (!s || !f)
		return (0);
	if (!(str = (char*)malloc((len + 1) * sizeof(char))))
		return (0);
	i = len;
	while (len--)
	{
		str[len] = f(len, s[len]);
	}
	str[i] = '\0';
	return (str);
}
