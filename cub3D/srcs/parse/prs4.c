/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:26:56 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/28 19:26:58 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

static char	*prs_w(t_all *all, char **ln)
{
	int			i;
	char		*tmp;

	if (**ln == '-')
		return ("negative width");
	if (**ln == '+')
		*ln += 1;
	i = 0;
	while (ft_isdigit(*(*ln + i)))
		i++;
	if (*(*ln + i) != ' ' || i == 0)
		return ("bad resolution formatting");
	if (i > 4)
		mlx_get_screen_size(all->win.mlx, &all->w, &all->tmp);
	else
	{
		*(*ln + i) = '\0';
		all->w = ft_atoi(*ln);
		*(*ln + i) = ' ';
	}
	if (!(tmp = ft_strdup(*ln + i)))
		return ("malloc failed at prs_w function");
	*ln = tmp;
	return (all->w < 100 ? "width is less than 100" : OK);
}

static char	*prs_h(t_all *all, char **lnn)
{
	int			i;
	char		*ln;

	all->tmp = 0;
	ln = *lnn;
	while (*ln == ' ')
		ln++;
	if (*ln == '-')
		return ("negative height");
	if (*ln == '+')
		ln++;
	i = 0;
	while (ft_isdigit(ln[i]))
		i++;
	if (i > 4)
		mlx_get_screen_size(all->win.mlx, &all->tmp, &all->h);
	if (ln[i] != '\0' || i == 0)
		return ("bad resolution formatting");
	if (!all->tmp)
		all->h = atoi(ln);
	return (all->h < 100 ? "height is less than 100" : OK);
}

char		*prs_r(t_all *all, char **ln)
{
	char		*ret;
	char		*tmp;

	tmp = *ln;
	tmp += 1;
	mlx_get_screen_size(all->win.mlx, &all->win.full_reso_w,
		&all->win.full_reso_h);
	while (*tmp == ' ')
		tmp += 1;
	if ((ret = prs_w(all, &tmp)))
		return (ret);
	if (all->w > all->win.full_reso_w)
		all->w = all->win.full_reso_w;
	if ((ret = prs_h(all, &tmp)) != OK)
		return (ret);
	if (all->h > all->win.full_reso_h)
		all->h = all->win.full_reso_h;
	free(*ln);
	*ln = NULL;
	free(tmp);
	tmp = NULL;
	return (OK);
}
