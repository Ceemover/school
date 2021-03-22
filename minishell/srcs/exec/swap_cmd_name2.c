/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd_name2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 00:19:50 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/11 12:12:12 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

static int		add_to_path(t_list **path, char **folder, char **tmp)
{
	t_list	*node;

	if (!(node = ft_lstnew(*folder)))
	{
		ft_lstclear(path, free);
		free2(tmp, folder);
		return (1);
	}
	ft_lstadd_back(path, node);
	free1(tmp);
	*folder = NULL;
	return (0);
}

static int		make_path_list(char *found, t_list **path, t_cmd *cmd)
{
	int		i;
	int		beg;
	char	*folder;
	char	*tmp;

	i = 0;
	while (found[i])
	{
		beg = i;
		while (found[i] && found[i] != ':')
			i++;
		if (ft_strncpy(&folder, &found[beg], i - beg) ||
			!(tmp = ft_strjoin(folder, "/")) ||
			(!free1(&folder) && !(folder = ft_strjoin(tmp, cmd->argv[0]))))
		{
			free2(&folder, &tmp);
			ft_lstclear(path, free);
			return (1);
		}
		if (add_to_path(path, &folder, &tmp))
			return (1);
		i += found[i] ? 1 : 0;
	}
	return (free1(&tmp));
}

static int		is_invalid_named_cmd2(t_all *all, t_cmd *cmd, t_list *lst,
															t_list **path)
{
	int		fd;
	char	*tmp;

	while (lst)
	{
		if (lst->content && (fd = open(lst->content, O_RDONLY)) != -1)
		{
			close(fd);
			if (!(tmp = ft_strdup(lst->content)))
			{
				free1(&tmp);
				ft_lstclear(path, free);
				return (set_err(all, 12, NULL, -1));
			}
			cmd->argv0_command = tmp;
			tmp = NULL;
			ft_lstclear(path, free);
			return (0);
		}
		lst = lst->next;
	}
	ft_lstclear(path, free);
	return (0);
}

static int		is_invalid_named_cmd(t_cmd *cmd, t_all *all)
{
	char	*name;
	char	*found;
	t_list	*path;
	t_list	*lst;

	path = NULL;
	lst = NULL;
	if (!(name = ft_strdup("PATH=")))
		return (set_err(all, 12, NULL, -1));
	if (scan_envp(all, &name, &found))
		return (set_err(all, 12, NULL, -1));
	if (!*found && free1(&cmd->argv[0]))
		return ((cmd->argv[0] = found) ? 0 : 0);
	if (make_path_list(found, &path, cmd))
		return (!free1(&found) && set_err(all, 12, NULL, -1));
	lst = path;
	if (is_invalid_named_cmd2(all, cmd, lst, &path))
		return (!free1(&found));
	free1(&found);
	return (0);
}

int				check_cmd_or_error(t_all *all, t_cmd *cmd,
							char **found_path_str, char **name)
{
	if (!is_built_in(cmd) && cmd->argv[0][0])
	{
		if (is_invalid_named_cmd(cmd, all))
		{
			free2(name, found_path_str);
			ft_ext(all, 1);
		}
	}
	if (is_built_in(cmd) || !cmd->argv[0][0] || (!cmd->argv0_command))
	{
		f_write(2, g_emojis[random_emoji(&g_queue)]);
		f_write(2, " \33[1;35m mimishell: \33[0m");
		f_write(2, cmd->argv[0]);
		f_write(2, ": command not found\n");
		free2(name, found_path_str);
		cmd->corrupted = 1;
		set_err(all, -1, "", 127);
		return (1);
	}
	free2(name, found_path_str);
	return (0);
}
