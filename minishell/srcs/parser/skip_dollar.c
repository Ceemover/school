/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 02:56:48 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/13 07:49:15 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

static int	insrt_str(t_all *all, char **insert_line, int double_quotes)
{
	char	*new;
	char	*tail;

	if (!(tail = ft_strjoin(*insert_line, &all->line[all->i])))
		return (set_err(all, 12, NULL, -1));
	all->line[all->i] = '\0';
	if (!(new = ft_strjoin(all->line, tail)))
		return (!free1(&tail) ? set_err(all, 12, NULL, -1) : 0);
	free1(&tail);
	free1(&all->line);
	all->line = new;
	all->i += double_quotes ? ft_strlen(*insert_line) : 0;
	free1(insert_line);
	return (0);
}

static int	finish_arg(t_all *all)
{
	char	quote;

	quote = 0;
	all->ambiguous_redir = 1;
	while (all->line[all->i] && !ft_strchr(" ;|()", all->line[all->i]))
	{
		if ((all->line[all->i] == '\'' || all->line[all->i] == '"') &&
				(quote = all->line[all->i]))
		{
			while (all->line[++all->i] && all->line[all->i] != quote)
			{
				if (all->line[all->i] == '\\')
				{
					if (!all->line[all->i + 1] && (all->i++))
						return (set_err(all, SYNTAX_ERR, NULL, -1));
					all->i++;
				}
			}
			if (!all->line[all->i])
				return (set_err(all, SYNTAX_ERR, NULL, -1));
		}
		all->i++;
	}
	return ((all->line[all->i] && ft_strchr("()", all->line[all->i])) ?
			set_err(all, SYNTAX_ERR, NULL, -1) : 0);
}

static int	ins_return(t_all *all)
{
	char	*last_return;
	char	*tmp;

	tmp = NULL;
	ft_memmove(&all->line[all->i], &all->line[all->i + 2],
			ft_strlen(&all->line[all->i + 2]) + 2);
	if (!(last_return = ft_itoa(\
	(g_return = (g_return < 0 ? g_return + 262144 : g_return) % 262144))))
		return (set_err(all, 12, NULL, -1));
	if (!(tmp = malloc(sizeof(char) * (ft_strlen(all->line) +
		ft_strlen(last_return) + 1))))
		return (set_err(all, 12, NULL, -1));
	if (all->i != 0)
		ft_memmove(tmp, all->line, all->i);
	ft_memmove(&tmp[all->i], last_return, ft_strlen(last_return));
	ft_memmove(&tmp[all->i + ft_strlen(last_return)], &all->line[all->i],
			ft_strlen(&all->line[all->i]) + 1);
	tmp[ft_strlen(all->line) + ft_strlen(last_return)] = '\0';
	free1(&all->line);
	all->line = tmp;
	all->i += ft_strlen(last_return);
	return (0);
}

static int	get_arg(t_all *all, int *i)
{
	while (all->line[++(*i)])
	{
		if ((all->line[*i] == '?' && *i - all->i == 1 && (*i)++) ||
			(ft_isdigit(all->line[*i]) && (*i - all->i) == 1 && (*i)++) ||
				!is_legal_case(all->line[*i]))
			break ;
	}
	return (0);
}

int			skip_dollar(t_all *all, int dbl_qt, int redir)
{
	int		i;
	char	*name;
	char	*found;
	char	*found_trimmed;

	i = all->i;
	get_arg(all, &i);
	if (i - all->i == 1 || (i - all->i == 2 && all->line[i - 1] == '?'))
		return (i - all->i == 1 ? (all->i++ * 0) : ins_return(all));
	if (ft_strncpy(&name, &all->line[all->i + 1], i - all->i - 1) ||
			add_char(&name, '='))
		return (set_err(all, 12, NULL, -1));
	if (scan_envp(all, &name, &found))
		return (free1(&name) || set_err(all, 12, NULL, -1));
	found_trimmed = NULL;
	if (found && !dbl_qt && (!(found_trimmed = ft_strtrim(found, " ")) ||
		free1(&found)))
		return (free2(&name, &found));
	found = found_trimmed ? found_trimmed : found;
	if (found && redir && (!dbl_qt && ft_strchr(found, ' ')) && (all->i = i))
		return (free2(&name, &found) || finish_arg(all));
	ft_memmove(&all->line[all->i], &all->line[i], ft_strlen(&all->line[i]) + 1);
	if (found && insrt_str(all, &found, dbl_qt))
		return (free2(&name, &found) || set_err(all, 12, NULL, -1));
	return (free2(&name, &found));
}
