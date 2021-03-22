/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:25:10 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/28 19:25:12 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char		*dst;

	dst = all->win.addr + (y * all->win.line_len + x * (all->win.bpp / 8));
	*(unsigned int*)dst = color;
}

void	set_vectors(t_all *all)
{
	if (all->m.p_look == 'N')
	{
		all->plr.dir_y = -1;
		all->plr.plane_x = tan(FOV / 2 * M_PI / 180);
	}
	else if (all->m.p_look == 'S')
	{
		all->plr.dir_y = 1;
		all->plr.plane_x = -tan(FOV / 2 * M_PI / 180);
	}
	else if (all->m.p_look == 'E')
	{
		all->plr.dir_x = 1;
		all->plr.plane_y = tan(FOV / 2 * M_PI / 180);
	}
	else if (all->m.p_look == 'W')
	{
		all->plr.dir_x = -1;
		all->plr.plane_y = -tan(FOV / 2 * M_PI / 180);
	}
}

void	draw_background(t_all *all)
{
	int			h;
	int			w;

	h = -1;
	while (++h < (all->h / 2))
	{
		w = -1;
		while (++w < all->w)
			my_mlx_pixel_put(all, w, h, all->txtrs.c);
	}
	while (h < all->h)
	{
		w = -1;
		while (++w < all->w)
			my_mlx_pixel_put(all, w, h, all->txtrs.f);
		h++;
	}
}

void	step_till_wall(t_all *all, int x)
{
	all->ray.hit = 0;
	while (!all->ray.hit)
	{
		if (all->ray.side_dist_x < all->ray.side_dist_y)
		{
			all->ray.side_dist_x += all->ray.delta_dist_x;
			all->ray.map_x += all->ray.step_x;
			all->ray.side_hit = (all->ray.ray_dir_x < 0) ? 0 : 1;
		}
		else
		{
			all->ray.side_dist_y += all->ray.delta_dist_y;
			all->ray.map_y += all->ray.step_y;
			all->ray.side_hit = (all->ray.ray_dir_y < 0) ? 2 : 3;
		}
		if (!ft_strchr("02NSWE", all->map[all->ray.map_y][all->ray.map_x]))
			all->ray.hit = 1;
	}
	if (all->ray.side_hit < 2)
		all->ray.perp_wall_dist[x] = (all->ray.map_x - all->plr.pos_x +
			(1 - all->ray.step_x) / 2) / all->ray.ray_dir_x;
	else
		all->ray.perp_wall_dist[x] = (all->ray.map_y - all->plr.pos_y +
			(1 - all->ray.step_y) / 2) / all->ray.ray_dir_y;
}

void	draw_wall(t_all *all, int x)
{
	int			y;

	y = all->ray.draw_start;
	all->ray.wall_x = all->ray.side_hit < 2 ? all->plr.pos_y +
		all->ray.perp_wall_dist[x] * all->ray.ray_dir_y : all->plr.pos_x +
			all->ray.perp_wall_dist[x] * all->ray.ray_dir_x;
	all->ray.wall_x -= (int)all->ray.wall_x;
	all->ray.tex_x = (int)(all->ray.wall_x * (double)(all->ray.txtr_w));
	if (all->ray.side_hit == 0 || all->ray.side_hit == 3)
	{
		all->ray.tex_x = (int)((double)all->ray.txtr_w - all->ray.wall_x *
			(double)all->ray.txtr_w - 1);
	}
	all->ray.step = 1.0 * all->ray.txtr_h / all->ray.line_height;
	all->ray.tex_pos = (all->ray.draw_start -
		all->h / 2 + all->ray.line_height / 2) * all->ray.step;
	while (y < all->ray.draw_end)
	{
		all->ray.tex_y = (int)all->ray.tex_pos;
		all->ray.color = *(int*)(all->ray.txtr_addr +
			((all->ray.tex_x + (all->ray.tex_y *
			all->ray.txtr_w)) * (all->ray.txtr_bpp / 8)));
		all->ray.tex_pos += all->ray.step;
		my_mlx_pixel_put(all, x, y++, all->ray.color);
	}
}
