/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:25:41 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/28 19:25:42 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

static char	*val_addr(t_all *all)
{
	if (!(all->txtrs.no_addr = mlx_get_data_addr(all->txtrs.no_ptr,
		&all->txtrs.no_bpp, &all->txtrs.no_llen, &all->txtrs.no_en)))
		return ("couldn't get nourth wall texture address");
	if (!(all->txtrs.so_addr = mlx_get_data_addr(all->txtrs.so_ptr,
		&all->txtrs.so_bpp, &all->txtrs.so_llen, &all->txtrs.so_en)))
		return ("couldn't get south wall texture address");
	if (!(all->txtrs.ea_addr = mlx_get_data_addr(all->txtrs.ea_ptr,
		&all->txtrs.ea_bpp, &all->txtrs.ea_llen, &all->txtrs.ea_en)))
		return ("couldn't get east wall texture address");
	if (!(all->txtrs.we_addr = mlx_get_data_addr(all->txtrs.we_ptr,
		&all->txtrs.we_bpp, &all->txtrs.we_llen, &all->txtrs.we_en)))
		return ("couldn't get west wall texture address");
	if (!(all->txtrs.s_addr = mlx_get_data_addr(all->txtrs.s_ptr,
		&all->txtrs.s_bpp, &all->txtrs.s_llen, &all->txtrs.s_en)))
		return ("couldn't get sprites texture address");
	if (all->txtrs.ff && !(all->txtrs.ff_addr = mlx_get_data_addr(
		all->txtrs.ff_ptr, &all->txtrs.ff_bpp, &all->txtrs.ff_llen,
		&all->txtrs.ff_en)))
		return ("couldn't get floor texture address");
	if (all->txtrs.cc && !(all->txtrs.cc_addr = mlx_get_data_addr(
		all->txtrs.cc_ptr, &all->txtrs.cc_bpp, &all->txtrs.cc_llen,
		&all->txtrs.cc_en)))
		return ("couldn't get floor texture address");
	return (OK);
}

static char	*val_txtrs(t_all *all)
{
	if (!(all->txtrs.no_ptr = mlx_xpm_file_to_image(all->win.mlx,
		all->txtrs.no, &all->txtrs.no_w, &all->txtrs.no_h)))
		return ("North texture won't open");
	if (!(all->txtrs.so_ptr = mlx_xpm_file_to_image(all->win.mlx,
		all->txtrs.so, &all->txtrs.so_w, &all->txtrs.so_h)))
		return ("South texture won't open");
	if (!(all->txtrs.ea_ptr = mlx_xpm_file_to_image(all->win.mlx,
		all->txtrs.ea, &all->txtrs.ea_w, &all->txtrs.ea_h)))
		return ("East texture won't open");
	if (!(all->txtrs.we_ptr = mlx_xpm_file_to_image(all->win.mlx,
		all->txtrs.we, &all->txtrs.we_w, &all->txtrs.we_h)))
		return ("West texture won't open");
	if (!(all->txtrs.s_ptr = mlx_xpm_file_to_image(all->win.mlx,
		all->txtrs.s, &all->txtrs.s_width, &all->txtrs.s_height)))
		return ("sprite texture won't open");
	if (all->txtrs.ff && !(all->txtrs.ff_ptr = mlx_xpm_file_to_image(
		all->win.mlx, all->txtrs.ff, &all->txtrs.ff_w, &all->txtrs.ff_h)))
		return ("floor texture won't open");
	if (all->txtrs.cc && !(all->txtrs.cc_ptr = mlx_xpm_file_to_image(
		all->win.mlx, all->txtrs.cc, &all->txtrs.cc_w, &all->txtrs.cc_h)))
		return ("ceiling texture won't open");
	return (OK);
}

static char	*val_mlx(t_all *all)
{
	if (!all->screenshot)
	{
		if (!(all->win.win =
			mlx_new_window(all->win.mlx, all->w, all->h, "cub3D")))
			return ("mlx_new_window failed");
	}
	if (!(all->win.img = mlx_new_image(all->win.mlx, all->w, all->h)))
		return ("mlx_new_image failed");
	if (!(all->win.addr = mlx_get_data_addr(all->win.img, &all->win.bpp,
		&all->win.line_len, &all->win.en)))
		return ("mlx_get_data_addr failed");
	return (OK);
}

static char	*locate_spr(t_all *all)
{
	int			i;
	int			j;
	int			z;

	if (!(all->spr.x = malloc(sizeof(double *) * all->spr.spr_num)) ||
		!(all->spr.y = malloc(sizeof(double *) * all->spr.spr_num)) ||
		!(all->spr.dist = malloc(sizeof(double *) * all->spr.spr_num)))
		return ("malloc failed at srh_spr function");
	z = 0;
	i = -1;
	while (++i <= all->m.row)
	{
		j = -1;
		while (++j <= all->m.max_rht)
		{
			if (all->map[i][j] == '2')
			{
				all->spr.x[z] = (double)j + 0.5;
				all->spr.y[z] = (double)i + 0.5;
				z++;
			}
		}
	}
	return (OK);
}

char		*ft_engine(t_all *all)
{
	char	*r;

	all->plr.pos_x = (float)all->m.pos_x + 0.5;
	all->plr.pos_y = (float)all->m.pos_y + 0.5;
	r = all->spr.spr_num ? locate_spr(all) : 0;
	if (r)
		return (ft_exit_0(all, r));
	if ((r = val_txtrs(all)))
		return (ft_exit_0(all, r));
	if ((r = val_addr(all)))
		return (ft_exit_0(all, r));
	if ((r = val_mlx(all)))
		return (ft_exit_0(all, r));
	set_vectors(all);
	all->plr.move_sp = 0.4 * MV_SP;
	all->plr.rot_sp = 0.05 * ROT_SP;
	if (!(all->ray.perp_wall_dist = (double*)ft_calloc(all->w, sizeof(double))))
		return (ft_exit_0(all, "malloc failed at ft_engine function"));
	all->screenshot ? save_screenshot(all) : 0;
	mlx_hook(all->win.win, 2, 1L << 0, key_press, all);
	mlx_hook(all->win.win, 3, 1L << 1, key_release, all);
	mlx_hook(all->win.win, 17, 1L << 17, exit_int, all);
	mlx_loop_hook(all->win.mlx, key_sort_n_draw, all);
	mlx_loop(all->win.mlx);
	return (OK);
}
