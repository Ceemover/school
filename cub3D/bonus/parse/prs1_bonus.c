/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:26:35 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/28 19:26:37 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

static char	*check(char ch, t_all *all)
{
	if (ch == 'r')
		return (all->w == -1 ? OK : "not ok");
	if (ch == 'n')
		return ((all->txtrs.no ? "not ok" : OK));
	if (ch == 's')
		return ((all->txtrs.so ? "not ok" : OK));
	if (ch == 'e')
		return ((all->txtrs.ea ? "not ok" : OK));
	if (ch == 'w')
		return ((all->txtrs.we ? "not ok" : OK));
	if (ch == 'f')
		return (all->txtrs.f == -1 && !all->txtrs.f_fl ? OK : "not ok");
	if (ch == 'c')
		return (all->txtrs.c == -1 && !all->txtrs.c_fl ? OK : "not ok");
	if (ch == 'z')
		return ((all->txtrs.s ? "not ok" : OK));
	return ("not ok");
}

static char	*realloc_ch(char **ln, int new_size_index, char filler)
{
	char		*s;

	if (!(s = ft_calloc((new_size_index + 2), sizeof(char))))
		return ("malloc failed at realloc_ch function");
	ft_memset(s, filler, new_size_index + 1);
	ft_memmove(s, *ln, ft_strlen(*ln));
	free(*ln);
	*ln = s;
	return (OK);
}

static char	*make_map(t_list **head, int size, t_all *all)
{
	int			i;
	int			end_index;
	t_list		*tmp;

	i = -1;
	tmp = *head;
	if (!(all->map = ft_calloc(size + 1, sizeof(char *))))
		return ("malloc failed at make_map function");
	tmp = *head;
	while (tmp)
	{
		if ((end_index = ft_strlen(tmp->content) - 1) < all->m.max_rht)
		{
			if (realloc_ch(&tmp->content, all->m.max_rht, ' '))
				return ("malloc failed at make_map function");
		}
		end_index = all->m.max_rht;
		if (!(all->map[++i] = ft_substr(tmp->content,
			all->m.max_lft, end_index + 1)))
			return ("malloc_failed at make_map function");
		tmp = tmp->next;
	}
	all->map[++i] = NULL;
	return (OK);
}

static char	*sort_prs(t_all *all, char **ln)
{
	if (**ln == 'R')
		return (!check('r', all) ? prs_r(all, ln) : "double resolution");
	else if (**ln == 'N' && *(*ln + 1) == 'O')
		return (!check('n', all) ? prs_txtr(all, ln, 'n') : "2x NO config");
	else if (**ln == 'S' && *(*ln + 1) == 'O')
		return (!check('s', all) ? prs_txtr(all, ln, 's') : "2x SO config");
	else if (**ln == 'E' && *(*ln + 1) == 'A')
		return (!check('e', all) ? prs_txtr(all, ln, 'e') : "2x EA config");
	else if (**ln == 'W' && *(*ln + 1) == 'E')
		return (!check('w', all) ? prs_txtr(all, ln, 'w') : "2x WE config");
	else if (**ln == 'F')
		return (!check('f', all) ? pars_f_and_c(all, ln, 'f') : "2x F config");
	else if (**ln == 'C')
		return (!check('c', all) ? pars_f_and_c(all, ln, 'c') : "2x C config");
	else if (**ln == 'S')
		return (!check('z', all) ? prs_txtr(all, ln, 'z') : "2x S config");
	else if (**ln == '\0' && !all->m.parsed)
		return (f_ree(ln, ln, ln) ? OK : OK);
	else if (**ln && ft_strchr(" 1", **ln))
		return (!complete(all) ?
		"missing elements in conf. file before map" : prs_m(all, ln));
	else
		f_ree(ln, ln, ln);
	return (all->m.parsed ? "bad map format" : "bad conf. file format");
}

char		*prs_file(t_all *all, int fd)
{
	char		*line;
	char		*ret;
	int			gnl;

	line = NULL;
	while ((gnl = get_next_line(fd, &line)) > -2)
	{
		if (gnl == -1)
			return ("malloc failed at get_next_line");
		if ((ret = sort_prs(all, &line)))
		{
			line ? f_ree(&line, &line, &line) : 0;
			return (ret);
		}
		if (gnl == 0)
			break ;
	}
	if (!(complete(all) && all->m.parsed))
		return ("missing configurations");
	if ((ret = make_map(&all->m.tmp, ft_lstsize(all->m.tmp), all)))
		return (ret);
	if ((ret = val_map(all)) || fill_map(all) || close(fd))
		return (ret);
	return (OK);
}
