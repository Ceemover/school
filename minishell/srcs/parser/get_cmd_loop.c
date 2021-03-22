/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 00:33:30 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/13 04:09:52 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

static int	malloc_argument(t_all *all, char **argument)
{
	if (!all->filled)
		*argument = NULL;
	else if (all->filled &&\
			!(*argument = ft_substr(all->line, all->arg_beg,
			all->i - all->arg_beg)))
		return (set_err(all, 12, NULL, -1));
	all->filled = 0;
	return (0);
}

int			make_argument(t_all *all, char **argument, int is_redir)
{
	all->arg_beg = all->i;
	*argument = NULL;
	while (all->line[all->i] && !ft_strchr("|><; ", all->line[all->i]))
	{
		all->filled = 1;
		if ((all->line[all->i] == '(' || all->line[all->i] == ')'))
			return (set_err(all, -3, NULL, -1));
		if (all->line[all->i] == '\'' || all->line[all->i] == '"')
		{
			if (all->line[all->i] == '\'' ? skip_single_quote(all) :
					skip_double_quote(all, is_redir))
				return (1);
			continue;
		}
		else if (all->line[all->i] == '$' || all->line[all->i] == '\\')
		{
			if (all->line[all->i] == '$' ? skip_dollar(all, 0, is_redir) :
				skip_slash(all))
				return (1);
			continue;
		}
		all->i++;
	}
	return (malloc_argument(all, argument));
}

int			get_cmd_loop(t_all *all, t_cmd *cmd)
{
	char	*argument;

	while (all->line[all->i] && all->line[all->i] != '|' &&
			all->line[all->i] != ';')
	{
		argument = NULL;
		if (all->line[all->i] == ' ' && (skip_space(all) ? 1 : 1))
			continue;
		if (all->line[all->i] == '>' || all->line[all->i] == '<')
		{
			if (redir(all, cmd))
				return (all->errcode == 12 ? ft_ext(all, 1) : 1);
			continue;
		}
		else if (make_argument(all, &argument, IS_NOT_REDIR))
			return (all->errcode == 12 ? ft_ext(all, 1) : 1);
		if (argument == NULL)
			return (set_err(all, SYNTAX_ERR, NULL, -1));
		else if (ft_add_str_to_arr(cmd, argument))
			return (ft_ext(all, set_err(all, 12, NULL, -1)));
	}
	return (0);
}
