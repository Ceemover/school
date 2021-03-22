/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 08:01:37 by kcaraway          #+#    #+#             */
/*   Updated: 2020/12/11 16:55:04 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

static int	ft_del_unset(t_cmd *cmd, t_list **tmp, int i)
{
	t_list	*tmp1;
	t_list	*copy;

	tmp1 = *tmp;
	copy = tmp1->next;
	if (copy && !ft_strncmp(copy->content, cmd->argv[i],\
	ft_strlen(cmd->argv[i])) && (copy->content[ft_strlen(cmd->argv[i])]\
	== '=' || !(copy->content[ft_strlen(cmd->argv[i])])))
	{
		tmp1->next = tmp1->next->next;
		ft_lstdelone(copy, free);
		return (1);
	}
	return (0);
}

int			ft_unset(t_list **lst, t_cmd *cmd)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (cmd->argv[++i])
	{
		tmp = *lst;
		if (cmd->argv[i] && tmp && ft_strncmp(tmp->content,\
		cmd->argv[i], ft_strlen(cmd->argv[i])) &&\
		(tmp->content[ft_strlen(cmd->argv[i])] == '=' ||\
		!(tmp->content[ft_strlen(cmd->argv[i])])))
		{
			lst = &tmp->next;
			ft_lstdelone(tmp, free);
			tmp = NULL;
		}
		while (cmd->argv[i] && tmp && tmp->next)
		{
			if (ft_del_unset(cmd, &tmp, i))
				break ;
			tmp = tmp->next;
		}
	}
	return (0);
}
