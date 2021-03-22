/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:37:52 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/29 10:14:52 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int			scene(t_all *all)
{
	draw_background(all);
	draw_columns(all);
	if (all->spr.spr_num)
		draw_sprites(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->win.img,
		0, 0);
	return (0);
}

int			key_press(int keycode, t_all *all)
{
	if (keycode == KEY_W)
		all->key.w = 1;
	if (keycode == KEY_A)
		all->key.a = 1;
	if (keycode == KEY_S)
		all->key.s = 1;
	if (keycode == KEY_D)
		all->key.d = 1;
	if (keycode == KEY_R)
		all->key.r = 1;
	if (keycode == KEY_L)
		all->key.l = 1;
	if (keycode == KEY_ESC)
		ft_exit_0(all, NULL);
	return (0);
}

int			key_release(int keycode, t_all *all)
{
	if (keycode == KEY_W)
		all->key.w = 0;
	if (keycode == KEY_A)
		all->key.a = 0;
	if (keycode == KEY_S)
		all->key.s = 0;
	if (keycode == KEY_D)
		all->key.d = 0;
	if (keycode == KEY_R)
		all->key.r = 0;
	if (keycode == KEY_L)
		all->key.l = 0;
	return (0);
}

int			main(int argc, char **argv)
{
	t_all	all;
	char	*ret;
	int		fd;

	fd = 0;
	ft_init_all(&all);
	if (argc == 1)
		ft_exit_0(&all, "no .cub file supplied as the 1st argument");
	if (argc > 3)
		ft_exit_0(&all, "too many arguments (maximum 2)");
	if ((ret = check_arguments(&all, argc, argv)))
		ft_exit_0(&all, ret);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_exit_0(&all, "the .cub file failed to open");
	if (!(all.win.mlx = mlx_init()))
		ft_exit_0(&all, "mlx_init failed");
	if ((ret = prs_file(&all, fd)))
		ft_exit_0(&all, ret);
	if ((ret = ft_engine(&all)))
		ft_exit_0(&all, ret);
	return (0);
}
