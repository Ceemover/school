/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 21:04:55 by dbolg             #+#    #+#             */
/*   Updated: 2020/08/02 06:32:22 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	null_wpi(t_wpi *wpi)
{
	wpi->width = 0;
	wpi->prec = -1;
	wpi->spec = 0;
	wpi->mal = 0;
	wpi->dot = 0;
	return ;
}

void	null_flg(t_flg *flg)
{
	flg->minus = 0;
	flg->zero = 0;
	flg->space = 0;
	flg->hash = 0;
	flg->plus = 0;
	return ;
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	char	*fmt;

	fmt = (char *)format;
	i = 0;
	if (!fmt)
		return (-1);
	va_start(ap, format);
	i = process_fmt(ap, fmt);
	va_end(ap);
	return (i);
}

int		print_neg_pointer(t_wpi *wpi, int *ret, char *char_p)
{
	f_putstr(ret, "0x");
	f_putstr(ret, char_p);
	f_putchar(ret, ' ', wpi->width - ft_strlen(char_p) - 2);
	free(char_p);
	char_p = NULL;
	return (*ret);
}
