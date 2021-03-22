/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 03:17:16 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/13 07:48:33 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

int g_return;
int g_sigint;
int g_reading_line;
int g_queue;
char *g_emojis[30] = {"😂", "🦆", "⛄️", "🎨", "🦄", "🍆", "🌪 ", "🍕", "🦔", "🍥",\
	"😤", "👻", "🌞", "🤯", "🤪", "🤬", "😆", "😎", "🐥", "🌙", "🦖", "👾", "👹",\
	"🤡", "🐋", "🐰", "🐢", "🌚", "💩", NULL};

static int	parse_commands_and_execute(t_all *all)
{
	t_cmd	*cmd;

	while (all->line[all->i])
	{
		if (new_cmd(all) || !(cmd = cmd_last(all->cmd)))
			return (ft_ext(all, set_err(all, 12, NULL, -1)));
		if (get_cmd_loop(all, cmd))
			return (1);
		get_separator_character(all, cmd);
		if (!cmd->argv)
			if (!cmd->file)
				return (set_err(all, SYNTAX_ERR, NULL, -1));
		manage_files(all, cmd);
		if (!cmd->corrupted && cmd->argv)
			swap_cmd_name(all, cmd);
		if (!cmd->corrupted && cmd->argv && is_built_in(cmd) &&
			cmd->separator != PIPE)
			if ((g_return = execute_built_in(cmd, all)))
				all->errcode == 12 ? ft_ext(all, 1) : print_err(all, 1);
		if (cmd->argv && (!cmd->corrupted &&
			(!is_built_in(cmd) || cmd->separator == PIPE)))
			manage_pipe(cmd, all);
	}
	return (0);
}

static int	get_and_parse_line(t_all *all)
{
	char	*line;
	int		ret;

	line = NULL;
	if (get_line_shell(all, &line, &ret))
		ft_ext(all, 1);
	g_reading_line = 0;
	if (ret == -1)
		return (!free1(&line) && set_err(all, 12, NULL, -1));
	all->line = line;
	if (!ret && !ft_strlen(line))
		return (f_exit(all));
	else if (!ft_strlen(line))
		return (flush_all(all));
	else if (!ret)
		write(1, "\n", 1);
	if (validate_line(all))
		return (print_err(all, 1) && flush_all(all));
	all->i = 0;
	if (parse_commands_and_execute(all))
		return (print_err(all, 1));
	return (flush_all(all));
}

static void	manage_sigquit(void)
{
	f_write(1, "\b\b  \b\b");
}

static void	manage_sigint(void)
{
	g_sigint = 1;
	if (g_reading_line)
	{
		f_write(1, "\b\b  \b\b\n");
		f_write(1, g_emojis[random_emoji(&g_queue)]);
		f_write(1, " \33[1;35m mimishell: \33[0m");
	}
	else
		f_write(1, "\b\b  \b\b");
}

int			main(int argc, char **argv, char **envp)
{
	t_all	all;

	(void)argv;
	g_return = 0;
	g_sigint = 0;
	g_reading_line = 0;
	g_queue = 0;
	(void)argc;
	if (init_all(&all, envp))
		ft_ext(&all, (set_err(&all, 12, NULL, -1)));
	if (signal(SIGINT, (void*)manage_sigint) == SIG_ERR)
		ft_ext(&all, set_err(&all, 4, NULL, -1));
	if (signal(SIGQUIT, (void*)manage_sigquit) == SIG_ERR)
		ft_ext(&all, set_err(&all, 4, NULL, -1));
	while (1)
	{
		f_write(1, g_emojis[random_emoji(&g_queue)]);
		f_write(1, " \33[1;35m mimishell: \33[0m");
		get_and_parse_line(&all);
	}
	return (0);
}
