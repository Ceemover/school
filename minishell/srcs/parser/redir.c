/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 00:25:13 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/13 04:08:36 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

static int	is_var_only(t_all *all, int *i)
{
	*i = all->i;
	while (all->line[*i] && !ft_strchr(" |;", all->line[*i]))
	{
		if (all->line[*i] == '$' && all->line[*i + 1] &&
				is_legal_case(all->line[*i + 1]) && is_single_env(all, i))
			return (1);
		else if (all->line[*i] == '\'')
			while (all->line[*i] && all->line[*i] != '\'')
				i++;
		else if (all->line[*i] == '"' && all->line[++(*i)])
			while (all->line[*i] && all->line[*i] != '"')
				*i += (all->line[*i] &&
						all->line[*i] == '\\' && all->line[*i + 1]) ? 2 : 1;
		*i += (all->line[*i] && all->line[*i] == '\\' && all->line[*i + 1])
			? 2 : 1;
	}
	return (0);
}

static int	check_file(t_all *all, char **tmp, char **argument,
			int is_single_var)
{
	if (!*argument)
		return (!free1(tmp) && set_err(all, SYNTAX_ERR, NULL, -1));
	else if (!**argument && is_single_var && (all->ambiguous_redir = 1))
		return (free1(argument) || !(*argument = *tmp));
	else if (!**argument && !is_single_var)
		return (free1(tmp));
	else if (**argument && all->ambiguous_redir)
		return (free1(argument) || !(*argument = *tmp));
	else
		free1(tmp);
	return (0);
}

int			redir(t_all *all, t_cmd *cmd)
{
	char	*file;
	int		redir;
	t_file	*node;
	int		is_single_var;
	char	*tmp;

	is_single_var = 0;
	tmp = NULL;
	redir = all->line[all->i] == '<' ? REDIR_LFT : SINGLE_REDIR_RHT;
	if ((redir && all->line[all->i + 1] == '>') && (redir = DOUBLE_REDIR_RHT))
		ft_memmove(&all->line[all->i],\
				&all->line[all->i + 2], ft_strlen(&all->line[all->i + 2]) + 1);
	else
		ft_memmove(&all->line[all->i],\
				&all->line[all->i + 1], ft_strlen(&all->line[all->i + 1]) + 1);
	if ((skip_space(all) || 1) && (is_single_var = is_var_only(all,\
		&all->j) || 1) && ft_strncpy(&tmp, &all->line[all->i], all->j - all->i))
		return (set_err(all, 12, NULL, -1));
	if (make_argument(all, &file, IS_REDIR))
		return (!free1(&tmp));
	if (check_file(all, &tmp, &file, is_single_var))
		return (1);
	if (!(node = file_new(file, redir, all->ambiguous_redir)))
		return (free1(&file) || set_err(all, 12, NULL, -1));
	return (file_addback(&(cmd->file), node) || (all->ambiguous_redir = 0));
}
