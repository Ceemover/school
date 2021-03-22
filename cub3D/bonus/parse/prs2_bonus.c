/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:26:42 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/28 19:26:44 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

char		*val_map(t_all *all)
{
	int			i;
	int			j;

	i = 0;
	while (++i <= all->m.row)
	{
		j = -1;
		while (++j < all->m.max_rht)
		{
			if (all->map[i][j] == ' ' && !(all->map[i - 1][j] == '1' ||
				all->map[i - 1][j] == ' '))
				return ("map is not closed");
			if (ft_strchr("02NEWS", all->map[i][j]) &&
				all->map[i - 1][j] == ' ')
				return ("map is not closed");
			if (ft_strchr("NEWS", all->map[i][j]))
			{
				all->m.pos_x = j;
				all->m.pos_y = i;
			}
			if (all->map[i][j] == '2')
				all->spr.spr_num++;
		}
	}
	return (OK);
}

static int	fill_w_0(t_all *all, int i, int j)
{
	int			empty_horiz;

	empty_horiz = 0;
	if (all->map[i][j - 1] == ' ' || all->map[i][j + 1] == ' ')
	{
		empty_horiz = 1;
		if (all->map[i][j - 1] == ' ' &&
		(all->map[i + 1][j - 1] == '1' || all->map[i - 1][j - 1] == '1'))
			all->map[i][j - 1] = '0';
		if (all->map[i][j + 1] == ' ' &&
		(all->map[i + 1][j + 1] == '1' || all->map[i - 1][j + 1] == '1'))
			all->map[i][j + 1] = '0';
	}
	if (all->map[i - 1][j] == ' ' || all->map[i + 1][j] == ' ' || empty_horiz)
	{
		if (all->map[i - 1][j] == ' ' &&
		(all->map[i - 1][j - 1] == '1' || all->map[i - 1][j + 1] == '1'))
			all->map[i - 1][j] = '0';
		if (all->map[i + 1][j] == ' ' &&
		(all->map[i + 1][j - 1] == '1' || all->map[i + 1][j + 1] == '1'))
			all->map[i + 1][j] = '0';
	}
	return (0);
}

int			fill_map(t_all *all)
{
	int			i;
	int			j;

	i = 0;
	while (++i < all->m.row)
	{
		j = 0;
		while (++j < all->m.max_rht)
		{
			if (all->map[i][j] == '1' &&
				(all->map[i][j - 1] == ' ' || all->map[i][j + 1] == ' ' ||
				all->map[i - 1][j] == ' ' || all->map[i + 1][j] == ' '))
				fill_w_0(all, i, j);
		}
	}
	return (0);
}

char		*prs_txtr(t_all *all, char **ln, char side)
{
	int			i;
	int			j;
	char		*tmp;

	tmp = *ln;
	i = 2;
	while (*(*ln + i) == ' ')
		i++;
	j = i;
	while (*(*ln + i) && (ft_isprint(*(*ln + i))))
	{
		if (*(*ln + i) == '.' && !ft_strchr("./", *(*ln + i + 1)))
			break ;
		i++;
	}
	if (ft_strncmp(*ln + i, ".xpm", 5))
		return ("bad path to the texture");
	if (!(*ln = ft_strdup(*ln + j)) || fr_ee(&tmp))
		return ("malloc failed at prs_txtr function");
	all->txtrs.no = (side == 'n' ? *ln : all->txtrs.no);
	all->txtrs.so = (side == 's' ? *ln : all->txtrs.so);
	all->txtrs.ea = (side == 'e' ? *ln : all->txtrs.ea);
	all->txtrs.we = (side == 'w' ? *ln : all->txtrs.we);
	all->txtrs.s = (side == 'z' ? *ln : all->txtrs.s);
	return (OK);
}
