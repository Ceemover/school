/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:24:53 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/28 19:24:57 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub_bonus.h"

void		bubble_sort(double array[], double a_x[], double a_y[], int n)
{
	int			i;
	int			j;
	double		temp;

	i = -1;
	while (++i < n - 1)
	{
		j = -1;
		while (++j < n - i - 1)
		{
			if (array[j] < array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				temp = a_x[j];
				a_x[j] = a_x[j + 1];
				a_x[j + 1] = temp;
				temp = a_y[j];
				a_y[j] = a_y[j + 1];
				a_y[j + 1] = temp;
			}
		}
	}
}

static void	f_bmp_headers_generate(t_all *all, char *bitm_h, char *dib)
{
	int			file_size;

	file_size = 14 + 40 + all->w * all->h * \
			all->win.bpp / 8;
	bitm_h[0] = 'B';
	bitm_h[1] = 'M';
	bitm_h[2] = (char)(file_size);
	bitm_h[3] = (char)(file_size >> 8);
	bitm_h[4] = (char)(file_size >> 16);
	bitm_h[5] = (char)(file_size >> 24);
	bitm_h[10] = (char)(14 + 40);
	dib[0] = (char)(40);
	dib[4] = (char)(all->w);
	dib[5] = (char)(all->w >> 8);
	dib[6] = (char)(all->w >> 16);
	dib[7] = (char)(all->w >> 24);
	dib[8] = (char)(-all->h);
	dib[9] = (char)(-all->h >> 8);
	dib[10] = (char)(-all->h >> 16);
	dib[11] = (char)(-all->h >> 24);
	dib[12] = (char)(1);
	dib[14] = (char)(all->win.bpp);
}

static char	*new_file(void)
{
	int			fd;
	char		*name;
	char		*ending;
	char		*temp;
	static int	index;

	if (!(name = ft_strdup("save.bmp")))
		return ("malloc failed at new_name function");
	while ((fd = open(name, O_RDONLY)) > 0)
	{
		f_ree(&name, &name, &name);
		if (close(fd) < 0)
			return ("failed to close screenshot fd");
		if (!(ending = ft_itoa(++index)) ||
			!(temp = ft_strjoin("save_", ending)) ||
				!(name = ft_strjoin(temp, ".bmp")))
			return ("malloc failed at new_name");
		ending ? f_ree(&ending, &ending, &ending) : 0;
		temp ? f_ree(&temp, &temp, &temp) : 0;
		if (!name)
			return (NULL);
	}
	return (name);
}

static char	*f_bmp_image_write(t_all *all, char *bitm_h, char *dib_head)
{
	int			fd;
	char		*file;
	int			i;
	int			win_width;

	i = 0;
	win_width = all->win.bpp / 8 * all->w;
	if (!(file = new_file()))
		return ("couldn't get new file for screenshot");
	if ((fd = open(file, O_RDWR | O_CREAT, 0664)) < 0)
		return ("couldn't open fd at f_bmp_image_write function");
	write(fd, bitm_h, 14);
	write(fd, dib_head, 40);
	while (i < all->h)
		write(fd, all->win.addr + i++ * all->win.line_len, win_width);
	ft_putstr_fd(file, 1);
	write(1, "\n", 1);
	free(file);
	return (close(fd) < 0) ? "couldn't close screenshot fd" : NULL;
}

void		save_screenshot(t_all *all)
{
	char		bitm_h[14];
	char		dib_header[40];

	ft_bzero(bitm_h, 14);
	ft_bzero(dib_header, 40);
	draw_f_c_txtrs(all);
	draw_columns(all);
	if (all->spr.spr_num)
		draw_sprites(all);
	f_bmp_headers_generate(all, bitm_h, dib_header);
	f_bmp_image_write(all, bitm_h, dib_header);
	ft_exit_0(all, NULL);
}
