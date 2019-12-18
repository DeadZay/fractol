#include "fractol.h"

void	show_usage(void)
{
	ft_putstr("Usage: ./fractal [ mandelbrot | julia | burningship ]\n\n");
	ft_putstr("Input is case insensitive. WrItE wHaT eVeR yOu LiKe.\n");
	ft_putstr("For example run fractal burningship:\n");
	ft_putstr("> ./fractal BURNingSHIP\n\n");
	ft_putstr("Also you can use first letter of name to call fractal.\n");
	ft_putstr("For example run fractal Julia:\n> ./fractal J\n");
	exit(0);
}

char 	**get_true_args(void)
{
	char 	**true_args;

	if (!(true_args =
				  (char **)malloc(sizeof(char *) * ((FRACTAL_COUNT * 2) + 1)))
		|| !(true_args[0] = ft_strdup("mandelbrot"))
		|| !(true_args[1] = ft_strdup("m"))
		|| !(true_args[2] = ft_strdup("julia"))
		|| !(true_args[3] = ft_strdup("j"))
		|| !(true_args[4] = ft_strdup("burningship"))
		|| !(true_args[5] = ft_strdup("b")))
	{
		ft_astr_del(true_args);
		return (NULL);
	}
	true_args[FRACTAL_COUNT * 2] = NULL;
	return (true_args);
}

void	check_arguments(int argc, char **argv)
{
	char 	**true_args;

	if (argc == 1)
		show_usage();
	if ((true_args = get_true_args()))
		ft_astr_tolower(argv);
	else
		exit(1);
	if (!ft_astr_astr(argv, true_args))
	{
		ft_astr_del(true_args);
		show_usage();
	}
	ft_astr_del(true_args);
}