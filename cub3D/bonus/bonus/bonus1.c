/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 02:13:29 by dbolg             #+#    #+#             */
/*   Updated: 2020/11/03 02:13:31 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	loop_draw_walls(t_all *all, int x, int y)
{
	all->ray.tex_y = (int)all->ray.tex_pos;
	all->ray.color = *(int*)(all->ray.txtr_addr +
		((all->ray.tex_x + (all->ray.tex_y *
		all->ray.txtr_w)) * (all->ray.txtr_bpp / 8)));
	all->ray.tex_pos += all->ray.step;
	my_mlx_pixel_put(all, x, y, all->ray.color);
}

void	draw_floor(t_all *all)
{
	int y;

	y = all->h / 2 + all->plr.pitch;
	if (all->txtrs.f_fl)
	{
		while (y < all->h)
		{
			all->f.is_floor = y > all->h / 2 + all->plr.pitch;
			all->plr.cam_z = all->f.is_floor ? (0.5 * all->h + all->plr.pos_z) :
				(0.5 * all->h - all->plr.pos_z);
			calc_floor(all, y);
			floor_loop(all, y);
			y++;
		}
	}
	else
		draw_background(all);
}

void	check_pitch(t_all *all, int side)
{
	if (side == 1)
	{
		all->plr.pitch += all->plr.pitch < (double)all->h /
			2.2 ? 150 : 1;
		all->plr.pitch = all->plr.pitch > (double)all->h / 2.2 ?
			(double)all->h / 2.2 : all->plr.pitch;
	}
	else
	{
		all->plr.pitch -= all->plr.pitch > -(double)all->h /
			2.8 ? 150 : 0;
		all->plr.pitch = all->plr.pitch < -(double)all->h / 2.2 ?
			-(double)all->h / 2.2 : all->plr.pitch;
	}
}
