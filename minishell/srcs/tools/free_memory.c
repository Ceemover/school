/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 03:13:51 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/11 07:22:36 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

int			flush_all(t_all *all)
{
	if (all->cmd)
		clear_cmd_list(all);
	free1(&all->line);
	all->tmp_envp ? ft_free_arr(all->tmp_envp) : 0;
	all->validated = 0;
	all->filled = 0;
	all->ambiguous_redir = 0;
	all->errcode = 0;
	all->err_unusual = 0;
	all->line = NULL;
	all->spec_err_mess = NULL;
	all->arg_beg = 0;
	all->i = 0;
	all->j = 0;
	all->arg_beg = 0;
	g_sigint = 0;
	return (0);
}

int			free_all(t_all *all)
{
	if (all->cmd)
		clear_cmd_list(all);
	all->envp ? ft_lstclear(&all->envp, free) : 0;
	all->tmp_envp ? ft_free_arr(all->tmp_envp) : 0;
	free1(&all->line);
	return (0);
}
