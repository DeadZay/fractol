#include "fractol.h"

void	show_usage(void)
{
	ft_putstr("Usage: ./fractal [ mandelbrot | julia | burningship ]\n");
	ft_putstr("Example:\n> ./fractal burningship\n(");
	ft_putstr("Also you can use first word of name to call fractal\n");
	ft_putstr("Example:\n> ./fractal J\n(It means: Run fractal Julia");
	exit(1);
}

void	check_arguments(int argc, char **argv)
{
	argc == 1 ? show_usage() : 0;
}

int 	main(int argc, char **argv)
{
	check_arguments(argc, argv);
	return (0);
}