/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:44:38 by dbolg             #+#    #+#             */
/*   Updated: 2020/08/01 21:18:36 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(char *str)
{
	char			*dst;
	size_t			strl;

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	l;

	if (s == 0)
		return (0);
	l = ft_strlen(s);
	if (start > l)
		return (ft_strdup(""));
	if (len > l - start)
		len = l - start;
	d = (char*)ft_calloc(len + 1, sizeof(char));
	if (d == 0)
		return (0);
	while (len--)
		d[len] = s[len + start];
	return (d);
}

int		f_putstr(int *ret, char *s)
{
	int				i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	*ret += i;
	return (i);
}

int		ft_find_len(unsigned int n)
{
	int				count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_ch_itoa(unsigned int n, t_wpi *wpi)
{
	unsigned int	len;
	char			*char_n;

	if (wpi->prec == 0 && n == 0)
	{
		char_n = ft_strdup("");
		return (char_n);
	}
	len = ft_find_len(n);
	char_n = ft_calloc(len + 1, sizeof(char));
	char_n[len] = '\0';
	if (n == 0)
		char_n[0] = '0';
	while (n != 0)
	{
		len--;
		char_n[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (char_n);
}
