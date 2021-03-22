/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_and_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 00:24:01 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/11 07:21:40 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

static t_cmd	*cmd_new(void)
{
	t_cmd	*lst;

	lst = (t_cmd*)malloc(sizeof(t_cmd));
	if (!lst)
		return (0);
	lst->argv0_command = NULL;
	lst->next = NULL;
	lst->prev = NULL;
	lst->file = NULL;
	lst->fd_write = -1;
	lst->fd_read = -1;
	lst->argv = NULL;
	lst->separator = -1;
	lst->file_read = NULL;
	lst->file_write = NULL;
	lst->redir_read = 0;
	lst->redir_write = 0;
	lst->corrupted = 0;
	lst->write_corrupted = 0;
	lst->read_corrupted = 0;
	return (lst);
}

int				new_cmd(t_all *all)
{
	t_cmd	*node;

	if (!(node = cmd_new()))
		return (set_err(all, 12, NULL, -1));
	cmd_addback(&(all->cmd), node);
	return (0);
}

t_file			*file_new(void *filename, int redir, int ambiguous_redir)
{
	t_file	*lst;

	lst = (t_file*)malloc(sizeof(t_file));
	if (!lst)
		return (0);
	lst->ambiguous_redir = ambiguous_redir;
	lst->filename = filename;
	lst->redir = redir;
	lst->next = NULL;
	return (lst);
}

static void		file_clear(t_file **lst, void (*del)(void *))
{
	t_file	*tmp;

	tmp = *lst;
	if (*lst && del)
	{
		file_clear(&(tmp->next), del);
		del(tmp->filename);
		tmp->filename = NULL;
		free(tmp);
	}
	return ;
}

int				clear_cmd_list(t_all *all)
{
	t_cmd	*tmp;

	while (all->cmd)
	{
		if (all->cmd->file)
			file_clear(&all->cmd->file, free);
		all->cmd->prev = NULL;
		if (all->cmd->argv)
			ft_free_arr(all->cmd->argv);
		free1(&all->cmd->argv0_command);
		tmp = all->cmd;
		all->cmd = all->cmd->next;
		tmp->next = NULL;
		if (tmp)
			free(tmp);
		tmp = NULL;
	}
	return (0);
}
