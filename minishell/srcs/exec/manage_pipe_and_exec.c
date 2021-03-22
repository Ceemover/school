/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pipe_and_exec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 23:51:37 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/12 23:25:12 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

static void	redir_write(t_cmd *cmd, t_all *all)
{
	if (!cmd->write_corrupted)
		if ((cmd->fd_write = open(cmd->file_write, O_WRONLY | O_APPEND)) == -1)
			ft_ext(all, (all->errcode = errno));
	if ((dup2(cmd->fd_write, 1)) == -1)
		ft_ext(all, (all->errcode = errno));
}

static void	redir_read(t_cmd *cmd, t_all *all)
{
	if (!cmd->read_corrupted)
		if ((cmd->fd_read = open(cmd->file_read, O_RDONLY)) == -1)
			ft_ext(all, (all->errcode = errno));
	if ((dup2(cmd->fd_read, 0)) == -1)
		ft_ext(all, (all->errcode = errno));
}

static void	close_fd(t_cmd *cmd)
{
	if (cmd->separator == PIPE)
		close(cmd->fd[1]);
	if (cmd->file_write)
		close(cmd->fd_write);
	if (cmd->file_read)
		close(cmd->fd_read);
	if (cmd->prev && cmd->prev->separator == PIPE)
		close(cmd->prev->fd[0]);
}

int			child_proc(t_cmd *cmd, t_all *all)
{
	if (cmd->separator == PIPE)
		if ((dup2(cmd->fd[1], 1)) == -1)
			ft_ext(all, (all->errcode = errno));
	(cmd->file_write) ? redir_write(cmd, all) : 0;
	if (cmd->prev && cmd->prev->separator == PIPE)
		if ((dup2(cmd->prev->fd[0], 0)) == -1)
			ft_ext(all, (all->errcode = errno));
	(cmd->file_read) ? redir_read(cmd, all) : 0;
	(cmd->corrupted) ? ft_ext(all, 1) : 0;
	if (is_built_in(cmd))
		g_return = execute_built_in(cmd, all);
	else
	{
		if (make_envp_arr(all))
			ft_ext(all, (all->errcode = 12));
		if (cmd->argv0_command)
		{
			if (execve(cmd->argv0_command, cmd->argv, all->tmp_envp) == -1)
				exit(errno);
		}
		else if (execve(cmd->argv[0], cmd->argv, all->tmp_envp) == -1)
			exit(errno);
	}
	exit(g_return);
}

int			manage_pipe(t_cmd *cmd, t_all *all)
{
	pid_t	pid;
	int		status;

	if (cmd->corrupted)
		f_write(2, "sdfsdf");
	if (cmd->corrupted || !ft_memcmp(cmd->argv[0], "exit\0", 5))
		return ((g_return = f_exit(all)) ? 0 : 0);
	if (cmd->separator == PIPE)
		if (pipe(cmd->fd))
			exit(1);
	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
		child_proc(cmd, all);
	else
	{
		waitpid(pid, &status, 0);
		close_fd(cmd);
		WIFEXITED(status) ? (g_return = WEXITSTATUS(status)) : 0;
	}
	return (0);
}
