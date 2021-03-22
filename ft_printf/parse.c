/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 21:00:58 by dbolg             #+#    #+#             */
/*   Updated: 2020/08/02 04:10:24 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_flg(t_wpi *wpi, char c)
{
	if (c == '-')
		wpi->flg.minus = 1;
	if (c == '0')
		wpi->flg.zero = 1;
	if (c == ' ')
		wpi->flg.space = 1;
	if (c == '#')
		wpi->flg.hash = 1;
	if (c == '+')
		wpi->flg.plus = 1;
	wpi->i++;
	return ;
}

static void	add_width(t_wpi *wpi, va_list ap, char *fmt)
{
	if (fmt[wpi->i] == '*')
	{
		if ((wpi->width = va_arg(ap, int)) < 0)
		{
			wpi->width *= -1;
			wpi->flg.zero = 0;
			wpi->flg.minus = 1;
		}
		wpi->i++;
	}
	else
	{
		while ('0' <= fmt[wpi->i] && fmt[wpi->i] <= '9')
		{
			wpi->width = wpi->width * 10 + fmt[wpi->i] - '0';
			wpi->i++;
		}
	}
	return ;
}

static int	add_precision(t_wpi *wpi, va_list ap, char *fmt)
{
	wpi->i++;
	wpi->prec = 0;
	if (fmt[wpi->i] == '*')
	{
		if ((wpi->prec = va_arg(ap, int)) < 0)
		{
			(fmt[wpi->i + 1] == 's' ? (wpi->prec *= -1) : 0);
			wpi->dot = 0;
		}
		wpi->i++;
	}
	else
	{
		if ('0' <= fmt[wpi->i] && fmt[wpi->i] <= '9')
			wpi->prec = 0;
		while ('0' <= fmt[wpi->i] && fmt[wpi->i] <= '9')
		{
			wpi->prec = wpi->prec * 10 + fmt[wpi->i] - '0';
			wpi->i++;
		}
	}
	return (wpi->prec == 0 ? 0 : 1);
}

static int	parse_fmt(va_list ap, t_wpi *wpi, char *fmt)
{
	static int	(*p[9])(t_wpi *, va_list) = {process_char,
		process_string, process_pointer, process_d_i_u, process_d_i_u,
		process_d_i_u, process_hex, process_hex, process_char};

	wpi->i++;
	while ((ft_istrchr("-0 #+", fmt[wpi->i])) > -1)
		add_flg(wpi, fmt[wpi->i]);
	if (fmt[wpi->i] == '*' || ('0' <= fmt[wpi->i] || fmt[wpi->i] <= '9'))
		add_width(wpi, ap, fmt);
	if (fmt[wpi->i] == '.' && fmt[wpi->i + 1])
	{
		wpi->dot = 1;
		if (add_precision(wpi, ap, fmt) < 0)
			return (-1);
	}
	wpi->spec = ft_istrchr("cspdiuxX%", fmt[wpi->i]);
	if (wpi->spec < 0)
		return (-1);
	wpi->ret += p[wpi->spec](wpi, ap);
	return (wpi->ret);
}

int			process_fmt(va_list ap, char *fmt)
{
	t_wpi		wpi;

	null_wpi(&wpi);
	wpi.ret = 0;
	wpi.i = 0;
	null_flg(&wpi.flg);
	while (fmt[wpi.i])
	{
		if (fmt[wpi.i] != '%' && wpi.ret != -1)
		{
			f_putchar(&wpi.i, fmt[wpi.i], 1);
			wpi.ret++;
		}
		else if (fmt[wpi.i] == '%' && fmt[wpi.i + 1] && wpi.ret != -1)
		{
			if ((parse_fmt(ap, &wpi, fmt)) < 0)
				return (-1);
			null_wpi(&wpi);
			null_flg(&wpi.flg);
			wpi.i++;
		}
		else if (fmt[wpi.i] == '%')
			f_putchar(&wpi.i, '%', 1);
	}
	return (wpi.ret);
}
