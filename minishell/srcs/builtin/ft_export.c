/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:01:09 by kcaraway          #+#    #+#             */
/*   Updated: 2020/12/11 21:23:38 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

static int	not_valid_argv(t_all *all, char *str)
{
	int		i;

	i = 0;
	if (ft_isalpha(str[i]) || str[i] == '_')
	{
		while (str[i] && ((ft_isalpha(str[i])) || (ft_isdigit(str[i]))
		|| str[i] == '_'))
			i++;
		if (str[i] == '\0' || str[i] == '=')
			return (0);
	}
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (set_err(all, -1, NULL, 1));
}

static int	ft_search(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] && s2[i] && s1[i] == s2[i] && s2[i] != '=')
			i++;
		if ((s1[i] == '\0' || s1[i] == '=') && (s2[i] == '\0' || s2[i] == '='))
			return (1);
	}
	return (0);
}

static int	ft_search_name(t_list **list, char *str)
{
	t_list *lst;

	lst = *list;
	while (lst)
	{
		if (ft_search(lst->content, str))
		{
			free1(&lst->content);
			if (!(lst->content = ft_strdup(str)))
				return (-1);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

static int	ft_export_2(t_list **list, t_cmd *cmd, int i)
{
	char	*tmp;
	t_list	*node;

	tmp = NULL;
	node = NULL;
	if (!(tmp = ft_strdup(cmd->argv[i])))
	{
		ft_lstclear(list, free);
		return (1);
	}
	if (!(node = ft_lstnew(tmp)))
	{
		free1(&tmp);
		ft_lstclear(list, free);
		return (1);
	}
	ft_lstadd_back(list, node);
	return (0);
}

int			ft_export(t_all *all, t_list **lst, t_cmd *cmd, int fd)
{
	int		i;
	t_list	*list;
	int		ret;

	list = *lst;
	i = 1;
	if (cmd->argv[i])
	{
		while (cmd->argv[i])
		{
			if (!not_valid_argv(all, cmd->argv[i]))
			{
				if (!(ret = ft_search_name(&list, cmd->argv[i])) &&
					ft_export_2(&list, cmd, i))
					return (set_err(all, 12, NULL, -1));
				else if (ret == -1)
					return (set_err(all, 12, NULL, -1));
			}
			i++;
		}
	}
	else if (sort_lst(all, lst, fd))
		return (set_err(all, 1, NULL, -1));
	return (all->errcode ? 1 : 0);
}
