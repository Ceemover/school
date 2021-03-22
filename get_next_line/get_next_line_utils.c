/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 07:37:17 by dbolg             #+#    #+#             */
/*   Updated: 2020/07/12 21:45:56 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		f_ree(char **str1, char **str2, char **str3)
{
	if (*str3 != *str2)
		free(*str3);
	if (*str2 != *str1)
	{
		free(*str2);
		free(*str1);
	}
	else
		free(*str1);
	*str1 = NULL;
	*str2 = NULL;
	*str3 = NULL;
	return (0);
}

int		find_n(char *buf, size_t len)
{
	size_t	i;

	i = 0;
	if (buf && len)
	{
		while (i < len)
		{
			if (buf[i] == '\n')
				return (i);
			i++;
		}
	}
	return (-1);
}

char	*ft_calloc(size_t num, size_t size)
{
	int		len;
	char	*y;
	int		i;

	if (size == 0 || num == 0)
	{
		num = 1;
		size = 1;
	}
	y = (char*)malloc(num * size);
	if (y == 0)
		return (0);
	len = num * size;
	i = 0;
	while (len--)
	{
		y[i] = '\0';
		i++;
	}
	return (y);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	ls1;
	size_t	ls2;
	size_t	ls3;

	if (s1 == 0 && s2 == 0)
		return (ft_strjoin("", ""));
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
