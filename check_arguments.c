/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:38:50 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/28 13:38:50 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_usage(void)
{
	ft_putstr("Usage: ./fractal [ mandelbrot | julia | burningship ]\n\n");
	ft_putstr("Input is case insensitive. WrItE wHaT eVeR yOu LiKe.\n");
	ft_putstr("For example run fractal burningship:\n");
	ft_putstr("> ./fractal BURNingSHIP\n\n");
	ft_putstr("Also you can use first letter of name to call fractal.\n");
	ft_putstr("For example run fractal Julia:\n> ./fractal J\n");
	exit(EXIT_FAILURE);
}

_Bool	arg_check(const char *arg, const char *param)
{
	if (!arg || !param || (!ft_strcmp(arg, param) && *arg != *param))
		return (FALSE);
	return (TRUE);
}

void	wrong_argument(int i)
{
	ft_putstr("Wrong argument ");
	ft_putstr(ft_itoa(i));
	ft_putstr("\n\n");
	show_usage();
}

void	check_arguments(int argc, char **argv)
{
	int		i;

	if (argc == 1)
		show_usage();
	ft_astr_tolower(argv);
	i = 0;
	while (++i < argc)
		if (arg_check(argv[i], "mandelbrot")
		|| arg_check(argv[i], "julia")
		|| arg_check(argv[i], "burningship")
		|| arg_check(argv[i], "spider")
		|| arg_check(argv[i], "newton"))
			continue;
		else
			wrong_argument(i);
}
