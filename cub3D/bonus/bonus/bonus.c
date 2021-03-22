/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:32:01 by dbolg             #+#    #+#             */
/*   Updated: 2020/11/02 19:32:03 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void			floor_loop(t_all *all, int y)
{
	all->tmp = -1;
	while (++all->tmp < all->w)
	{
		all->f.cell_x = (int)(all->f.floor_x);
		all->f.cell_y = (int)(all->f.floor_y);
		all->f.tx = (int)(all->txtrs.ff_w * (all->f.floor_x -
			all->f.cell_x));
		if (all->f.tx < 0)
			all->f.tx = (int)(all->txtrs.ff_w * (all->f.floor_x -
			all->f.cell_x)) & (all->txtrs.ff_w - 1);
		all->f.ty = (int)(all->txtrs.ff_h * (all->f.floor_y -
			all->f.cell_y));
		if (all->f.ty < 0)
			all->f.ty = (int)(all->txtrs.ff_h * (all->f.floor_y -
				all->f.cell_y)) & (all->txtrs.ff_h - 1);
		all->f.floor_x += all->f.fl_step_x;
		all->f.floor_y += all->f.fl_step_y;
		all->f.color = *(int*)(all->txtrs.ff_addr + (((all->txtrs.ff_w *
			all->f.ty) + all->f.tx) * (all->txtrs.ff_bpp / 8)));
		my_mlx_pixel_put(all, all->tmp, y, all->f.color);
	}
}

void			calc_floor(t_all *all, int y)
{
	int p;

	all->f.ray_dir_x0 = all->plr.dir_x - all->plr.plane_x;
	all->f.ray_dir_y0 = all->plr.dir_y - all->plr.plane_y;
	all->f.ray_dir_x1 = all->plr.dir_x + all->plr.plane_x;
	all->f.ray_dir_y1 = all->plr.dir_y + all->plr.plane_y;
	p = all->f.is_floor ? (y - all->h / 2 - all->plr.pitch) :
		(all->h / 2 - y + all->plr.pitch);
	if (p < 0)
		p *= -1;
	all->f.row_dist = all->plr.cam_z / p;
	all->f.fl_step_x = all->f.row_dist *
		(all->f.ray_dir_x1 - all->f.ray_dir_x0) / all->w;
	all->f.fl_step_y = all->f.row_dist *
		(all->f.ray_dir_y1 - all->f.ray_dir_y0) / all->w;
	all->f.floor_x = all->plr.pos_x + all->f.row_dist * all->f.ray_dir_x0;
	all->f.floor_y = all->plr.pos_y + all->f.row_dist * all->f.ray_dir_y0;
}

static void		calc_ceil(t_all *all, int y)
{
	int p;

	all->f.ray_dir_x0 = all->plr.dir_x - all->plr.plane_x;
	all->f.ray_dir_y0 = all->plr.dir_y - all->plr.plane_y;
	all->f.ray_dir_x1 = all->plr.dir_x + all->plr.plane_x;
	all->f.ray_dir_y1 = all->plr.dir_y + all->plr.plane_y;
	p = all->f.is_floor ? (y - all->h / 2 - all->plr.pitch) :
		(all->h / 2 - y + all->plr.pitch);
	if (p < 0)
		p *= -1;
	all->f.row_dist = all->plr.cam_z / p;
	all->f.fl_step_x = all->f.row_dist *
		(all->f.ray_dir_x1 - all->f.ray_dir_x0) / all->w;
	all->f.fl_step_y = all->f.row_dist *
		(all->f.ray_dir_y1 - all->f.ray_dir_y0) / all->w;
	all->f.floor_x = all->plr.pos_x + all->f.row_dist * all->f.ray_dir_x0;
	all->f.floor_y = all->plr.pos_y + all->f.row_dist * all->f.ray_dir_y0;
}

static void		ceil_loop(t_all *all, int y)
{
	all->tmp = -1;
	while (++all->tmp < all->w)
	{
		all->f.cell_x = (int)(all->f.floor_x);
		all->f.cell_y = (int)(all->f.floor_y);
		all->f.tx = (int)(all->txtrs.cc_w * (all->f.floor_x -
			all->f.cell_x));
		if (all->f.tx < 0)
			all->f.tx = (int)(all->txtrs.cc_w * (all->f.floor_x -
			all->f.cell_x)) & (all->txtrs.cc_w - 1);
		all->f.ty = (int)(all->txtrs.cc_h * (all->f.floor_y -
			all->f.cell_y));
		if (all->f.ty < 0)
			all->f.ty = (int)(all->txtrs.cc_h * (all->f.floor_y -
				all->f.cell_y)) & (all->txtrs.cc_h - 1);
		all->f.floor_x += all->f.fl_step_x;
		all->f.floor_y += all->f.fl_step_y;
		all->f.color = *(int*)(all->txtrs.cc_addr + (((all->txtrs.cc_w *
			all->f.ty) + all->f.tx) * (all->txtrs.cc_bpp / 8)));
		my_mlx_pixel_put(all, all->tmp, y, all->f.color);
	}
}

void			draw_f_c_txtrs(t_all *all)
{
	int y;

	y = 0;
	if (all->txtrs.c_fl)
	{
		while (y < all->h / 2 + all->plr.pitch)
		{
			all->f.is_floor = y > all->h / 2 + all->plr.pitch;
			all->plr.cam_z = all->f.is_floor ? (0.5 * all->h + all->plr.pos_z) :
				(0.5 * all->h - all->plr.pos_z);
			calc_ceil(all, y);
			ceil_loop(all, y);
			y++;
		}
	}
	else
		draw_background(all);
	draw_floor(all);
}
