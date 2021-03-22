/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:25:47 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/28 19:25:48 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

char	*ft_exit_0(t_all *all, char *line)
{
	if (line)
	{
		ft_putstr_fd("Error\n: ", 1);
		ft_putstr_fd(line, 1);
		write(1, "\n", 1);
	}
	!all->screenshot && !line ? ft_putstr_fd("closed cub3D\n", 1) : 0;
	if (all->win.win)
		mlx_destroy_window(all->win.mlx, all->win.win);
	all->txtrs.no ? fr_ee(&all->txtrs.no) : 0;
	all->txtrs.so ? fr_ee(&all->txtrs.so) : 0;
	all->txtrs.ea ? fr_ee(&all->txtrs.ea) : 0;
	all->txtrs.we ? fr_ee(&all->txtrs.we) : 0;
	all->txtrs.s ? fr_ee(&all->txtrs.s) : 0;
	all->m.tmp ? ft_lstclear(&all->m.tmp, &free) : 0;
	all->tmp = 0;
	while (all->map && all->tmp <= all->m.row)
		fr_ee(&all->map[all->tmp++]);
	all->map ? free(all->map) : 0;
	all->ray.perp_wall_dist ? free(all->ray.perp_wall_dist) : 0;
	all->spr.dist ? free(all->spr.dist) : 0;
	all->spr.x ? free(all->spr.x) : 0;
	all->spr.y ? free(all->spr.y) : 0;
	exit(line ? -1 : 0);
	return (NULL);
}
