/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:17:02 by kcaraway          #+#    #+#             */
/*   Updated: 2020/12/13 07:50:08 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

static int		write_oldpwd(t_all *all, char *tmp)
{
	t_list	*list;

	list = all->envp;
	if (!tmp)
	{
		if (!ft_strncmp("OLDPWD=", list->content, 7))
		{
			free1(&list->content);
			if (!(list->content = ft_strdup("OLDPWD=")))
				return (free1(&tmp) ? 1 : set_err(all, 12, NULL, -1));
			return (0);
		}
	}
	while (list)
	{
		if (!ft_strncmp("OLDPWD=", list->content, 7))
		{
			free1(&list->content);
			if (!(list->content = ft_strjoin("OLDPWD=", tmp)))
				return (free1(&tmp) ? 1 : set_err(all, 12, NULL, -1));
			return (0);
		}
		list = list->next;
	}
	return (0);
}

static int		write_pwd(t_all *all)
{
	t_list	*list;
	char	*tmp;

	list = all->envp;
	tmp = NULL;
	while (list && list->content)
	{
		if (!ft_strncmp("PWD=", list->content, 4))
		{
			if (!(tmp = ft_strdup(&list->content[4])))
				return (free1(&tmp) ? 1 : set_err(all, 12, NULL, -1));
			break ;
		}
		list = list->next;
	}
	if (tmp != NULL)
	{
		if (write_oldpwd(all, tmp))
			return (1);
		free1(&tmp);
	}
	return (0);
}

static int		error_argv_cd(t_cmd *cmd, t_all *all)
{
	if (cmd->argv[1])
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(cmd->argv[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else
		ft_putstr_fd("cd: HOME not set", 2);
	return (set_err(all, -1, NULL, 1));
}

static int		write_newpwd(t_all *all)
{
	char	*dir;
	t_list	*list;

	list = all->envp;
	if (!(dir = getcwd(NULL, 0)))
		return (set_err(all, errno, NULL, -1));
	while (list)
	{
		if (!(ft_strncmp("PWD=", list->content, 4)))
		{
			free1(&list->content);
			if (!(list->content = ft_strjoin("PWD=", dir)))
				return (free1(&dir) || set_err(all, 12, NULL, -1));
			free1(&dir);
			break ;
		}
		list = list->next;
	}
	return (0);
}

int				ft_cd(t_all *all, t_cmd *cmd)
{
	if (!cmd->argv[1])
	{
		if (write_pwd(all))
			return (1);
		if (chdir((const char *)search_home(all->envp)) == -1)
			return (error_argv_cd(cmd, all));
		return (write_newpwd(all));
	}
	if (chdir(cmd->argv[1]) == -1)
		return (error_argv_cd(cmd, all));
	if (write_pwd(all) || write_newpwd(all))
		return (1);
	return (0);
}
