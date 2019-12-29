/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:33:51 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/29 14:30:57 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fpoint				get_fpoint(t_fractol *fractol, t_point2d point)
{
	const t_view_attr	attr = fractol->view->attr;
	t_fpoint			fpoint;

	fpoint = (t_fpoint){
			(((long double)point.x - attr.width2) / attr.zoom) + attr.dx,
			(((long double)point.y - attr.height2) / attr.zoom) + attr.dy};
	return (fpoint);
}

size_t					escape(t_fractol *fractol, t_fpoint point)
{
	const t_point		tmouse = fractol->view->mouse.point_a;
	const size_t		i_max = fractol->i_max;
	const t_complex		cpoint = (t_complex){point.x, point.y};
	const t_complex		mouse_point = (t_complex){tmouse.x, tmouse.y};

	if (fractol->letter == FRACTOL_MANDELBROT)
		return (mandelbrot(cpoint, i_max));
	if (fractol->letter == FRACTOL_JULIA)
		return (julia((t_complex)cpoint, mouse_point, i_max));
	if (fractol->letter == FRACTOL_BURNINGSHIP)
		return (burningship(cpoint, i_max));
	if (fractol->letter == FRACTOL_SPIDER)
		return (spider(cpoint, i_max));
	return (0);
}

int						get_color(t_fractol *fractol, size_t i, t_point point)
{
	const t_color_power	cpower = fractol->cpower;
	int					color;

	color = 0;
	if (point.x < WIDTH && point.y < HEIGHT && i < fractol->i_max)
		color = ((((i * cpower.r) % 255) << 16) + (((i * cpower.g) % 255) <<
		8) + (i * cpower.b) % 255);
	return (color);
}
