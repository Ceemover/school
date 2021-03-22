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
	int		len;
	int		i;

	i = -1;
	tmp = *lst;
	if (*lst && del)
	{
		ft_lstclear(&(tmp->next), del);
		if (tmp->content)
		{
			len = ft_strlen(tmp->content);
			while (++i < len)
				tmp->content[i] = '@';
			del(tmp->content);
			tmp->content = NULL;
		}
		free(tmp);
		tmp = NULL;
	}
	return ;
}
