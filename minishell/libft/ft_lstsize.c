/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 11:31:45 by dbolg             #+#    #+#             */
/*   Updated: 2020/12/11 07:52:26 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int size;

	size = 0;
	if (lst)
	{
		while (lst != 0)
		{
			size++;
			lst = lst->next;
		}
	}
	return (size);
}
