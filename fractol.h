//TODO Добавить 42 header

#ifndef FRACTOL_H
# define FRACTOL_H
# define FRACTAL_COUNT 3
# define STRING(X) #X
# define CONCAT(X,Y) X##Y
# include "libft/libft.h"
# include "ft_mlx.h"
# include <fcntl.h>
# include <pthread.h>
# include <math.h>

#include <stdio.h>

#define WIDTH 640
#define HEIGHT 480
#define I_MAX 25
#define CX(X) ((long double)X - (long double)WIDTH * 0.5L) \
/ (WIDTH > HEIGHT ? HEIGHT / 5 : WIDTH / 5)
#define CY(Y) ((long double)Y - 0.5L * (long double)HEIGHT) \
/ (WIDTH > HEIGHT ? HEIGHT / 5 : WIDTH / 5)

typedef struct		s_complex
{
	long double		re;
	long double		im;
}					t_complex;

void	check_arguments(int argc, char **argv);

#endif
