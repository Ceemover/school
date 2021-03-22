/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:39:45 by dbolg             #+#    #+#             */
/*   Updated: 2020/08/01 21:19:42 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	f_putchar(int *i, char fmt, int times)
{
	while (times > 0)
	{
		write(1, &fmt, 1);
		*i = *i + 1;
		times--;
	}
	return ;
}

int		ft_istrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
		if (s[i] != '\0' && s[i] != c)
			i++;
		else if (s[i] == c)
			return (i);
	return (-1);
}

void	ft_str_toupper(char **str)
{
	int		i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] >= 97 && (*str)[i] <= 122)
			(*str)[i] -= 32;
		i++;
	}
	return ;
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
