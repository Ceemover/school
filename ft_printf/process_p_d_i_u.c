/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p_d_i_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 20:54:56 by dbolg             #+#    #+#             */
/*   Updated: 2020/08/03 11:36:21 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			process_pointer(t_wpi *wpi, va_list ap)
{
	size_t			n;
	char			*char_p;
	int				ret;
	int				fill;
	int				len;

	ret = 0;
	n = va_arg(ap, size_t);
	char_p = f_itoa_base16(wpi->prec, n);
	if (wpi->flg.minus)
		return (print_neg_pointer(wpi, &ret, char_p));
	fill = 0;
	len = ((int)ft_strlen(char_p) ? (int)ft_strlen(char_p) : 1);
	f_putchar(&ret, ' ', (wpi->width - ((!n && wpi->dot) ? 2 :
					ft_find_xlen(n) + 2)));
	n = (wpi->prec - len);
	if (wpi->dot)
		fill = (n > 0 ? n : 0);
	f_putstr(&ret, "0x");
	f_putchar(&ret, '0', fill);
	f_putstr(&ret, char_p);
	free(char_p);
	char_p = NULL;
	return (ret);
}

int			add_nulls(t_wpi *wpi, char **char_n)
{
	int				fill_str;
	int				fill_null;
	int				i;
	char			*tmp;

	i = -1;
	fill_str = (wpi->prec > wpi->width ? wpi->prec : wpi->width);
	fill_null = wpi->prec - ft_strlen(*char_n);
	if (!(tmp = ft_calloc(fill_str + 1, sizeof(char))))
	{
		free(*char_n);
		return (-1);
	}
	wpi->mal = 1;
	while (++i < fill_null)
		tmp[i] = '0';
	while (i < ((int)ft_strlen(*char_n) + fill_null))
	{
		tmp[i] = (*char_n)[(i) - fill_null];
		i++;
	}
	free(*char_n);
	*char_n = tmp;
	return (1);
}

static void	print_d_i_u_x_cont(t_wpi *wpi, int *ret, char *char_n, int sign)
{
	int				len;
	int				total_len;
	char			*s_sign;

	s_sign = (sign == 1 ? "" : "-");
	sign = sign > 0 ? 0 : sign;
	len = ft_strlen(char_n);
	total_len = wpi->width + sign;
	if (wpi->dot)
		total_len = wpi->prec > len ? wpi->prec : len;
	if (!wpi->flg.minus)
	{
		f_putchar(ret, ' ', wpi->width - total_len + sign);
		(*s_sign ? f_putchar(ret, *s_sign, 1) : 0);
		f_putchar(ret, '0', total_len - len);
		f_putstr(ret, char_n);
		return ;
	}
	(*s_sign ? f_putchar(ret, *s_sign, 1) : 0);
	f_putchar(ret, '0', total_len - len);
	f_putstr(ret, char_n);
	f_putchar(ret, ' ', wpi->width - total_len + sign);
	return ;
}

void		print_d_i_u_x(t_wpi *wpi, int *ret, char *char_n, int sign)
{
	if ((!wpi->flg.minus && wpi->flg.zero) || wpi->dot)
	{
		print_d_i_u_x_cont(wpi, ret, char_n, sign);
		return ;
	}
	if (sign == 1)
	{
		(wpi->flg.minus ? f_putstr(ret, char_n) :
			f_putchar(ret, ' ', wpi->width - ft_strlen(char_n)));
		(!wpi->flg.minus ? f_putstr(ret, char_n) :
			f_putchar(ret, ' ', wpi->width - ft_strlen(char_n)));
		return ;
	}
	(wpi->flg.minus ? f_putchar(ret, '-', 1) :
		f_putchar(ret, ' ', wpi->width - ft_strlen(char_n) - 1));
	(wpi->flg.minus ? f_putstr(ret, char_n) : f_putchar(ret, '-', 1));
	(!wpi->flg.minus ? f_putstr(ret, char_n) :
		f_putchar(ret, ' ', wpi->width - ft_strlen(char_n) - 1));
	return ;
}

int			process_d_i_u(t_wpi *wpi, va_list ap)
{
	unsigned int	n;
	char			*char_n;
	int				len;
	int				ret;
	int				sign;

	ret = 0;
	len = (wpi->spec == 5 ? (int)(va_arg(ap, unsigned int)) :
			va_arg(ap, int));
	sign = (len < 0 ? -1 : 1);
	if (wpi->spec == 3 || wpi->spec == 4)
		n = (sign == 1 ? len : ((-1) * len));
	else
		n = ((wpi->spec == 1 || wpi->spec == 5) ? len : (-1) * len);
	((wpi->spec == 5) ? (sign = 1) : 0);
	char_n = ft_ch_itoa(n, wpi);
	if (wpi->prec > ft_find_len(len))
	{
		if (add_nulls(wpi, &char_n) == -1)
			return (-1);
	}
	print_d_i_u_x(wpi, &ret, char_n, sign);
	free(char_n);
	char_n = NULL;
	return (ret);
}
