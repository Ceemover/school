/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:25:26 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/28 19:25:27 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	turn_lft(t_all *all)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = all->plr.dir_x;
	all->plr.dir_x = all->plr.dir_x * cos(-all->plr.rot_sp) -
		all->plr.dir_y * sin(-all->plr.rot_sp);
	all->plr.dir_y = old_dir_x * sin(-all->plr.rot_sp) +
		all->plr.dir_y * cos(-all->plr.rot_sp);
	old_plane_x = all->plr.plane_x;
	all->plr.plane_x = all->plr.plane_x * cos(-all->plr.rot_sp) -
		all->plr.plane_y * sin(-all->plr.rot_sp);
	all->plr.plane_y = old_plane_x * sin(-all->plr.rot_sp) +
		all->plr.plane_y * cos(-all->plr.rot_sp);
}

void	turn_rht(t_all *all)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = all->plr.dir_x;
	all->plr.dir_x = all->plr.dir_x * cos(all->plr.rot_sp) -
		all->plr.dir_y * sin(all->plr.rot_sp);
	all->plr.dir_y = old_dir_x * sin(all->plr.rot_sp) +
		all->plr.dir_y * cos(all->plr.rot_sp);
	old_plane_x = all->plr.plane_x;
	all->plr.plane_x = all->plr.plane_x * cos(all->plr.rot_sp) -
		all->plr.plane_y * sin(all->plr.rot_sp);
	all->plr.plane_y = old_plane_x * sin(all->plr.rot_sp) +
		all->plr.plane_y * cos(all->plr.rot_sp);
}

void	calc_wall_column(t_all *all, int x)
{
	all->ray.line_height = (int)(all->h / all->ray.perp_wall_dist[x]);
	all->ray.draw_start = (-all->ray.line_height / 2) + (all->h / 2) +
		all->plr.pitch + (all->plr.pos_z / all->ray.perp_wall_dist[x]);
	if (all->ray.draw_start < 0)
		all->ray.draw_start = 0;
	all->ray.draw_end = all->ray.line_height / 2 + all->h / 2 +
		all->plr.pitch + (all->plr.pos_z / all->ray.perp_wall_dist[x]);
	if (all->ray.draw_end >= all->h)
		all->ray.draw_end = all->h - 1;
}

int		fr_ee(char **line)
{
	if (*line)
		free(*line);
	*line = NULL;
	return (0);
}

int		exit_int(t_all *all)
{
	ft_exit_0(all, NULL);
	return (0);
}
