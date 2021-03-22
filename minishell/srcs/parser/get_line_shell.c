/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_shell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 02:47:56 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/11 07:21:53 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

static int	process_eol(t_vars *vars, char **line, int *ret)
{
	if (g_sigint)
	{
		vars->remember = ft_strlen(vars->buf);
		g_sigint = 0;
	}
	if (vars->remember > 0)
	{
		if (ft_strncpy(line, &vars->buf[vars->remember],
					ft_strlen(&vars->buf[vars->remember])))
			return (!free1(&vars->buf));
		free1(&vars->buf);
	}
	else
		*line = vars->buf;
	return (!(*ret = 1));
}

static int	process_read(t_vars *vars, t_all *all, char **line, int *ret)
{
	if ((*ret = read(0, &vars->ch, 1)) == -1)
		return (set_err(all, 77, NULL, -1));
	if (*ret > 0 && vars->ch != '\n')
		if (add_char(&vars->buf, vars->ch))
			return (!free1(&vars->buf));
	if (*ret > 0 && vars->ch == '\n')
		return (process_eol(vars, line, ret));
	else if (!*ret && !*vars->buf)
		return (!(*line = vars->buf));
	else if (!*ret && *vars->buf)
		return (!(*line = vars->buf));
	return (-1);
}

int			get_line_shell(t_all *all, char **line, int *ret)
{
	int		res;
	t_vars	vars;

	vars.remember = 0;
	vars.buf = NULL;
	vars.ch = 0;
	*ret = 0;
	if (!(vars.buf = ft_calloc(1, sizeof(char))))
		return (set_err(all, 12, NULL, -1));
	while (1)
	{
		g_reading_line = 1;
		if (g_sigint)
		{
			vars.remember = ft_strlen(vars.buf) - 1;
			g_sigint = 0;
		}
		if ((res = process_read(&vars, all, line, ret)) != -1)
			return (res);
	}
	return (0);
}
