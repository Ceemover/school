/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:26:12 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/28 19:26:16 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	ft_init_txtrs2(t_txtrs *txtrs)
{
	txtrs->so_ptr = NULL;
	txtrs->so_addr = NULL;
	txtrs->so_h = 0;
	txtrs->so_w = 0;
	txtrs->so_bpp = 0;
	txtrs->so_llen = 0;
	txtrs->so_en = 0;
	txtrs->ea_ptr = NULL;
	txtrs->ea_addr = NULL;
	txtrs->ea_h = 0;
	txtrs->ea_w = 0;
	txtrs->ea_bpp = 0;
	txtrs->ea_llen = 0;
	txtrs->ea_en = 0;
	txtrs->we_ptr = NULL;
	txtrs->we_addr = NULL;
	txtrs->we_h = 0;
	txtrs->we_w = 0;
	txtrs->we_bpp = 0;
	txtrs->we_llen = 0;
	txtrs->we_en = 0;
}

void	ft_init_txtrs(t_txtrs *txtrs)
{
	txtrs->no = NULL;
	txtrs->so = NULL;
	txtrs->ea = NULL;
	txtrs->we = NULL;
	txtrs->s = NULL;
	txtrs->f = -1;
	txtrs->c = -1;
	txtrs->s_ptr = NULL;
	txtrs->s_addr = NULL;
	txtrs->s_height = 0;
	txtrs->s_width = 0;
	txtrs->s_bpp = 0;
	txtrs->s_llen = 0;
	txtrs->s_en = 0;
	txtrs->no_ptr = NULL;
	txtrs->no_addr = NULL;
	txtrs->no_h = 0;
	txtrs->no_w = 0;
	txtrs->no_bpp = 0;
	txtrs->no_llen = 0;
	txtrs->no_en = 0;
	ft_init_txtrs2(txtrs);
}

void	ft_init_key(t_key *key)
{
	key->w = 0;
	key->s = 0;
	key->d = 0;
	key->a = 0;
	key->r = 0;
	key->l = 0;
}

void	ft_init_plr(t_plr *plr)
{
	plr->pos_x = 0;
	plr->pos_y = 0;
	plr->dir_x = 0;
	plr->dir_y = 0;
	plr->move_sp = 0;
	plr->rot_sp = 0;
	plr->plane_x = 0;
	plr->plane_y = 0;
	plr->camera_x = 0;
	plr->camera_y = 0;
}

void	ft_init_win(t_win *win)
{
	win->mlx = NULL;
	win->win = NULL;
	win->img = NULL;
	win->addr = NULL;
	win->line_len = 0;
	win->bpp = 0;
	win->en = 0;
}
