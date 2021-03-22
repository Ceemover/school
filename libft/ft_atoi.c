/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 08:18:58 by dbolg             #+#    #+#             */
/*   Updated: 2020/05/30 20:37:02 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_my_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ' ? 1 : 0);
}

static char	*move_isspace(char *s)
{
	while (ft_my_isspace(*s))
		s++;
	return (s);
}

static char	*move_isnull(char *s)
{
	while (*s == '0')
		s++;
	return (s);
}

int			ft_atoi(const char *str)
{
	char	*s;
	int		sign;
	int		res;
	int		num;

	res = 0;
	num = 1;
	s = (char*)str;
	sign = 1;
	s = move_isspace(s);
	if (*s == '-' || *s == '+')
	{
		sign = (*s == '-' ? -1 : 1);
		s++;
	}
	s = move_isnull(s);
	while (*s && ft_isdigit(*s))
	{
		res = (res * 10) + *s - 48;
		if (num > 19)
			return (sign == -1 ? 0 : -1);
		s++;
		num++;
	}
	return (res * sign);
}
