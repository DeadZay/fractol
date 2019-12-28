/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:18:36 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/28 13:34:41 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** ************************************************************************** **
** Define
** ************************************************************************** **
*/

# define TITLE "fractol"

/*
** ************************************************************************** **
** Include
** ************************************************************************** **
*/

# include "libft/libft.h"
# include "ft_complex.h"
# include "ft_mlx.h"
# include <fcntl.h>
# include <pthread.h>
# include <math.h>

/*
** ************************************************************************** **
** Typedef, struct, enum and union
** ************************************************************************** **
*/

typedef enum 		e_fractol_type
{
	FRACTOL_MANDELBROT = 'm',
	FRACTOL_JULIA = 'j',
	FRACTOL_BURNINGSHIP = 'b',
	FRACTOL_SPIDER = 's'
}					t_fractol_type;

typedef t_point 	t_fpoint;

typedef struct		s_tpoint2d
{
	unsigned		x;
	unsigned		y;
}					t_point2d;

typedef struct		s_color_power
{
	int 			r;
	int 			g;
	int 			b;
	int 			a;
}					t_color_power;

typedef struct 		s_fractol
{
	t_view 			*view;
	char 			letter;
	size_t			i[WIDTH * HEIGHT];
	t_color_power	cpower;
	size_t			i_max;
	_Bool			move;
	_Bool			refresh_color;
}					t_fractol;

/*
** ************************************************************************** **
** Function
** ************************************************************************** **
*/

void			check_arguments(int argc, char **argv);
void			show_usage(void);

size_t			mandelbrot(t_complex c, const size_t i_max);
size_t			julia(t_complex z, t_complex c, const size_t i_max);
size_t			burningship(t_complex c, const size_t i_max);
size_t 			spider(t_complex c, const size_t i_max);

void			change_zoom(t_fractol *fractol, int button, int keycode);
void			change_color(t_fractol *fractol, int keycode);
void			change_view(t_fractol *fractol, int keycode);

int				e_mouse_move(int x, int y, void *param);
int				e_mouse_press(int button, int x, int y, void *param);
int 			e_key_press(int keycode, void *param);
int 			e_close(void *param);

t_fpoint		get_fpoint(t_fractol *fractol, t_point2d point);
size_t			escape(t_fractol *fractol, t_fpoint point);
int 			get_color(t_fractol *fractol, size_t i, t_point point);

void			destroy_tfractol(t_fractol *fractol);
void 			event_set(t_fractol *fractol);
void			init_i_array(t_fractol *fractol);
void			init_cpower(t_fractol *fractol);
void 			reset_fractol(t_fractol *fractol);
t_fractol 		*get_tfractol(t_view *view, char fractol_letter);

_Bool 			cycle(t_fractol *fractol);

#endif
