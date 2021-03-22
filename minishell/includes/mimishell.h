/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mimishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 01:51:43 by kcaraway          #+#    #+#             */
/*   Updated: 2020/12/12 23:47:43 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIMISHELL_H
# define MIMISHELL_H
# include "../libft/libft.h"
# include <signal.h>
# include <search.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# define REDIR_LFT 0
# define SINGLE_REDIR_RHT 1
# define DOUBLE_REDIR_RHT 2
# define IS_REDIR 1
# define IS_NOT_REDIR 0
# define SYNTAX_ERR -3
# define PIPE 1
# define SEMICOLON 2
# define END 0
# define DAUTHER 0
# define INQUOTE 1

extern int g_return;
extern int g_sigint;
extern int g_reading_line;
extern int g_queue;
extern char *g_emojis[30];

typedef	struct		s_file
{
	int				ambiguous_redir;
	char			*filename;
	int				redir;
	struct s_file	*next;
}					t_file;

typedef struct		s_cmd
{
	int				fd[2];
	int				fd_write;
	int				fd_read;
	char			**argv;
	char			*argv0_command;
	int				separator;
	char			*file_write;
	char			*file_read;
	int				redir_write;
	int				redir_read;
	int				corrupted;
	int				write_corrupted;
	int				read_corrupted;
	t_file			*file;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef struct		s_all
{
	char			**tmp_envp;
	int				validated;
	int				filled;
	int				ambiguous_redir;
	int				i;
	int				j;
	int				arg_beg;
	char			*spec_err_mess;
	int				errcode;
	int				err_unusual;
	t_list			*envp;
	char			**argv;
	char			*line;
	t_cmd			*cmd;
}					t_all;

typedef	struct		s_vars
{
	int				remember;
	char			*buf;
	char			ch;
}					t_vars;

/*
**	LISTS	addback.c
*/

t_cmd				*cmd_last(t_cmd *cmd);
void				cmd_addback(t_cmd **lst, t_cmd *new_node);
int					file_addback(t_file **lst, t_file *new_node);

/*
**	LISTS	new_and_clear.c
*/
t_file				*file_new(void *filename, int redir, int ambiguous_redir);
int					new_cmd(t_all *all);
int					clear_cmd_list(t_all *all);

/*
**	TOOLS	errors.c
*/
int					f_exit(t_all *all);
int					print_err(t_all *all, int set_err);
int					ft_ext(t_all *all, int set_err);
int					set_err(t_all *all, int errcode, char *message,
													int err_unusual);
/*
**	TOOLS	free_memory.c
*/
int					flush_all(t_all *all);
int					free_all(t_all *all);
/*
**	TOOLS	strings_arrs.c
*/
int					add_char(char **name, char ch);
int					make_envp_arr(t_all *all);
int					scan_envp(t_all *all, char **name, char **save);
int					make_envp(char **envp, t_all *all);
int					ft_add_str_to_arr(t_cmd *cmd, char *str_to_add);
/*
**	TOOLS	tools.c
*/
int					get_separator_character(t_all *all, t_cmd *cmd);
int					random_emoji(int *queue);
int					init_all(t_all *all, char **envp);
int					turn_ret(int g);
/*
**	TOOLS	is_boolean.c
*/
int					is_single_env(t_all *all, int *i);
int					is_legal_case(char ch);
int					is_built_in(t_cmd *cmd);

/*
**	PARSER	get_line_shell.c
*/
int					make_argument(t_all *all, char **argument, int is_redir);
int					get_line_shell(t_all *all, char **line, int *ret);
/*
**	PARSER	redir.c
*/
int					redir(t_all *all, t_cmd *cmd);
/*
**	PARSER	get_cmd_loop.c
*/
int					make_argument(t_all *all, char **argument, int is_redir);
int					get_cmd_loop(t_all *all, t_cmd *cmd);
/*
**	PARSER	skip_dollar.c
*/
int					skip_dollar(t_all *all, int dbl_qt, int redir);
/*
**	PARSER	skip_quotes_slash_space.c
*/
int					skip_space(t_all *all);
int					skip_slash(t_all *all);
int					skip_double_quote(t_all *all, int redir);
int					skip_single_quote(t_all *all);

/*
**	PARSER	validate_line.c
*/
int					validate_line(t_all *all);

/*
**	EXEC	swap_cmd_name.c
*/
int					swap_cmd_name(t_all *all, t_cmd *cmd);
/*
**	EXEC	swap_cmd_name2.c
*/
int					check_cmd_or_error(t_all *all, t_cmd *cmd,\
							char **found_path_str, char **name);
/*
**	EXEC	manage_files.c
*/
int					manage_files(t_all *all, t_cmd *cmd);
/*
**	EXEC	manage_pipe_and_exec.c
*/
int					manage_pipe(t_cmd *cmd, t_all *all);

/*
**	BUILTIN	builtin_helper.c
*/
int					execute_built_in(t_cmd *cmd, t_all *all);
char				*search_home(t_list *list);
/*
**	BUILTIN
*/
int					ft_cd(t_all *all, t_cmd *cmd);
int					ft_echo(t_cmd *cmd, int fd);
int					ft_env(t_all *all, int fd);
int					ft_export(t_all *all, t_list **lst, t_cmd *cmd, int fd);
int					ft_pwd(int fd);
int					ft_unset(t_list **lst, t_cmd *cmd);

/*
**	BUILTIN ft_export_sort.c
*/
int					sort_lst(t_all *all, t_list **list, int fd);

#endif
