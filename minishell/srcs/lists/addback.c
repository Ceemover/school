/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addback.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 00:21:33 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/11 07:21:29 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

static t_file	*file_last(t_file *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int				file_addback(t_file **lst, t_file *new)
{
	t_file	*temp;

	if (!lst || !new)
		return (0);
	if (!*lst)
	{
		*lst = new;
		return (0);
	}
	temp = file_last(*lst);
	temp->next = new;
	return (0);
}

t_cmd			*cmd_last(t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}

void			cmd_addback(t_cmd **lst, t_cmd *new)
{
	t_cmd	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = cmd_last(*lst);
	temp->next = new;
	new->prev = temp;
}
