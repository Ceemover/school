/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 23:50:01 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/13 04:09:15 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

static int	manage_files2(t_all *all, t_cmd *cmd, t_file *file)
{
	if (file->redir == SINGLE_REDIR_RHT &&
		((cmd->fd[1] = open(file->filename, O_CREAT | O_TRUNC, 0644)) == -1))
		return ((cmd->write_corrupted = 1) && set_err(all, -1, strerror(2), -1)\
			&& (cmd->corrupted = 1));
	else if (file->redir == DOUBLE_REDIR_RHT &&
		((cmd->fd[1] = open(file->filename, O_CREAT, 0644)) == -1))
		return ((cmd->write_corrupted = 1) && set_err(all, -1, strerror(2), -1)\
			&& (cmd->corrupted = 1));
	else if (file->redir == REDIR_LFT &&\
		((cmd->fd[0] = open(file->filename, O_RDONLY)) == -1))
	{
		return ((cmd->corrupted = 1) && set_err(all, -1, strerror(2), -1)\
			&& (cmd->read_corrupted = 1));
	}
	if (file->redir && (cmd->file_write = file->filename))
		close(cmd->fd[1]);
	else if (!file->redir && (cmd->file_read = file->filename))
		close(cmd->fd[0]);
	return (0);
}

int			manage_files(t_all *all, t_cmd *cmd)
{
	t_file	*file;

	file = cmd->file;
	while (file)
	{
		if (file->ambiguous_redir && (cmd->corrupted = 1))
		{
			file->redir ? (cmd->write_corrupted = 1) : 0;
			file->redir ? 0 : (cmd->read_corrupted = 1);
			f_write(2, g_emojis[random_emoji(&g_queue)]);
			f_write(2, " \33[1;35m mimishell: \33[0m");
			f_write(2, file->filename);
			return (f_write(2, ": ambiguous redirect\n"));
		}
		else if (manage_files2(all, cmd, file))
			return (0);
		file = file->next;
	}
	return (0);
}
