/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 21:10:19 by dbolg             #+#    #+#             */
/*   Updated: 2020/08/02 06:46:17 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_flg
{
	int		minus;
	int		zero;
	int		space;
	int		hash;
	int		plus;
}				t_flg;

typedef struct	s_wpi
{
	int		width;
	int		prec;
	int		i;
	int		spec;
	int		ret;
	int		mal;
	int		dot;

	t_flg	flg;
}				t_wpi;

/*
** libft.c
*/
size_t			ft_strlen(const char *str);
void			f_putchar(int *i, char fmt, int times);
int				ft_istrchr(const char *s, int c);
void			ft_str_toupper(char **str);
char			*ft_calloc(size_t num, size_t size);
/*
** libft2.c
*/
char			*ft_strdup(char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				f_putstr(int *ret, char *s);
int				ft_find_len(unsigned int n);
char			*ft_ch_itoa(unsigned int n, t_wpi *wpi);
/*
** process_c_s_x.c
*/
int				process_char(t_wpi *wpi, va_list ap);
int				process_string(t_wpi *wpi, va_list ap);
int				ft_find_xlen(size_t n);
char			*f_itoa_base16(int prec, unsigned long long n);
int				process_hex(t_wpi *wpi, va_list ap);
/*
** process_p_d_i_u.c
*/
int				process_pointer(t_wpi *wpi, va_list ap);
int				add_nulls(t_wpi *wpi, char **char_n);
void			print_d_i_u_x(t_wpi *wpi, int *ret, char *char_n, int sign);
int				process_d_i_u(t_wpi *wpi, va_list ap);
/*
** parce.c
*/
int				process_fmt(va_list ap, char *fmt);
/*
** ft_printf.c
*/
void			null_wpi(t_wpi *wpi);
void			null_flg(t_flg *flg);
int				ft_printf(const char *format, ...);
int				print_neg_pointer(t_wpi *wpi, int *ret, char *char_p);

#endif
