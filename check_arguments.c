/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:38:50 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/29 14:51:00 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_usage(void)
{
	ft_putstr("Usage: ./fractal [ mandelbrot | julia | burningship ");
	ft_putstr("| spider ]\n\n");
	ft_putstr("Input is case insensitive. WrItE wHaT eVeR yOu LiKe.\n");
	ft_putstr("For example run fractal burningship:\n");
	ft_putstr("> ./fractal BURNingSHIP\n\n");
	ft_putstr("Also you can use first letter of name to call fractal.\n");
	ft_putstr("For example run fractal Julia:\n> ./fractal J\n");
	exit(EXIT_FAILURE);
}

_Bool	arg_check(const char *arg, const char *param)
{
	if (ft_strcmp(arg, param) == 0 || (ft_strlen(arg) == 1 && *arg == *param))
		return (TRUE);
	return (FALSE);
}

void	check_arguments(int argc, char **argv)
{
	ft_astr_tolower(argv);
	if (!(argc == 2 && (arg_check(argv[1], "mandelbrot")
	|| arg_check(argv[1], "julia")
	|| arg_check(argv[1], "burningship")
	|| arg_check(argv[1], "spider"))))
		show_usage();
}
