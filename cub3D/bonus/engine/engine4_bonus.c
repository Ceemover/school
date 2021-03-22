/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:25:17 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/28 19:25:19 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

static void	move_up(t_all *all)
{
	if (ft_strchr("0NEWS",
		all->map[(int)(all->plr.pos_y + all->plr.dir_y * all->plr.move_sp)]
			[(int)(all->plr.pos_x)]))
		all->plr.pos_y += all->plr.dir_y * all->plr.move_sp;
	if (ft_strchr("0NEWS", all->map[(int)all->plr.pos_y]
			[(int)(all->plr.pos_x + all->plr.dir_x * all->plr.move_sp)]))
		all->plr.pos_x += all->plr.dir_x * all->plr.move_sp;
}

static void	move_down(t_all *all)
{
	if (ft_strchr("0NEWS",
		all->map[(int)(all->plr.pos_y - (all->plr.dir_y * all->plr.move_sp))]
			[(int)all->plr.pos_x]))
		all->plr.pos_y -= all->plr.dir_y * all->plr.move_sp;
	if (ft_strchr("0NEWS", all->map[(int)all->plr.pos_y]
			[(int)(all->plr.pos_x - (all->plr.dir_x * all->plr.move_sp))]))
		all->plr.pos_x -= all->plr.dir_x * all->plr.move_sp;
}

static void	move_rht(t_all *all)
{
	if (ft_strchr("0NSWE", all->map[(int)all->plr.pos_y]
		[(int)(all->plr.pos_x + (all->plr.plane_x * all->plr.move_sp))]))
		all->plr.pos_x += all->plr.plane_x * all->plr.move_sp;
	if (ft_strchr("0NSWE", all->map[(int)(all->plr.pos_y +
		(all->plr.plane_y * all->plr.move_sp))][(int)all->plr.pos_x]))
		all->plr.pos_y += all->plr.plane_y * all->plr.move_sp;
}

static void	move_lft(t_all *all)
{
	if (ft_strchr("0NSWE", all->map[(int)all->plr.pos_y]
		[(int)(all->plr.pos_x - (all->plr.plane_x * all->plr.move_sp))]))
		all->plr.pos_x -= all->plr.plane_x * all->plr.move_sp;
	if (ft_strchr("0NSWE", all->map[(int)(all->plr.pos_y -
		(all->plr.plane_y * all->plr.move_sp))][(int)all->plr.pos_x]))
		all->plr.pos_y -= all->plr.plane_y * all->plr.move_sp;
}

int			key_sort_n_draw(t_all *all)
{
	mlx_do_sync(all->win.mlx);
	if (all->key.w && !all->key.s)
		move_up(all);
	if (all->key.s && !all->key.w)
		move_down(all);
	if (all->key.a && !all->key.d)
		move_lft(all);
	if (all->key.d && !all->key.a)
		move_rht(all);
	if (all->key.r && !all->key.l)
		turn_rht(all);
	if (all->key.l && !all->key.r)
		turn_lft(all);
	if (all->key.up && !all->key.down)
		check_pitch(all, 1);
	if (all->key.down && !all->key.up)
		check_pitch(all, 2);
	if (!all->key.space && !all->key.ctrl && all->key.space && all->key.ctrl)
		all->plr.pos_z = 0;
	return (scene(all));
}
