/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbolg <dbolg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 23:16:33 by dbolg             #+#    #+#             */
/*   Updated: 2020/10/29 10:57:18 by dbolg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include "./linux/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# include <stdint.h>
# define OK NULL
# define FOV 66
# define MV_SP 0.2
# define ROT_SP 0.07
# define XK_MISCELLANY
# define XK_LATIN1
# include <X11/keysymdef.h>
# define KEY_ESC XK_Escape
# define KEY_W XK_w
# define KEY_A XK_a
# define KEY_S XK_s
# define KEY_D XK_d
# define KEY_M XK_m
# define KEY_L XK_Left
# define KEY_R XK_Right

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_len;
	int			bpp;
	int			en;
	int			full_reso_w;
	int			full_reso_h;
}				t_win;

typedef struct	s_plr
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		move_sp;
	double		rot_sp;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		camera_y;
}				t_plr;

typedef struct	s_ray
{
	int			side_hit;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			step_x;
	int			step_y;
	int			hit;
	double		*perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_num;
	double		wall_x;
	int			tex_x;
	void		*txtr;
	char		*txtr_addr;
	int			txtr_h;
	int			txtr_w;
	int			txtr_bpp;
	int			txtr_en;
	int			txtr_llen;
	double		step;
	double		tex_pos;
	int			tex_y;
	int32_t		color;
}				t_ray;

typedef struct	s_txtrs
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	char		*s;
	int			f;
	int			c;
	int			no_h;
	int			no_w;
	void		*no_ptr;
	char		*no_addr;
	int			no_bpp;
	int			no_llen;
	int			no_en;
	int			so_h;
	int			so_w;
	void		*so_ptr;
	char		*so_addr;
	int			so_bpp;
	int			so_llen;
	int			so_en;
	int			ea_h;
	int			ea_w;
	void		*ea_ptr;
	char		*ea_addr;
	int			ea_bpp;
	int			ea_llen;
	int			ea_en;
	int			we_h;
	int			we_w;
	void		*we_ptr;
	char		*we_addr;
	int			we_bpp;
	int			we_llen;
	int			we_en;
	int			s_height;
	int			s_width;
	void		*s_ptr;
	char		*s_addr;
	int			s_bpp;
	int			s_llen;
	int			s_en;
}				t_txtrs;

typedef struct	s_m
{
	int			parsed;
	int			started;
	int			bot;
	int			lft;
	int			max_lft;
	int			max_rht;
	int			last_col_end;
	int			last_col_beg;
	int			row;
	int			h;
	int			w;
	char		p_look;
	int			pos_x;
	int			pos_y;
	t_list		*tmp;
}				t_m;

typedef struct	s_key
{
	int			w;
	int			s;
	int			d;
	int			a;
	int			r;
	int			l;
}				t_key;

typedef struct	s_spr
{
	double		*x;
	double		*y;
	double		*dist;
	double		dist_x;
	double		dist_y;
	int			spr_num;
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			screen_x;
	int			vert_mv;
	int			height;
	int			width;
	int			draw_start_x;
	int			draw_start_y;
	int			draw_end_x;
	int			draw_end_y;
	int			tex_x;
	int			tex_y;
}				t_spr;

typedef struct	s_all
{
	int			w;
	int			h;
	t_win		win;
	t_plr		plr;
	t_txtrs		txtrs;
	t_m			m;
	t_spr		spr;
	t_key		key;
	t_ray		ray;
	char		**map;
	int			screenshot;
	int			tmp;
}				t_all;

/*
** main.c/4
*/
int				scene(t_all *all);
int				key_release(int keycode, t_all *all);
int				key_press(int keycode, t_all *all);
int				key_sort_n_draw(t_all *all);
/*
** utilc.c
*/
char			*check_arguments(t_all *all, int argc, char **argv);
int				complete(t_all *all);
int				skip_space(char *ln, int *i);
int				create_trgb(int t, int r, int g, int b);
/*
** init.c
*/
void			ft_init_all(t_all *all);
void			ft_init_spr(t_spr *spr);
void			ft_init_map(t_m *m);
void			ft_init_ray(t_ray *ray);
/*
** init1.c
*/
void			ft_init_txtrs(t_txtrs *txtrs);
void			ft_init_key(t_key *key);
void			ft_init_plr(t_plr *plr);
void			ft_init_win(t_win *win);
char			*prs_txtr(t_all *all, char **ln, char side);
/*
** prs1.c
*/
char			*prs_file(t_all *all, int fd);
/*
** prs2.c
*/
char			*val_map(t_all *all);
int				fill_map(t_all *all);
/*
** prs3.c
*/
char			*prs_m(t_all *all, char **ln);
char			*pars_f_and_c(t_all *all, char **ln, char side);
/*
** prs4.c
*/
char			*prs_r(t_all *all, char **ln);
/*
** engine.c
*/
char			*ft_engine(t_all *all);
/*
**engine1.c (screenshot)
*/
void			bubble_sort(double array[], double a_x[], double a_y[], int n);
void			save_screenshot(t_all *all);
/*
** engine2.c (walls)
*/
void			draw_columns(t_all *all);
/*
** engine3.c (leftovers)
*/
void			my_mlx_pixel_put(t_all *all, int x, int y, int color);
void			set_vectors(t_all *all);
void			step_till_wall(t_all *all, int x);
void			draw_background(t_all *all);
void			draw_wall(t_all *all, int x);
/*
** engine4.c (keys)
*/
int				key_sort_n_draw(t_all *all);
/*
** engine5.c (leftovers)
*/
void			turn_lft(t_all *all);
void			turn_rht(t_all *all);
void			calc_wall_column(t_all *all, int x);
int				fr_ee(char **line);
int				exit_int(t_all *all);
/*
** engine6.c (sprite)
*/
void			draw_sprites(t_all *all);
/*
** exit.c
*/
char			*ft_exit_0(t_all *all, char *line);

#endif
