#include "fractol.h"
#include <stdio.h>

/*size_t	mandelbrot()
{
	size_t	i;

}

void	mandelbrot_set(void)
{

}*/

/*_Bool	choose_fractal(char *arg)
{
	const char		c = arg ? (char)ft_tolower(*arg) : '\0';

	if (c == '\0')
		return (FALSE);

}*/

int 	main(int argc, char **argv)
{
	argc != 2 ? show_usage() : 0; //TODO Сделать в несколько потоков
	check_arguments(argc, argv);
	return (0);
}