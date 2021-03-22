/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 00:51:58 by kcaraway          #+#    #+#             */
/*   Updated: 2020/12/11 15:38:30 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

int		ft_pwd(int fd)
{
	char	*dir;

	if (!(dir = getcwd(NULL, 0)))
		return (1);
	ft_putstr_fd(dir, fd);
	ft_putstr_fd("\n", fd);
	free(dir);
	return (0);
}
