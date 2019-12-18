#ifndef FRACTOL_H
# define FRACTOL_H
# define FRACTAL_COUNT 3
# define STRING(X) #X
# define CONCAT(X,Y) X##Y
# include "libft/libft.h"
# include "ft_mlx.h"
# include <fcntl.h>
# include <pthread.h>

void	check_arguments(int argc, char **argv);

typedef struct		s_fractol
{
	char 			letter;
	void			*mlx;
}					t_fractol;

typedef struct		s_complex
{
	long double		re;
	long double		im;
}					t_complex;

//TODO Добавить 42 header

#endif
