/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 03:07:25 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/11 17:06:08 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

static int	quote_not_valid(t_all *all)
{
	char	quote;

	quote = all->line[all->i];
	all->i++;
	while (all->line[all->i] && all->line[all->i] != quote)
	{
		if (all->line[all->i] == '\\')
		{
			if (!all->line[all->i + 1] && (all->i++))
				return (set_err(all, SYNTAX_ERR, NULL, -1));
			all->i += 2;
			continue;
		}
		all->i++;
	}
	if (!all->line[all->i])
		return (set_err(all, SYNTAX_ERR, NULL, -1));
	return (0);
}

static int	validate_one_arg(t_all *all)
{
	all->validated = 0;
	while (all->line[all->i] && !ft_strchr(" ;|()<>", all->line[all->i]))
	{
		all->validated = 1;
		if (all->line[all->i] == '\'' || all->line[all->i] == '"')
			if (quote_not_valid(all))
				return (1);
		if (all->line[all->i] == '\\')
		{
			if (!all->line[all->i + 1] && (all->i++))
				return (set_err(all, SYNTAX_ERR, NULL, -1));
			all->i += 2;
			continue;
		}
		all->i++;
	}
	if (all->line[all->i] && ft_strchr("()", all->line[all->i]))
		return (set_err(all, SYNTAX_ERR, NULL, -1));
	return (0);
}

static int	validate_command(t_all *all, int *started)
{
	*started = 0;
	while (all->line[all->i] && !ft_strchr(";|", all->line[all->i]))
	{
		*started = 1;
		if (all->line[all->i] == ' ' && (skip_space(all) ? 1 : 1))
			continue ;
		if (all->line[all->i] && ft_strchr("<>", all->line[all->i]))
		{
			all->i += (all->line[all->i] == '>' && all->line[all->i + 1] == '>')
				? 2 : 1;
			skip_space(all);
			if (validate_one_arg(all))
				return (1);
			if (!all->validated)
				return (set_err(all, SYNTAX_ERR, NULL, -1));
			continue ;
		}
		if (validate_one_arg(all))
			return (1);
		if (!all->validated)
			return (set_err(all, SYNTAX_ERR, NULL, -1));
	}
	return (0);
}

int			validate_line(t_all *all)
{
	int		started;

	started = 0;
	while (all->line[all->i])
	{
		if (all->line[all->i] == ' ')
		{
			skip_space(all);
			continue;
		}
		if (validate_command(all, &started))
			return (1);
		if (!started)
			return (set_err(all, SYNTAX_ERR, NULL, -1));
		if (all->line[all->i] && ft_strchr("|;", all->line[all->i]))
		{
			if (!all->line[++all->i] && all->line[all->i - 1] != ';')
				return (set_err(all, SYNTAX_ERR, NULL, -1));
			started = 0;
		}
	}
	return (0);
}
