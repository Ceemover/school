/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_boolean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 03:14:11 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/12 23:47:38 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

int			is_legal_case(char ch)
{
	if (ft_isalnum(ch) || ch == '_')
		return (1);
	return (0);
}

int			is_single_env(t_all *all, int *i)
{
	(*i)++;
	while (all->line[*i] && is_legal_case(all->line[*i]))
		(*i)++;
	if (!all->line[*i] || ft_strchr("|; ", all->line[*i]))
		return (1);
	return (0);
}

int			is_built_in(t_cmd *cmd)
{
	if (!ft_memcmp(cmd->argv[0], "exit\0", 5) ||
		!ft_memcmp(cmd->argv[0], "echo\0", 5) ||
		!ft_memcmp(cmd->argv[0], "cd\0", 3) ||
		!ft_memcmp(cmd->argv[0], "unset\0", 6) ||
		!ft_memcmp(cmd->argv[0], "export\0", 7) ||
		!ft_memcmp(cmd->argv[0], "env\0", 4) ||
		!ft_memcmp(cmd->argv[0], "pwd\0", 4))
		return (1);
	return (0);
}
