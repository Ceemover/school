/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_built_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 22:10:36 by kcaraway          #+#    #+#             */
/*   Updated: 2020/12/13 07:52:10 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

int			execute_built_in(t_cmd *cmd, t_all *all)
{
	int		fd;

	fd = 1;
	if (cmd->corrupted)
		return (1);
	if (!ft_memcmp(cmd->argv[0], "exit\0", 5))
		return ((g_return = f_exit(all)) ? 1 : 0);
	if (cmd->file_write && !cmd->write_corrupted)
		if ((fd = open(cmd->file_write, O_WRONLY | O_APPEND)) == -1)
			ft_ext(all, (all->errcode = errno));
	if (!ft_memcmp(cmd->argv[0], "echo\0", 5))
		return ((g_return = ft_echo(cmd, fd)) ? 1 : 0);
	else if (!ft_memcmp(cmd->argv[0], "cd\0", 3))
		return ((g_return = ft_cd(all, cmd)) ? 1 : 0);
	else if (!ft_memcmp(cmd->argv[0], "unset\0", 6))
		return ((g_return = ft_unset(&all->envp, cmd)) ? 1 : 0);
	else if (!ft_memcmp(cmd->argv[0], "export\0", 7))
		return ((g_return = ft_export(all, &all->envp, cmd, fd)) ? 1 : 0);
	else if (!ft_memcmp(cmd->argv[0], "env\0", 4))
		return ((g_return = ft_env(all, fd)) ? 1 : 0);
	else if (!ft_memcmp(cmd->argv[0], "pwd\0", 4))
		return ((g_return = ft_pwd(fd)) ? 1 : 0);
	return (0);
}

char		*search_home(t_list *list)
{
	while (list->content)
	{
		if (!ft_strncmp("HOME=", list->content, 5))
		{
			return (&list->content[5]);
		}
		list = list->next;
	}
	return (0);
}
