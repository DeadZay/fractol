/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:38:39 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/29 14:30:57 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t			mandelbrot(t_complex c, const size_t i_max)
{
	size_t		i;
	t_complex	z;

	i = 0;
	z = (t_complex){0, 0};
	while (i < i_max)
	{
		z = ft_cpowl(z, 2.0L);
		z = ft_cadd(z, c);
		if (powl(z.re, 2.0L) + powl(z.im, 2.0L) >= 4.0L)
			break ;
		i++;
	}
	return (i);
}

size_t			julia(t_complex z, t_complex c, const size_t i_max)
{
	size_t		i;

	i = 0;
	while (i < i_max)
	{
		z = ft_cpowl(z, 2.0L);
		z = ft_cadd(z, c);
		if (powl(z.re, 2.0L) + powl(z.im, 2.0L) >= 4.0L)
			break ;
		i++;
	}
	return (i);
}

size_t			burningship(t_complex c, const size_t i_max)
{
	size_t		i;
	t_complex	z;

	i = 0;
	z.re = 0;
	z.im = 0;
	while (i < i_max)
	{
		z = ft_cpowl(z, 2.0L);
		z.im = fabsl(z.im);
		z = ft_cadd(z, c);
		if (powl(z.re, 2.0L) + powl(z.im, 2.0L) >= 4.0L)
			break ;
		i++;
	}
	return (i);
}

size_t			spider(t_complex c, const size_t i_max)
{
	size_t		i;
	t_complex	z;

	i = 0;
	z = (t_complex){c.re * 0.01L, c.im * 0.01L};
	while (i < i_max)
	{
		z = ft_cpowl(z, 2.0L);
		z = ft_cadd(z, c);
		c = (t_complex){c.re / 2L + z.re, c.im / 2L + z.im};
		if (powl(z.re, 2.0L) + powl(z.im, 2.0L) >= 4.0L)
			break ;
		i++;
	}
	return (i);
}
