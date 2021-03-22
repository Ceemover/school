/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_arrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 03:15:19 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/11 21:21:51 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

int			add_char(char **name, char ch)
{
	char	*new_name;

	if (!(new_name = malloc(sizeof(char) * ft_strlen(*name) + 2)))
	{
		free1(name);
		return (1);
	}
	ft_memmove(new_name, *name, ft_strlen(*name));
	new_name[ft_strlen(*name)] = ch;
	new_name[ft_strlen(*name) + 1] = '\0';
	free1(name);
	*name = new_name;
	return (0);
}

int			make_envp_arr(t_all *all)
{
	char	**new;
	t_list	*tmp;
	int		i;

	if (all->tmp_envp)
		ft_free_arr(all->tmp_envp);
	if (!(new = malloc(sizeof(char *) * (ft_lstsize(all->envp) + 1))))
		return (set_err(all, 12, NULL, -1));
	tmp = all->envp;
	i = 0;
	while (tmp)
	{
		if (!(new[i] = ft_strdup(tmp->content)))
		{
			ft_free_arr(new);
			return (set_err(all, 12, NULL, -1));
		}
		i++;
		tmp = tmp->next;
	}
	new[i] = NULL;
	all->tmp_envp = new;
	return (0);
}

int			scan_envp(t_all *all, char **name, char **save)
{
	char	*found;
	t_list	*lst;

	lst = all->envp;
	found = NULL;
	*save = NULL;
	while (lst)
	{
		if (lst->content)
		{
			if ((found = ft_strnstr(lst->content, *name,
				ft_strlen(lst->content))) && found == lst->content)
			{
				if (!(*save = ft_strdup(found + ft_strlen(*name))))
					return (!free1(name) && set_err(all, 12, NULL, -1));
				return (free1(name));
			}
		}
		lst = lst->next;
	}
	free1(name);
	return (0);
}

int			make_envp(char **envp, t_all *all)
{
	int		i;
	t_list	*node;
	char	*line;

	i = -1;
	while (envp[++i])
	{
		if (!(line = ft_strdup(envp[i])))
			return ((all->errcode = 12) ? 1 : 1);
		if (!(node = ft_lstnew(line)))
			return (!free1(&line) && set_err(all, 12, NULL, -1));
		ft_lstadd_back(&(all->envp), node);
	}
	return (0);
}

int			ft_add_str_to_arr(t_cmd *cmd, char *str_to_add)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	while (cmd->argv && cmd->argv[i])
		i++;
	if (!(new = malloc(sizeof(char*) * (i + 2))))
		return (1);
	j = 0;
	while (cmd->argv && (j < i))
	{
		new[j] = (cmd->argv[j]);
		j++;
	}
	new[i] = str_to_add;
	new[i + 1] = NULL;
	if (cmd->argv)
		free(cmd->argv);
	cmd->argv = new;
	return (0);
}
