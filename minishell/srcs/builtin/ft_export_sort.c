/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 01:47:07 by kcaraway          #+#    #+#             */
/*   Updated: 2020/12/13 07:47:47 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mimishell.h"

static t_list	*ft_lstcopy(t_list *list)
{
	t_list	*head;
	t_list	*new;

	head = NULL;
	while (list && list->content)
	{
		if (!(new = ft_lstnew(ft_strdup(list->content))))
		{
			ft_lstclear(&head, free);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		list = list->next;
	}
	return (head);
}

static void		ft_lstsort(t_list *lst)
{
	int		sorted;
	t_list	*tmp;
	char	*str;

	sorted = 0;
	while (!sorted)
	{
		tmp = lst;
		sorted = 1;
		while (tmp && tmp->next != NULL)
		{
			if (ft_memcmp(tmp->content, tmp->next->content,\
			ft_strlen(tmp->content) + 1) > 0)
			{
				str = tmp->content;
				tmp->content = tmp->next->content;
				tmp->next->content = str;
				sorted = 0;
				break ;
			}
			tmp = tmp->next;
		}
	}
}

static void		print_envp(t_list *list, int fd)
{
	char	*tmp;

	while (list)
	{
		if (ft_isalpha(*list->content))
		{
			ft_putstr_fd("declare -x ", fd);
			if ((tmp = ft_strchr(list->content, '=')))
			{
				write(fd, list->content, tmp - list->content + 1);
				write(fd, "\"", 1);
				write(fd, tmp + 1, ft_strlen(tmp));
				write(fd, "\"\n", 2);
			}
			else
			{
				ft_putstr_fd(list->content, fd);
				ft_putstr_fd("\n", fd);
			}
		}
		list = list->next;
	}
}

int				sort_lst(t_all *all, t_list **list, int fd)
{
	t_list	*tmp;

	if (!(tmp = ft_lstcopy(*list)))
		return (set_err(all, 12, NULL, -1));
	ft_lstsort(tmp);
	print_envp(tmp, fd);
	ft_lstclear(&tmp, free);
	return (0);
}
