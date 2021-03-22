/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:25:33 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/28 19:25:35 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"
#include <stdio.h>

static void	calc_3d_depth(t_all *all, int i)
{
	all->spr.sprite_x = all->spr.x[i] - all->plr.pos_x;
	all->spr.sprite_y = all->spr.y[i] - all->plr.pos_y;
	all->spr.inv_det = 1.0 / (all->plr.plane_x *
		all->plr.dir_y - all->plr.dir_x * all->plr.plane_y);
	all->spr.transform_x = all->spr.inv_det * (all->plr.dir_y *
		all->spr.sprite_x - all->plr.dir_x * all->spr.sprite_y);
	all->spr.transform_y = all->spr.inv_det * (-all->plr.plane_y *
		all->spr.sprite_x + all->plr.plane_x * all->spr.sprite_y);
	all->spr.screen_x = (int)((all->w / 2) *
		(1 + all->spr.transform_x / all->spr.transform_y));
	all->spr.vert_mv = (int)(all->h * 0.1 / all->spr.transform_y);
}

static void	calc_sprite_height_and_width(t_all *all)
{
	all->spr.height = abs((int)(all->h / (all->spr.transform_y)));
	if ((all->spr.draw_start_y = -all->spr.height / 2 +
		all->h / 2 + all->spr.vert_mv) < 0)
		all->spr.draw_start_y = 0;
	if ((all->spr.draw_end_y = all->spr.height / 2 +
		all->h / 2 + all->spr.vert_mv) >= all->h)
		all->spr.draw_end_y = all->h - 1;
	all->spr.width = abs((int)(all->h / all->spr.transform_y));
	if ((all->spr.draw_start_x = -all->spr.width / 2 + all->spr.screen_x) < 0)
		all->spr.draw_start_x = 0;
	if ((all->spr.draw_end_x =
		all->spr.width / 2 + all->spr.screen_x) >= all->w)
		all->spr.draw_end_x = all->w - 1;
}

static void	draw_1_stripe(t_all *all, int stripe)
{
	int			y;
	int			d;
	uint32_t	color;

	y = all->spr.draw_start_y;
	while (y < all->spr.draw_end_y)
	{
		d = (y - all->spr.vert_mv) * 256 - all->h *
			128 + all->spr.height * 128;
		all->spr.tex_y = ((d * all->txtrs.s_height) /
			all->spr.height) / 256;
		if (all->spr.tex_x >= 0 && all->spr.tex_y >= 0)
		{
			color = *(int*)(all->txtrs.s_addr + ((all->spr.tex_x +
				(all->spr.tex_y * all->txtrs.s_width)) *
				(all->txtrs.s_bpp / 8)));
			if (color & 0x00FFFFFF)
				my_mlx_pixel_put(all, stripe, y, color);
		}
		y++;
	}
}

static void	draw_sprite_1_by_1(t_all *all, int i)
{
	int			stripe;

	calc_3d_depth(all, i);
	calc_sprite_height_and_width(all);
	stripe = all->spr.draw_start_x;
	while (stripe < all->spr.draw_end_x)
	{
		all->spr.tex_x = (int)(256 * (stripe -
			(-all->spr.width / 2 + all->spr.screen_x)) *
				all->txtrs.s_width / all->spr.width) / 256;
		if (all->spr.transform_y > 0.1 && stripe > 0 && stripe < all->w &&
			all->spr.transform_y < all->ray.perp_wall_dist[stripe])
			draw_1_stripe(all, stripe);
		stripe++;
	}
}

void		draw_sprites(t_all *all)
{
	int			i;

	i = -1;
	while (++i < all->spr.spr_num)
		all->spr.dist[i] = sqrt(pow(all->plr.pos_x - all->spr.x[i], 2) +
			pow(all->plr.pos_y - all->spr.y[i], 2));
	bubble_sort(all->spr.dist, all->spr.x, all->spr.y, all->spr.spr_num);
	i = -1;
	while (++i < all->spr.spr_num)
		draw_sprite_1_by_1(all, i);
}
