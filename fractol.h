//TODO Добавить 42 header

#ifndef FRACTOL_H
# define FRACTOL_H
# define FRACTAL_COUNT 3
# define STRING(X) #X
# define CONCAT(X,Y) X##Y
# define TITLE "fractol"
# define TPOINT2D
# include "libft/libft.h"
# include "ft_complex.h"
# include "ft_mlx.h"
# include <fcntl.h>
# include <pthread.h>
# include <math.h>

#define I_MAX 255
#define I_MAX_DELTA 50

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
	t_point 		point[WIDTH * HEIGHT];
	t_color_power	cpower;
	size_t			i_max;
	_Bool			move;
	_Bool			refresh_color;
}					t_fractol;

void			check_arguments(int argc, char **argv);
void			show_usage(void);

/*
** ************************************************************************** **
** Fractals
** ************************************************************************** **
*/

size_t			mandelbrot(t_complex c, const size_t i_max);
size_t			julia(t_complex z, t_complex c, const size_t i_max);
size_t			burningship(t_complex c, const size_t i_max);
size_t 			spider(t_complex c, const size_t i_max);

#endif
