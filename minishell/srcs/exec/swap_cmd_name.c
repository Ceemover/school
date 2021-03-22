/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 00:00:58 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/11 12:21:37 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

static int	check_if_executable(t_all *all, t_cmd *cmd, int fd)
{
	struct stat statbuf;

	if (stat(cmd->argv[0], &statbuf) == -1)
		return (set_err(all, errno, NULL, -1));
	if ((statbuf.st_mode & S_IXUSR) && S_ISDIR(statbuf.st_mode))
	{
		f_write(2, g_emojis[random_emoji(&g_queue)]);
		f_write(2, " \33[1;35m mimishell: \33[0m");
		f_write(2, cmd->argv[0]);
		f_write(2, ": Is a directory\n");
		close(fd);
		return ((cmd->corrupted = 1));
	}
	else if (S_ISREG(statbuf.st_mode) && !(statbuf.st_mode & S_IXUSR))
	{
		f_write(2, g_emojis[random_emoji(&g_queue)]);
		f_write(2, " \33[1;35m mimishell: \33[0m");
		f_write(2, cmd->argv[0]);
		f_write(2, ": Permission denied\n");
		close(fd);
		return ((cmd->corrupted = 1));
	}
	close(fd);
	return (0);
}

static int	no_such_file(t_all *all, t_cmd *cmd, char **found_path, char **name)
{
	f_write(2, g_emojis[random_emoji(&g_queue)]);
	f_write(2, " \33[1;35m mimishell: \33[0m");
	f_write(2, cmd->argv[0]);
	f_write(2, ": No such file or directory\n");
	free2(name, found_path);
	set_err(all, -1, "", 127);
	cmd->corrupted = 1;
	return (1);
}

int			swap_cmd_name(t_all *all, t_cmd *cmd)
{
	char	*name;
	char	*found_path_str;
	int		fd;

	if ((is_built_in(cmd) && ft_memcmp(cmd->argv[0], "env\0", 4)))
		return (0);
	if (!(name = ft_strdup("PATH=")) || scan_envp(all, &name, &found_path_str))
		return (ft_ext(all, set_err(all, 12, NULL, -1)));
	if (found_path_str && cmd->argv[0][0] &&
		(!is_built_in(cmd) && !ft_strchr(cmd->argv[0], '/')))
		return (check_cmd_or_error(all, cmd, &found_path_str, &name));
	else if (!is_built_in(cmd) &&
		(cmd->argv[0] && (((fd = open(cmd->argv[0], O_RDONLY)) > 2))))
		return (free2(&name, &found_path_str) ||
			check_if_executable(all, cmd, fd));
	else if (!found_path_str || (!is_built_in(cmd) &&
			(cmd->argv[0] && (((fd = open(cmd->argv[0], O_RDONLY)) == -1)))))
		return (no_such_file(all, cmd, &found_path_str, &name));
	free2(&name, &found_path_str);
	return (0);
}
