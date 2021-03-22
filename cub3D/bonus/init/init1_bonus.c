/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:34:13 by dbolg             #+#    #+#             */
/*   Updated: 2020/11/02 19:34:14 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void	ft_init_key(t_key *key)
{
	key->w = 0;
	key->s = 0;
	key->d = 0;
	key->a = 0;
	key->r = 0;
	key->l = 0;
	key->shift = 0;
	key->up = 0;
	key->down = 0;
	key->ctrl = 0;
	key->space = 0;
}

void	ft_init_f(t_f *f)
{
	f->is_floor = 0;
}
