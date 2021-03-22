/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 03:16:30 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/11 18:35:46 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

int			get_separator_character(t_all *all, t_cmd *cmd)
{
	if (all->line[all->i] == '\0')
		cmd->separator = END;
	if (all->line[all->i] == ';')
		cmd->separator = SEMICOLON;
	if (all->line[all->i] == '|')
		cmd->separator = PIPE;
	all->i += all->line[all->i] ? 1 : 0;
	return (0);
}

int			random_emoji(int *queue)
{
	unsigned int	randomized;
	int				result;

	randomized = *queue;
	randomized *= 1103515245;
	randomized += 12345;
	result = (unsigned int)(randomized / 65536) % 2048;
	randomized *= 1103515245;
	randomized += 12345;
	result <<= 10;
	result ^= (unsigned int)(randomized / 65536) % 1024;
	randomized *= 1103515245;
	randomized += 12345;
	result <<= 10;
	result ^= (unsigned int)(randomized / 65536) % 1024;
	*queue = randomized;
	return (result % 29);
}

int			init_all(t_all *all, char **envp)
{
	int ret;

	all->i = 0;
	all->j = 0;
	all->envp = NULL;
	if ((ret = make_envp(envp, all)))
		return (1);
	all->tmp_envp = NULL;
	all->filled = 0;
	all->ambiguous_redir = 0;
	all->arg_beg = 0;
	all->spec_err_mess = NULL;
	all->line = NULL;
	all->errcode = 0;
	all->err_unusual = -1;
	all->cmd = NULL;
	return (0);
}
