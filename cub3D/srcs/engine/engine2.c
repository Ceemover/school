/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:25:03 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/28 19:25:05 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

static void	calc_dist_between_x_y_hits(t_all *all)
{
	all->ray.ray_dir_x =
		all->plr.dir_x + all->plr.plane_x * all->plr.camera_x;
	all->ray.ray_dir_y =
		all->plr.dir_y + all->plr.plane_y * all->plr.camera_x;
	if (!all->ray.ray_dir_y)
		all->ray.delta_dist_x = 0;
	else
		all->ray.delta_dist_x = !all->ray.ray_dir_x ?
			1 : fabs(1 / all->ray.ray_dir_x);
	if (!all->ray.ray_dir_x)
		all->ray.delta_dist_y = 0;
	else
		all->ray.delta_dist_y = !all->ray.ray_dir_y ?
			1 : fabs(1 / all->ray.ray_dir_y);
}

static void	set_step_orientation(t_all *all)
{
	if (all->ray.ray_dir_x < 0)
	{
		all->ray.step_x = -1;
		all->ray.side_dist_x =
			(all->plr.pos_x - all->ray.map_x) * all->ray.delta_dist_x;
	}
	else
	{
		all->ray.step_x = 1;
		all->ray.side_dist_x =
			(all->ray.map_x + 1.0 - all->plr.pos_x) * all->ray.delta_dist_x;
	}
	if (all->ray.ray_dir_y < 0)
	{
		all->ray.step_y = -1;
		all->ray.side_dist_y =
			(all->plr.pos_y - all->ray.map_y) * all->ray.delta_dist_y;
	}
	else
	{
		all->ray.step_y = 1;
		all->ray.side_dist_y =
			(all->ray.map_y + 1.0 - all->plr.pos_y) * all->ray.delta_dist_y;
	}
}

static void	assign_wall_txtr2(t_all *all)
{
	if (all->ray.side_hit == 2)
	{
		all->ray.txtr = all->txtrs.no;
		all->ray.txtr_addr = all->txtrs.no_addr;
		all->ray.txtr_h = all->txtrs.no_h;
		all->ray.txtr_w = all->txtrs.no_w;
		all->ray.txtr_bpp = all->txtrs.no_bpp;
		all->ray.txtr_en = all->txtrs.no_en;
		all->ray.txtr_llen = all->txtrs.no_llen;
	}
	else
	{
		all->ray.txtr = all->txtrs.so;
		all->ray.txtr_addr = all->txtrs.so_addr;
		all->ray.txtr_h = all->txtrs.so_h;
		all->ray.txtr_w = all->txtrs.so_w;
		all->ray.txtr_bpp = all->txtrs.so_bpp;
		all->ray.txtr_en = all->txtrs.so_en;
		all->ray.txtr_llen = all->txtrs.so_llen;
	}
}

static void	assign_wall_txtr(t_all *all)
{
	if (all->ray.side_hit == 0)
	{
		all->ray.txtr = all->txtrs.we;
		all->ray.txtr_addr = all->txtrs.we_addr;
		all->ray.txtr_h = all->txtrs.we_h;
		all->ray.txtr_w = all->txtrs.we_w;
		all->ray.txtr_bpp = all->txtrs.we_bpp;
		all->ray.txtr_en = all->txtrs.we_en;
		all->ray.txtr_llen = all->txtrs.we_llen;
	}
	else if (all->ray.side_hit == 1)
	{
		all->ray.txtr = all->txtrs.ea;
		all->ray.txtr_addr = all->txtrs.ea_addr;
		all->ray.txtr_h = all->txtrs.ea_h;
		all->ray.txtr_w = all->txtrs.ea_w;
		all->ray.txtr_bpp = all->txtrs.ea_bpp;
		all->ray.txtr_en = all->txtrs.ea_en;
		all->ray.txtr_llen = all->txtrs.ea_llen;
	}
	else
		assign_wall_txtr2(all);
}

void		draw_columns(t_all *all)
{
	int			x;

	x = -1;
	while (++x < all->w)
	{
		all->plr.camera_x = 2 * x / (double)all->w - 1;
		all->ray.map_x = (int)all->plr.pos_x;
		all->ray.map_y = (int)all->plr.pos_y;
		calc_dist_between_x_y_hits(all);
		set_step_orientation(all);
		step_till_wall(all, x);
		calc_wall_column(all, x);
		assign_wall_txtr(all);
		draw_wall(all, x);
	}
}
