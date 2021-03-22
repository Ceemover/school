/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 00:50:01 by kcaraway          #+#    #+#             */
/*   Updated: 2020/12/11 07:20:26 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

int		ft_env(t_all *all, int fd)
{
	t_list	*tmp;

	tmp = all->envp;
	while (tmp)
	{
		if (ft_strchr(tmp->content, '='))
		{
			ft_putstr_fd(tmp->content, fd);
			ft_putstr_fd("\n", fd);
		}
		tmp = tmp->next;
	}
	return (0);
}
