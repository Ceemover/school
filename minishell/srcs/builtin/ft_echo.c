/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 23:44:10 by kcaraway          #+#    #+#             */
/*   Updated: 2020/12/11 15:38:15 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

int		ft_echo(t_cmd *cmd, int fd)
{
	int	i;
	int	flag;

	i = 1;
	flag = 1;
	while (cmd->argv[i] && !(ft_memcmp(cmd->argv[i], "-n\0", 3)))
	{
		flag = 0;
		i++;
	}
	while (cmd->argv[i])
	{
		ft_putstr_fd(cmd->argv[i], fd);
		if (cmd->argv[++i])
			ft_putstr_fd(" ", fd);
	}
	if (flag)
		ft_putstr_fd("\n", fd);
	return (0);
}
