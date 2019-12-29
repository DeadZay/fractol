/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:17:56 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/29 13:05:03 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

/*
** ************************************************************************** **
** Define
** ************************************************************************** **
*/

# ifndef WIDTH
#  define WIDTH 640
# endif
# ifndef HEIGHT
#  define HEIGHT 480
# endif
# ifndef TITLE
#  define TITLE "TITLE"
# endif
# define KEY_COUNT 0x77
# define BUTTON_COUNT 3

/*
** ************************************************************************** **
** Include
** ************************************************************************** **
*/

# include <math.h>
# include <mlx.h>
# include "ft_mlx_events.h"
# include "ft_complex.h"
# include "libft/libft.h"

/*
** ************************************************************************** **
** Typedef, struct, enum and union
** ************************************************************************** **
*/

typedef struct		s_point
{
	long double		x;
	long double		y;
}					t_point;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data;
}					t_win;

typedef struct		s_mouse
{
	_Bool			button[BUTTON_COUNT];
	t_point			point_a;
	t_point			point_b;
}					t_mouse;

typedef struct		s_keyboard
{
	_Bool			key[KEY_COUNT];
	unsigned		current_pressed;
}					t_keyboard;

typedef struct		s_view_attr
{
	size_t			zoom_count;
	long double		zoom;
	long double		dx;
	long double		dy;
	long double		width2;
	long double		height2;
}					t_view_attr;

typedef struct		s_view
{
	t_win			*twin;
	t_view_attr		attr;
	t_mouse			mouse;
	t_keyboard		keyboard;
}					t_view;

/*
** ************************************************************************** **
** Function
** ************************************************************************** **
*/

void				destroy_twin(t_win *twin, _Bool destroy_mlx);
t_win				*get_twin(int width, int height, char *title);
t_win				*get_twin_mlx(int width, int height, char *title,
		void *mlx);
void				destroy_tview(t_view *view);
void				init_tview_attr(t_view *view);
void				init_tkeyboard(t_view *view);
void				init_tmouse(t_view *view);
t_view				*get_tview(t_win *twin, int width, int height, char *title);

#endif
