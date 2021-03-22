/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_quotes_slash_space.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 03:01:41 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/11 07:22:15 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

int			skip_space(t_all *all)
{
	int		j;

	j = 0;
	while (all->line[all->i] == ' ')
	{
		j++;
		all->i++;
	}
	return (j);
}

int			skip_slash(t_all *all)
{
	int		i;
	int		slashes;
	char	esc_char;
	int		slashes_ttl;

	i = all->i;
	slashes_ttl = 1;
	while (all->line[++i] == '\\')
		slashes_ttl++;
	esc_char = all->line[i];
	if (slashes_ttl % 2 && !esc_char)
		return (set_err(all, -1, "missing escape sequence character", -1));
	slashes = slashes_ttl / 2;
	ft_memmove(&all->line[all->i], &all->line[all->i + slashes],\
		ft_strlen(&all->line[all->i + slashes]) + 1);
	all->i += slashes;
	if (slashes_ttl % 2)
	{
		ft_memmove(&all->line[all->i], &all->line[all->i + 1],\
			ft_strlen(&all->line[all->i + 1]) + 1);
		all->i++;
	}
	return (0);
}

int			skip_double_quote(t_all *all, int redir)
{
	ft_memmove(&all->line[all->i], &all->line[all->i + 1],
			ft_strlen(&all->line[all->i + 1]) + 1);
	while (all->line[all->i] && all->line[all->i] != '"')
	{
		if (all->line[all->i] == '$')
		{
			if (skip_dollar(all, INQUOTE, redir))
				return (1);
			continue;
		}
		if (all->line[all->i] == '\\')
		{
			skip_slash(all);
			continue;
		}
		all->i++;
	}
	if (!all->line[all->i])
		return (set_err(all, SYNTAX_ERR, NULL, -1));
	ft_memmove(&all->line[all->i], &all->line[all->i + 1],
			ft_strlen(&all->line[all->i + 1]) + 1);
	return (0);
}

int			skip_single_quote(t_all *all)
{
	int		i;

	i = all->i;
	while (all->line[++i])
		if (all->line[i] == '\'')
			break ;
	if (!all->line[i])
		return (set_err(all, -1, "unclosed single quote", 1));
	ft_memmove(&all->line[i], &all->line[i + 1],
		ft_strlen(&all->line[i + 1]) + 1);
	ft_memmove(&all->line[all->i], &all->line[all->i + 1],
		ft_strlen(&all->line[all->i + 1]) + 1);
	all->i = i - 1;
	return (0);
}
