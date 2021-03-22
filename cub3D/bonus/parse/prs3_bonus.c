/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:26:50 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/28 19:26:52 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

static char	*prs_rgb(char *ln, int *i, int *col, char shade)
{
	int			j;
	char		ch;

	*col = 0;
	if (ln[*i] == '-')
		return ("the color in rgb config is not 0-255");
	if (ln[*i] == '+')
		*i += 1;
	j = *i;
	while (ft_isdigit(ln[j]))
		j++;
	if (j - *i == 0 || (j - *i) > 3 || (shade == 'b' && ln[j] != '\0'))
		return ("bad color configuration formatting");
	ch = ln[j];
	ln[j] = '\0';
	*col = ft_atoi(&ln[*i]);
	ln[j] = ch;
	*i = j;
	skip_space(ln, i);
	return (*col > 255 ? "bad color configuration formatting" : OK);
}

static char	*extract_rgb(char **ln, int *rgb, t_all *all)
{
	int			r;
	int			g;
	int			b;
	char		*ret;

	all->tmp = 1;
	skip_space(*ln, &all->tmp);
	if ((ret = (prs_rgb(*ln, &all->tmp, &r, 'r'))))
		return (ret);
	if (*(*ln + all->tmp) == ',')
		all->tmp++;
	else
		return ("bad color configuration formatting");
	skip_space(*ln, &all->tmp);
	if ((ret = (prs_rgb(*ln, &all->tmp, &g, 'g'))))
		return (ret);
	if (*(*ln + all->tmp) == ',')
		all->tmp++;
	else
		return ("bad color configuration formatting");
	skip_space(*ln, &all->tmp);
	if ((ret = (prs_rgb(*ln, &all->tmp, &b, 'b'))))
		return (ret);
	*rgb = create_trgb(0, r, g, b);
	return (OK);
}

char		*pars_f_and_c(t_all *all, char **ln, char side)
{
	char		*ret;
	int			rgb;

	rgb = -1;
	if (ft_strnstr(*ln, ".xpm", ft_strlen(*ln)))
	{
		if (side == 'f')
			all->txtrs.f_fl = 1;
		else
			all->txtrs.c_fl = 1;
		ret = prs_txtr_f_c(all, ln, side);
		return (ret);
	}
	if ((ret = extract_rgb(ln, &rgb, all)))
	{
		f_ree(ln, ln, ln);
		return (ret);
	}
	if (side == 'f')
		all->txtrs.f = rgb;
	else if (side == 'c')
		all->txtrs.c = rgb;
	f_ree(ln, ln, ln);
	return (OK);
}

static char	*ft_valid_syms_edges_plr2x(t_all *all, char *ln)
{
	int			i;

	all->m.parsed++;
	i = 0;
	while (ln[i] && ln[i] == ' ')
		i++;
	if (!all->m.started && ln[i])
		all->m.started = 1;
	if (ln[i] && all->m.started && all->m.bot)
		return ("bad symbols after map");
	all->m.bot = (all->m.started && !ln[i]) ? 1 : 0;
	all->m.row += (ln[i] && all->m.started && !all->m.bot) ? 1 : 0;
	all->m.lft = ln[i] ? i : -1;
	while (ln[i] && ft_strchr(" 012NEWS", ln[i]))
	{
		if (ft_strchr("0NEWS", ln[i]) && (!all->m.row ||
			i == 0 || ln[i + 1] == '\0' || i == all->m.lft))
			return ("the map is not closed");
		if (ft_strchr("NEWS", ln[i]) && all->m.p_look)
			return ("more than 1 player on map");
		if (ft_strchr("NEWS", ln[i]))
			all->m.p_look = ln[i];
		i++;
	}
	return (ln[i] == '\0' ? OK : "bad symbols within map");
}

char		*prs_m(t_all *all, char **ln)
{
	int			j;
	t_list		*node;
	char		*ret;

	if ((ret = ft_valid_syms_edges_plr2x(all, *ln)))
		return (ret);
	if (!all->m.bot && all->m.started)
	{
		all->m.max_lft = (all->m.lft < all->m.max_lft) ?
				all->m.lft : all->m.max_lft;
		j = ft_strlen(*ln) - 1;
		while (*(*ln + j) == ' ' && *(*ln + j) > -1)
			j--;
		all->m.last_col_end = j;
		all->m.max_rht = j > all->m.max_rht ? j : all->m.max_rht;
		all->m.last_col_beg = all->m.lft;
		if (!(node = ft_lstnew(*ln)))
			return ("malloc failed at prs_m function");
		ft_lstadd_back(&(all->m.tmp), node);
		return (OK);
	}
	f_ree(ln, ln, ln);
	return (OK);
}
