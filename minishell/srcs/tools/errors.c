/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 03:13:24 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/11 21:12:48 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

int			set_err(t_all *all, int errcode, char *message, int err_unusual)
{
	if (errcode == -1)
		all->spec_err_mess = message;
	all->err_unusual = err_unusual;
	all->errcode = errcode;
	return (1);
}

int			ft_ext(t_all *all, int set_err)
{
	(void)set_err;
	if (!all->errcode)
		free_all(all) ? 0 : exit(0);
	if (all->errcode == -1)
	{
		f_write(2, all->spec_err_mess);
		(all->spec_err_mess && *all->spec_err_mess) ? write(2, "\n", 1) : 0;
		free_all(all);
		exit(all->err_unusual != -1 ? all->err_unusual : 1);
	}
	else if (all->errcode == -3)
	{
		f_write(2, g_emojis[random_emoji(&g_queue)]) ? 0 : f_write(2,\
		" \33[1;35m mimishell:\33[0m syntax error near unexpected token '");
		!all->line[all->i] ? f_write(2, "newline") :
			write(2, &all->line[all->i], 1);
		if (all->line[all->i] == '>' && all->line[all->i + 1] == '>')
			write(2, &all->line[all->i + 1], 1);
		free_all(all);
		exit((!f_wr_ch(2, '\'') && !f_wr_ch(2, '\n')) ? 258 : 258);
	}
	if (all->errcode)
		f_write(2, strerror(all->errcode));
	free_all(all);
	exit(all->errcode);
}

int			print_err(t_all *all, int set_err)
{
	(void)set_err;
	if (all->errcode == -1)
	{
		f_write(2, all->spec_err_mess);
		(all->spec_err_mess && *all->spec_err_mess) ? write(2, "\n", 1) : 0;
		return ((g_return = (all->err_unusual != -1 ? all->err_unusual : 1)));
	}
	else if (all->errcode == -3)
	{
		f_write(2, g_emojis[random_emoji(&g_queue)]);
		f_write(2, " \33[1;35m mimishell:\33[0m syntax error near ");
		f_write(2, "unexpected token '");
		!all->line[all->i] ? f_write(2, "newline") :
			write(2, &all->line[all->i], 1);
		if (all->line[all->i] == '>' && all->line[all->i + 1] == '>')
			write(2, &all->line[all->i + 1], 1);
		g_return = 258;
		return (((!f_wr_ch(2, '\'') && !f_wr_ch(2, '\n')) ?
			258 : 258));
	}
	if (all->errcode)
		f_write(2, strerror(all->errcode));
	return ((g_return = all->errcode));
}

int			f_exit(t_all *all)
{
	f_write(2, "exit");
	f_wr_ch(2, '\n');
	ft_ext(all, set_err(all, 0, NULL, -1));
	return (0);
}
