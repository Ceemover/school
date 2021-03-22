/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_c_s_x_X.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:51:17 by dbolg             #+#    #+#             */
/*   Updated: 2020/08/02 06:25:23 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		process_char(t_wpi *wpi, va_list ap)
{
	int					ret;
	char				c;
	char				filler;

	filler = (wpi->flg.zero && !wpi->flg.minus ? '0' : ' ');
	ret = 0;
	if (wpi->spec == 8)
		c = '%';
	else
		c = va_arg(ap, int);
	if (wpi->width == 0)
		wpi->width = 1;
	if (wpi->flg.minus)
	{
		f_putchar(&ret, c, 1);
		f_putchar(&ret, ' ', wpi->width - 1);
	}
	else
	{
		f_putchar(&ret, filler, wpi->width - 1);
		f_putchar(&ret, c, 1);
	}
	return (ret);
}

int		process_string(t_wpi *wpi, va_list ap)
{
	char				*str;
	int					ret;
	int					fill;
	int					filler;

	ret = 0;
	fill = 0;
	filler = ((wpi->flg.zero && !wpi->flg.minus) ? '0' : ' ');
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	if (wpi->prec == 0 && wpi->dot)
		str = "";
	if (wpi->dot && (int)ft_strlen(str) > wpi->prec)
	{
		if (!(str = ft_substr(str, 0, wpi->prec)))
			return (-1);
		wpi->mal = 1;
	}
	fill = wpi->width - ft_strlen(str);
	(wpi->flg.minus ? f_putstr(&ret, str) : f_putchar(&ret, filler, fill));
	(wpi->flg.minus ? f_putchar(&ret, filler, fill) : f_putstr(&ret, str));
	(wpi->mal ? free(str) : 0);
	str = NULL;
	return (ret);
}

int		ft_find_xlen(size_t n)
{
	int		len;

	len = 1;
	while (n /= 16)
		len++;
	return (len);
}

char	*f_itoa_base16(int prec, unsigned long long n)
{
	int					len;
	char				*s;
	char				*set;
	unsigned long long	m;

	set = "0123456789abcdef";
	if (n == 0)
		return (!prec ? ft_strdup("") : ft_strdup("0"));
	len = 1;
	m = n;
	while (m /= 16)
		len++;
	if (!(s = malloc((len + 1) * sizeof(char))))
		return (NULL);
	s[len--] = '\0';
	s[len--] = set[n % 16];
	while (n /= 16)
		s[len--] = set[n % 16];
	return (s);
}

int		process_hex(t_wpi *wpi, va_list ap)
{
	size_t				n;
	char				*char_x;
	int					len;
	int					ret;

	ret = 0;
	n = va_arg(ap, unsigned int);
	if (!(char_x = f_itoa_base16(wpi->prec, n)))
		return (-1);
	(wpi->spec == 7 ? ft_str_toupper(&char_x) : 0);
	len = ft_find_xlen(n);
	if (wpi->prec == 0 && n == 0)
		len = 0;
	if (wpi->prec > len)
	{
		if (add_nulls(wpi, &char_x) == -1)
			return (-1);
	}
	print_d_i_u_x(wpi, &ret, char_x, 1);
	free(char_x);
	char_x = NULL;
	return (ret);
}
