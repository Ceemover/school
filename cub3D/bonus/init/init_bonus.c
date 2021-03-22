/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:26:03 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/28 19:26:05 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	ft_init_all(t_all *all)
{
	ft_init_win(&all->win);
	ft_init_plr(&all->plr);
	ft_init_txtrs(&all->txtrs);
	ft_init_map(&all->m);
	ft_init_key(&all->key);
	ft_init_ray(&all->ray);
	ft_init_spr(&all->spr);
	ft_init_f(&all->f);
	all->w = -1;
	all->h = -1;
	all->tmp = 0;
	all->map = NULL;
	all->screenshot = 0;
}

void	ft_init_spr(t_spr *spr)
{
	spr->x = 0;
	spr->y = 0;
	spr->dist = 0;
	spr->spr_num = 0;
	spr->dist_x = 0;
	spr->dist_y = 0;
	spr->spr_num = 0;
	spr->sprite_x = 0;
	spr->sprite_y = 0;
	spr->inv_det = 0;
	spr->transform_x = 0;
	spr->transform_y = 0;
	spr->screen_x = 0;
	spr->vert_mv = 0;
	spr->height = 0;
	spr->width = 0;
	spr->draw_start_x = 0;
	spr->draw_start_y = 0;
	spr->draw_end_x = 0;
	spr->draw_end_y = 0;
	spr->tex_x = 0;
	spr->tex_y = 0;
}

void	ft_init_map(t_m *m)
{
	m->tmp = NULL;
	m->parsed = 0;
	m->started = 0;
	m->bot = 0;
	m->lft = -1;
	m->max_lft = 1000000;
	m->max_rht = 0;
	m->last_col_end = -1;
	m->last_col_beg = -1;
	m->w = -1;
	m->h = -1;
	m->p_look = 0;
	m->pos_x = 0;
	m->pos_y = 0;
	m->row = -1;
}

void	ft_init_ray2(t_ray *ray)
{
	ray->tex_num = 0;
	ray->wall_x = 0;
	ray->tex_x = 0;
	ray->txtr_h = 0;
	ray->txtr_w = 0;
	ray->txtr_bpp = 0;
	ray->txtr_en = 0;
	ray->txtr_llen = 0;
	ray->step = 0;
	ray->tex_pos = 0;
	ray->tex_y = 0;
	ray->color = 0;
}

void	ft_init_ray(t_ray *ray)
{
	ray->perp_wall_dist = 0;
	ray->side_hit = 0;
	ray->ray_dir_x = 0;
	ray->ray_dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ft_init_ray2(ray);
}
