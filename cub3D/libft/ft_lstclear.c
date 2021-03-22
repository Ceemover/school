/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:21:05 by dbolg             #+#    #+#             */
/*   Updated: 2020/06/02 10:19:57 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	tmp = *lst;
	if (*lst && del)
	{
		ft_lstclear(&(tmp->next), del);
		del(tmp->content);
		free(tmp);
	}
	return ;
}
